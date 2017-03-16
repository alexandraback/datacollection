#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long

int dp[1000010];

int rev[1000010];

int rever(int x)
{
    int ret=0;
    while(x)
    {
        ret=ret*10+x%10;
        x/=10;
    }
    return ret;
}

int main()
{
    dp[1]=1;
    for(int i=2;i<=1000000;i++)
        rev[i]=rever(i);
    for(int i=2;i<=1000000;i++)
    {
        if(rev[i]<i && rev[rev[i]]==i)
            dp[i]=min(dp[i-1],dp[rev[i]])+1;
        else
            dp[i]=dp[i-1]+1;
    }
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",tt,dp[n]);
    }
    return 0;
}
