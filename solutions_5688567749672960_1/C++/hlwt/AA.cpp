#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dp[1000010];

int re(int x) {
    int l=0,num[10];
    while(x) {
        num[++l]=x%10;
        x/=10;
    }
    int res=0;
    for(int i=1;i<=l;i++)
        res=res*10+num[i];
    return res;
}

int solve(int x)
{
    if(dp[x]>=0)
        return dp[x];
    if(x%10&&re(x)<x)
        dp[x]=min(solve(x-1),solve(re(x)))+1;
    else
        dp[x]=solve(x-1)+1;
    return dp[x];
}

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=n;i++)
            solve(i);
        printf("Case #%d: %d\n",++cas,dp[n]);
    }
    return 0;
}
