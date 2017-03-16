#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
struct DP
{
    LL ra,rb,ans;
}dp[105][105];
LL sa[105],ta[105];
LL sb[105],tb[105];
LL gao(LL ssa[],LL tta[],LL ssb[],LL ttb[],LL n,LL m)
{
    memset(dp,0,sizeof(dp));
    for(int j=0;j<=m;j++)
    {
        dp[0][j].ra=0;
        dp[0][j].rb=ssb[j];
        dp[0][j].ans=0;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        long long ra=ssa[i],rb=ssb[j],add=0;
        long long d=0,k1=j;
        for(int k=j-1;k>=0;k--)
            if(ttb[k]==tta[i])
            {
                k1=k;
                d=min(dp[i-1][k].rb,ra);
                ra-=d;
                add+=d;
                break;
            }
        if(ttb[j]==tta[i])
        {
            long long d=min(ra,rb);
            ra-=d;
            rb-=d;
            add+=d;
        }
        dp[i][j].ra=ra;
        dp[i][j].rb=rb;
        dp[i][j].ans=dp[i-1][k1].ans+add;
    }
    long long re=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        re=max(re,dp[i][j].ans);
    return re;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%I64d%I64d",&sa[i],&ta[i]);
        for(int i=1;i<=m;i++)
            scanf("%I64d%I64d",&sb[i],&tb[i]);
        LL ans1=gao(sa,ta,sb,tb,n,m);
        LL ans2=gao(sb,tb,sa,ta,m,n);
        printf("Case #%d: %I64d\n",++cas,max(ans1,ans2));
    }
    return 0;
}
