#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

int dp[100][100];
int n,E,R,v[100];

int main()
{
    freopen("D:\\bdata.in","r",stdin);
    freopen("D:\\bdata.out","w",stdout);
    int cas, t = 0;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d %d %d",&E,&R,&n);
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
            for(int j=0;j<=E;j++)
                for(int k=0;k<=j;k++)
                {
                    int nx=j-k+R;
                    if(nx>E)nx=E;
                    dp[i][nx]=max(dp[i][nx],dp[i-1][j]+k*v[i]);
                    ans=max(ans,dp[i][nx]);
                }
        }
        printf("Case #%d: %d\n",++t,ans);
    }
    return 0;
}