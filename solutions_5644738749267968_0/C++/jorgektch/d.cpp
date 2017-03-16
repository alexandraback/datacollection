#include<stdio.h>
#include<stdlib.h>
 
int compare(const void *x, const void *y)
{
  double xx = *(double*)x, yy = *(double*)y;
  if (xx > yy) return -1;
  if (xx < yy) return  1;
  return 0;
}
 
int main()
{
    int T, N, k=1, i, j, m;
    double naomi[1000]={0}, ken[1000]={0};
    scanf("%d", &T);
    while(T--)
    {
        int war=0, deceitful_war=0;
        scanf("%d", &N);
        for(i=0; i<N; i++)
            scanf("%lf", &naomi[i]);
        for(i=0; i<N; i++)
            scanf("%lf", &ken[i]);
 
        qsort(naomi, N, sizeof(double), compare);
        qsort(ken, N, sizeof(double), compare);
 
        double temp[N];
        for(i=0; i<N; i++)
            temp[i] = ken[i];
 
        //Calculation of Deceitful war
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                if(naomi[i] > ken[j])
                {
                    ken[j] = 10;
                    deceitful_war++;
                    break;
                }
            }
        }
 
        //Calculation of war
        for(i=0; i<N; i++)
        {
            for(j=N-1; j>=0; j--)
            {
                if(temp[j]>=naomi[i])
                {
                    temp[j] = -1;
                    break;
                }
            }
            if(j== -1)
                war++;
        }
 
        printf("Case #%d: %d %d\n", k, deceitful_war, war);
        k++;
    }
    return 0;
}
