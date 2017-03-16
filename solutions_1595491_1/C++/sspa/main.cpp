#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n,s,p,dp[101][101],t[101];

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int ca,m=0;
    for(scanf("%d",&ca);ca--;)
    {
        scanf("%d%d%d",&n,&s,&p);
        for(int i=1;i<=n;i++) scanf("%d",&t[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(t[i]==0)
                {dp[i][j]=dp[i-1][j]+(t[i]/3>=p?1:0);}
                else if(t[i]%3==0)
                {
                    if(j) dp[i][j]=max(dp[i-1][j-1]+(t[i]/3+1>=p?1:0),dp[i-1][j]+(t[i]/3>=p?1:0));
                    else dp[i][j]=dp[i-1][j]+(t[i]/3>=p?1:0);
                }
                else if(t[i]%3==1)
                {
                    if(j) dp[i][j]=max(dp[i-1][j-1]+(t[i]/3+1>=p?1:0),dp[i-1][j]+(t[i]/3+1>=p?1:0));
                    else dp[i][j]=dp[i-1][j]+(t[i]/3+1>=p?1:0);
                }
                else if(t[i]%3==2)
                {
                    if(j) dp[i][j]=max(dp[i-1][j-1]+(t[i]/3+2>=p?1:0),dp[i-1][j]+(t[i]/3+1>=p?1:0));
                    else dp[i][j]=dp[i-1][j]+(t[i]/3+1>=p?1:0);
                }
//                printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
            }
        }
        printf("Case #%d: %d\n",++m,dp[n][s]);
    }
    return 0;
}
