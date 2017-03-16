#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
int dp[15][6];
int a[15];
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,time=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        printf("Case #%d: ",++time);
        int e,r,n,i,j,k,ans=0;
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d",&e,&r,&n);
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<=e;i++)
        {
            dp[1][i]=(e-i)*a[1];
            ans=max(ans,dp[1][i]);
        }
        for(i=2;i<=n;i++)
        {
            for(j=0;j<=e;j++)
            {
                int limit=min(e,j+r);
                for(k=0;k<=limit;k++)
                {
                    dp[i][k]=max(dp[i][k],dp[i-1][j]+(limit-k)*a[i]);
                    ans=max(dp[i][k],ans);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
