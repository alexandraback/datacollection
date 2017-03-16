#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#define LL long long
#define DB double
const int INF = 0x3f3f3f3f;
using namespace std;
int dp[19][19];
int re[19];
int e,r,n;
void solve()
{
    for(int i=0;i<=n;i++)
    for(int j=0;j<=e;j++) dp[i][j] = -INF;
    dp[0][e] = 0;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<=e;k++)
        {
            for(int j=0;j<=k;j++)
            dp[i+1][min(e,k-j+r)] = max(dp[i+1][min(e,k-j+r)],dp[i][k]+j*re[i+1]);
        }
    }
    int ans = -INF;
    for(int i=0;i<=e;i++)
    ans = max(dp[n][i],ans);
    cout<<ans<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w+",stdout);
    #endif
    int cas,T=1;scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d%d",&e,&r,&n);
        for(int i=1;i<=n;i++) scanf("%d",&re[i]);
        printf("Case #%d: ",T++);
        solve();
    }
    return 0;
}
