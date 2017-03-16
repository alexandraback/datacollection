#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 1000000000;
int dp[1 << 10][1 << 10];
int costA[10] , costB[10];
int gao(int i ,int j ,int n)
{
    int own = 0;
    for(int k = 0 ; k < n ; k ++)
    {
        if(( i & (1 << k)  ) && ( j & (1 << k)  ))
        {
            own += 2;
        }
        else if( i & (1 << k)  )
        {
            own += 1;
        }
        else if(j & (1 << k))
        {
            own += 2;
        }
    }
    return own;
}
int main()
{
    freopen("B-small-attempt4.in","r",stdin);
    freopen("ans.small","w",stdout);
    int t , cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i ++)
            scanf("%d %d",&costA[i],&costB[i]);

        int all = 1 << n;
        for(int i = 0 ; i< all ; i ++)
            for(int j = 0 ; j < all ; j ++)
                dp[i][j] = inf;

        dp[0][0] = 0;
        for(int i = 0 ; i < all ; i ++)
        {
            for(int j = 0 ; j < all ; j ++)
            {
                int own = gao(i,j,n);
                for(int pc = 0 ; pc < n ; pc ++)
                {
                    if(i & (1 << pc)) continue;
                    if( own >= costA[pc] )
                        dp[i^(1 << pc)][j] = min(dp[i^(1 << pc)][j] , dp[i][j] + 1);
                }
                for(int pc = 0 ; pc < n ; pc ++)
                {
                    if(j & (1 << pc)) continue;
                    if( own >= costB[pc] )
                        dp[i][j^(1 << pc)] = min(dp[i][j^(1 << pc)] , dp[i][j] + 1);
                }
                for(int pc = 0 ; pc < n ; pc ++)
                {
                    if(i & (1 << pc)) continue;
                    if(j & (1 << pc)) continue;
                    if( own >= costA[pc] && own >= costB[pc])
                    {
                        dp[i^(1 << pc)][j^(1 << pc)] = min(dp[i^(1 << pc)][j^(1 << pc)] , dp[i][j] + 1);
                    }
                }
            }
        }

        int ans = inf;

        for(int i = 0 ; i < all ; i ++)
        {
            ans = min(ans,dp[i][all - 1]);
        }
        if(ans == inf)
            printf("Case #%d: Too Bad\n",cas++);
        else
            printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
