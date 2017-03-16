#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long  ll;
struct node
{
    ll  p1,p2;
} a[150],b[150];
ll  dp[150][150];
ll  sum1[150][150],sum2[150][150];

ll  max(ll  a,ll  b)
{
    return a>b?a:b;
}
ll  min(ll  a,ll  b)
{
    return a<b?a:b;
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int t,n,m,x,y;

    int Cas,cas;
    scanf("%d",&Cas);
    for (int cas=0; cas<Cas; cas++)
    {
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++)
        {
            scanf("%lld%lld",&a[i].p1,&a[i].p2);
            sum1[a[i].p2][i+1]=a[i].p1;
        }
        for (int i=0; i<n; i++)
            for (int k=0; k<=100; k++)
                sum1[k][i+1]+=sum1[k][i];
        for (int i=0; i<m; i++)
        {
            scanf("%lld%lld",&b[i].p1,&b[i].p2);
            sum2[b[i].p2][i+1]=b[i].p1;
        }
        for (int i=0; i<m; i++)
            for (int k=0; k<=100; k++)
                sum2[k][i+1]+=sum2[k][i];


        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                if (a[i-1].p2!=b[j-1].p2)
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                else
                {
                    for (x=0; x<i; x++)
                        for (y=0; y<j; y++)
                            dp[i][j]=max(dp[i][j],dp[x][y]+min(sum1[a[i-1].p2][i]-sum1[a[i-1].p2][x],sum2[b[j-1].p2][j]-sum2[b[j-1].p2][y]));
                }
            }

        ll  ans=0;
        for (int i=0; i<=n; i++)
            for (int j=0; j<=m; j++)
                ans=max(ans,dp[i][j]);
        printf("Case #%d: %lld\n",cas+1,ans);
    }
    return 0;
}
