#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#define N 110
using namespace std;
const int Inf = 0x7fffffff;
long long v[N];
long long dp[N][N];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,T=0;
    scanf("%d",&t);
    while(t--)
    {
        int E,R,n;
        scanf("%d%d%d",&E,&R,&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&v[i]);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=E;j++)
                dp[i][j]=-Inf;
        dp[0][E]=0;
        int s=min(R,E);
        for(int i=1;i<=n;i++)
        {
            for(int j=s;j<=E;j++)
            {
                for(int k=0;k<=j;k++)
                {
                    int now=min(E,j-k+R);
                    dp[i][now]=max(dp[i][now],dp[i-1][j]+k*v[i]);
                }
            }
        }
        long long ans=0;
        for(int i=s;i<=E;i++)
            ans=max(ans,dp[n][i]);
        printf("Case #%d: %lld\n",++T,ans);
    }
    return 0;
}
