#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

using namespace std;

#define FILE
typedef long long lint;
vector<lint> dp;
lint INF=1LL<<60LL;
inline lint rev(lint x)
{
    lint rez=0;
    while(x)
    {
        rez=rez*10+x%10;x/=10;
    }
    return rez;
}

int main()
{
#ifdef FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int tt;
    scanf("%d",&tt);
    dp.resize(1000005,INF);
    dp[1]=1;
    for(int i=1;i<=1000000;i++)
    {
        dp[i+1]=min(dp[i]+1,dp[i+1]);
        dp[rev(i)]=min(dp[rev(i)],dp[i]+1);
    }
    lint x;
    for(int CASE=1;CASE<=tt;CASE++)
        printf("Case #%d: %lld\n",CASE,dp[scanf("%lld",&x),x]);
    return 0;
}
