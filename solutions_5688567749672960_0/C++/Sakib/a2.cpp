#include <bits/stdc++.h>
#define inf 2000000000
#define ll long long
#define Max 2000000

using namespace std;

ll dp[Max+5];


ll rev(ll x){

    ll r=0;

    while(x){

        r=r*10+x%10;
        x/=10;
    }

    return r;

}


ll f(ll x)
{
    if(dp[x]!=-1) return dp[x];

    ll k=rev(x);

    if(x%10 && k<x) return dp[x]=min(f(x-1)+1 , f(k)+1);

    //cout<<"DP "<<x<<" "<<f(x-1)+1<<endl;

    return dp[x] = f(x-1)+1;
}


int main()
{
    ll i,j,k,T,cas;

    freopen("A-small-attempt1.in","r",stdin);
    freopen("ASmall2.txt","w",stdout);

    memset(dp,-1,sizeof(dp));

    dp[0]=0;

    scanf("%lld",&T);

    for(cas=1;cas<=T;cas++)
    {
        scanf("%lld",&k);
        //cout<<"here"<<endl;
        printf("Case #%lld: %lld\n",cas,f(k));
    }

    return 0;
}
