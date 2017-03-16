#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-12
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long t,dp[1000006],n;

int rev(int x)
{
    int ans=0;
    while(x)
    {
        ans*=10;
        ans+=x%10;
        x/=10;
    }
    return ans;
}

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    reset(dp,127);
    dp[1]=1;
    For(i,1,1000001)
    {
        dp[i+1]=min(dp[i]+1,dp[i+1]);
        dp[rev(i)]=min(dp[rev(i)],dp[i]+1);
    }
    //cout<<rev(12);
    For(cas,1,1+t)
    {
        cout<<"Case #"<<cas<<": ";
        cin>>n;
        cout<<dp[n]<<endl;
    }
}
