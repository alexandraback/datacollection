#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1234567890000000
int dp[1000001];
ll rev( int x )
{
    if( x%10 == 0 ) return x;
    ll ret=0;
    while( x > 0 ) {
        ret = ret*10 + x%10;
        x/=10;
    }
    return ret;
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;  cin>>t;
    dp[0]=0;
    for( int i=1; i<=1000000; ++i ) {
        dp[i]=dp[i-1]+1;
        if( rev(i) < i ) dp[i] = min(dp[i], dp[rev(i)]+1);
    }
    for( int tt=1; tt<=t; ++tt ) {
        int n,ans;  cin>>n;
        ans = dp[n];
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
