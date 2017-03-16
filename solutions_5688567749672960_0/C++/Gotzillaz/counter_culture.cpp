#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
#define ll long long

using namespace std;

int dp[1000100] = {0};
int revint(int a)
{
    int ans = 0;
    while(a>0)
    {
        ans *=10;
        ans += a%10;
        a/=10;
    }
    return ans;
}
int main()
{
    int t,tt;
    scanf("%d",&tt);
    t = 1;
    dp[1] = 1;
    for(int i=2;i<=1e6;i++)
    {
        dp[i] = INT_MAX;
    }
    for(int i=2;i<=1e6;i++)
    {
        int rev = revint(i);
        if(i%10 == 0) rev = i-1;
        dp[i] = min(dp[i-1],dp[rev])+1;
    }
    while(t<=tt)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case #%d: %d\n",t,dp[n]);
        t++;
    }
    return 0;
}
