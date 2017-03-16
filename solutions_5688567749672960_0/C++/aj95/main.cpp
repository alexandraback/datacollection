#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int dp[1000010];


int rev(int n)
{
    int r=0,N=n;
    if(n%10 == 0) return (n-1);
    while(N>0)
    {
        r = (r*10) + (N%10);
        N/=10;
    }
    if(r >= n) return (n-1);
    return r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Users/Ayur/Downloads/A-small-attempt0.in","r",stdin);
    freopen("/Users/Ayur/Downloads/A-small-output.txt","w",stdout);
    int tt,t,i,n;
    for(i=0;i<=10;i++) dp[i]=i;
    for(i=11;i<=1000000;i++)
    {
        dp[i] = min(dp[i-1]+1,dp[rev(i)]+1);
    }
    cin>>tt;
    for(t=1;t<=tt;t++)
    {
        cin>>n;
        cout<<"Case #"<<t<<": "<<dp[n]<<'\n';
        
    }
    return 0;
}