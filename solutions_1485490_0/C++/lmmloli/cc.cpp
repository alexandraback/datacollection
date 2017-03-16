#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct node
{
    long long val;
    int num;
};

node a[105],b[105];
long long dp[105][105];
long long suma[105][105],sumb[105][105];
int n,m;

void init()
{
    int i,j;
    for (i=1;i<=100;i++)
    {
        suma[i][0]=0;
        for (j=1;j<=n;j++)
        {
            if (a[j].num==i) suma[i][j]=suma[i][j-1]+a[j].val;
            else suma[i][j]=suma[i][j-1];
        }
    }

    for (i=1;i<=100;i++)
    {
        sumb[i][0]=0;
        for (j=1;j<=m;j++)
        {
            if (b[j].num==i) sumb[i][j]=sumb[i][j-1]+b[j].val;
            else sumb[i][j]=sumb[i][j-1];
        }
    }
}
int main()
{
    int i,j,k1,k2,t,ca=0;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (i=1;i<=n;i++)
        scanf("%lld%d",&a[i].val,&a[i].num);
        for (i=1;i<=m;i++)
        scanf("%lld%d",&b[i].val,&b[i].num);
        init();
        memset(dp,0,sizeof(dp));
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

                   if (a[i].num==b[j].num)
                   {

                    for (k1=0;k1<i;k1++)
                    for (k2=0;k2<j;k2++)
                    {
                         long long sum1,sum2;
                         int p;
                         p =  a[i].num;
                         sum1 = suma[p][i]-suma[p][k1];
                         sum2 = sumb[p][j]-sumb[p][k2];
                         long long px = min(sum1,sum2)+dp[k1][k2];
                         dp[i][j]=max(dp[i][j],px);
                    }

                }
            }
        }
        /*
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            printf("%d ",dp[i][j]);
            printf("\n");
        }
        */
       printf("Case #%d: %lld\n",++ca,dp[n][m]);
    }
    return 0;
}
