#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
int dp[20][20][20];
int E,R,n;
int v[20];

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,ta=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&E,&R,&n);
        int i,j,j0,k,k0;
        for(i=1; i<=n; i++) scanf("%d",v+i);
        memset(dp,0x8f,sizeof(dp));
        int ans = dp[1][1][1];
        for(i=0; i<=E; i++)
        {
            dp[1][E][i] = v[1] * i;
            if(n == 1) ans = max(ans,dp[1][E][i]);
        }

        for(i=2; i<=n; i++)
        {
            for(j=R; j<=E; j++)
              for(k=0; k<=j; k++)
              {
                  for(j0=j-R; j0<=E; j0++)
                  {
                      k0 = j0 + R - j;
                      dp[i][j][k] = max(dp[i][j][k],dp[i-1][j0][k0]+k*v[i]);
                      if(i == n)
                        ans = max(ans,dp[i][j][k]);
                  }
              }
            for(j=max(R,E+1); j<=E+R; j++)
               for(k=0; k<=E; k++)
                {
                    for(j0=j-R; j0<=E; j0++)
                    {
                        k0 = j0 + R - j;
                        dp[i][E][k] = max(dp[i][E][k],dp[i-1][j0][k0]+k*v[i]);
                        if(i == n)
                           ans = max(ans,dp[i][E][k]);
                    }
                }
        }
        printf("Case #%d: %d\n",ta++,ans);
    }
    return 0;
}
