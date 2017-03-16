#include<stdio.h>
#include<string.h>

int main()
{

    int cas;
    double pob[100005];
    double list[100005];
    int A,B;
    double now,min;
    scanf("%d",&cas);
    for(int i=1;i<=cas;++i)
    {
        scanf("%d %d",&A,&B);

        for(int j=0;j<A;j++)
            scanf("%lf",&pob[j]);
        for(int j=0;j<=A;j++)
        {
            list[j]=1;
            for(int k=0;k<A-j;k++)
            {
                list[j]*=pob[k];
            }
            if(j>0)
                list[j]*=(1-pob[A-j]);
            //printf("%lf ",list[j]);
        }
        min=B+2;
        for(int j=0;j<=A;j++)
        {
            now=0;
            for(int k=0;k<=A;k++)
            {
                int key=B-A+1+j*2;
                if(A-k<A-j)
                    key+=(B+1);
                //if(k>=A-j)
                    now+=(list[k]*key);
                if(now>min)
                    break;
            }
            //printf("   %lf",now);
            if(now<min)
                min=now;
        }
        printf("Case #%d: %.6lf",i,min);
        if(i<cas)
            printf("\n");

    }
    return 0;
}
