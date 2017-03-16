#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[1010];
void cal()
{
    int div;
    for(int i=1;i<4;i++)
        dp[i]=i;
    for(int i=4;i<=1000;i++)
    {
        if(i%2==0)
            dp[i]=dp[i/2]+1;
        else
            dp[i]=max(dp[i/2+1],dp[i/2])+1;
    }
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("b.out","w", stdout);
    int t;
    scanf("%d",&t);
    cal();
    for(int p=1;p<=t;p++)
    {
        ll d,x,ans=-1;
        scanf("%lld",&d);
        for(ll i=0;i<d;i++){
            scanf("%lld",&x);
            ans=max(ans,dp[x]);
        }
        printf("Case #%d: %lld\n",p,ans);
    }
    return 0;
}

