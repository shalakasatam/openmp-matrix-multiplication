#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
int s=240,i,j,k,taskid,thrdnum;
int a[s][s],b[s][s],c[s][s];
    
#pragma omp parallel shared(a,b,c)
   {
       taskid = omp_get_thread_num();
    if (taskid== 0)
    {
      thrdnum = omp_get_num_threads();
    }

#pragma omp for  schedule(static)
 for(i=0;i<s;i++)
   {
       for(j=0;j<s;j++)
        {
              a[i][j]=rand()%5;
               b[i][j]=rand()%5;
         }
    }

#pragma omp for  schedule(static)
   for (i=0; i<s; i++)
    {
         for (j=0; j<s; j++)
       {
           for (int k=0; k<s; k++)
              {
                 c[i][j]=c[i][j]+a[i][k]*b[k][j];
              }
       }
   }
}

#pragma omp for  schedule(static)
for(i=0; i<s;i++)
    {
      printf("\n");
      for(j=0;j<s;j++)
         printf("%d",c[i][j]);
    }
return 0;
}
