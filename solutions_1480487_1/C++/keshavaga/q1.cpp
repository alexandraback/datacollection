#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int N;
        float score[200];
        float fraction[200];
        int maxx=0;
        float sum=0;
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            scanf("%f",&score[j]);
            if(score[j]>score[maxx])
                maxx=j;
            sum+=score[j];
        }
        float fsum=0;
        int k=0;
        float sd=0;
        for(int j=0;j<N;j++)
        {
            fraction[j]=((score[maxx]-score[j])/sum)*100;
            fsum+=fraction[j];
        }
        printf("Case #%d: ",i+1);
        for(int j=0;j<N;j++)
        {
            fraction[j]+=(100.0-fsum)/N;
            if(fraction[j]<0.0)
            {
                k++;
                sd+=fraction[j];
                fraction[j]=0.0;
            }


        }
        for(int j=0;j<N;j++)
        {
            if(fraction[j]>0)
                fraction[j]+=(sd/(float)(N-k));
            printf("%f ",fraction[j]);
        }

        printf("\n");
    }
    return 0;
}
