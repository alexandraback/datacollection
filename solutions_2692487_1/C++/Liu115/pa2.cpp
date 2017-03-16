#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,t,mote[105];
long long aa,dp[105][105];
int dfs(int now, int tot, long long a)
{
    if(now==n)
    {
        //dp[now][tot]=a;
        return tot;
    }
    if(a<dp[now][tot])return 999;
    else dp[now][tot]=a;
    if(a>mote[now])
    {
        return dfs(now+1,tot,a+mote[now]);
    }
    if(2*a-1>a)return min(dfs(now,tot+1,2*a-1),dfs(now+1,tot+1,a));
    else return dfs(now+1,tot+1,a);
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&t);
    for(int amm=1;amm<=t;amm++)
    {
        scanf("%lld%d",&aa,&n);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&mote[i]);
        }
        sort(mote,mote+n);
        int now=0,op=0;
        printf("Case #%d: %d\n",amm,dfs(0,0,aa));
    }
    return 0;
}

