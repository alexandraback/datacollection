#include <bits/stdc++.h>

using namespace std;
const bool DEBUG=true;
int dp[10001000];
int rev(int x)
{
    int ret=0;
    while(x>0)
    {
        ret*=10;
        ret+=x%10;
        x/=10;
    }
    return ret;
}
int main()
{
    if(DEBUG)
    {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }



    memset(dp,9999999,sizeof dp);
    dp[0]=0;
    dp[1]=1;
    for(int i=1;i<=1000100;i++)
    {
        dp[i]=min(dp[i],dp[i-1]+1);
        if(i<rev(i))
        {
            dp[rev(i)]=min(dp[rev(i)],dp[i]+1);
        }
    }
       int t;
       int cur=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",cur++,dp[n]);
    }
    return 0;
}
