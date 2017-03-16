#include<stdio.h>
double p;
int main()
{
    int T,t,A,B,i;
    double pp,ans;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d",&A,&B);
        ans=B+2;    //option 3
        for(i=1,pp=1.;i<=A;i++)
        {
            scanf("%lf",&p);
            pp*=p;
            ans<?=(A+B-i*2+1)*pp+(A+B*2-i*2+2)*(1-pp);
        }
        ans<?=(B*2-A+2)-pp*(B+1);
        printf("Case #%d: %.6f\n",t,ans);
    }
}
