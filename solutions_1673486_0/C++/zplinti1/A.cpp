#include <stdio.h>
#include <string.h>

const int maxn=100010;

double a[maxn],dp[maxn],bad[maxn],sum[maxn];

int main()
{
    int cas;
    int A,B;

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++)
    {
        scanf("%d %d",&A,&B);
        for(int i=1;i<=A;i++) scanf("%lf",&a[i]);
        dp[0]=1.0;
        for(int i=1;i<=A;i++) dp[i]=dp[i-1]*a[i];
        for(int i=0;i<A;i++) bad[i]=dp[i]*(1-a[i+1]);
        sum[0]=0;
        for(int i=1;i<=A;i++) sum[i]=sum[i-1]+bad[i-1];
       // for(int i=1;i<=A;i++) printf("%f ",sum[i]);puts("");
        double ans=B+1;
        for(int i=0;i<=A;i++)
        {
            double now=(B-A+2*(A-i))*1.0+(B+1)*sum[i];
            //printf("%d %f\n",i,now);
            if (now<ans) ans=now;
        }
        printf("Case #%d: %.10f\n",ii,ans+1);
    }
    return 0;
}
