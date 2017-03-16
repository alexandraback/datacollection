#include<stdio.h>
#define MAX(a,b) a>b? a:b

int main()
{
    int T,tt,N,i,new_N;
    double sum=0.0,sum_m=0.0;
    double score[200],p[200],ans[200],inv,max;


    scanf("%d",&T);
    for(tt=1;tt<=T;tt++)
    {

        scanf("%d",&N);

        new_N=N;

        sum=0.0;max=0;
        for(i=0;i<N;i++){
            scanf("%lf",&score[i]);
            max=MAX(max,score[i]);
            sum+=score[i];
        }

        inv=1/(double(N));

        for(i=0;i<N;i++)
        {
            ans[i]=(((inv*2.0*sum)-score[i])*100.00)/sum;
        }


        printf("Case #%d: ",tt);

        /*
        printf("\n*****************\n");
        printf("sum=%f",sum);
        for(i=0;i<N;i++)
        {
            printf("score[%d]=%f ",i+1,score[i]);
        }
        printf("\n*****************\n");
        */

        sum_m=0.0;
        for(i=0;i<N;i++)
        {
            if(ans[i]<0)
            {
                new_N--;
                sum_m+=score[i];
            }
        }

        if(new_N!=N)
        {
            for(i=0;i<N;i++)
            {
                if(ans[i]>=0)
                {
                    ans[i]=(((sum+sum-sum_m)/new_N)-score[i])*100/sum;
                }
                else
                    ans[i]=0.0;
            }
        }

        for(i=0;i<N;i++)
        {
            printf("%f ",ans[i]);
        }

        printf("\n");
    }
    return 0;
}
