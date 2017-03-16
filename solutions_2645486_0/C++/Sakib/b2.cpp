#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#define inf 1000000000
#define ll long long

using namespace std;

ll e,r,n;

ll v[10005];

ll dp[15][10];

ll f(ll x,ll p)
{
    ll i,j,k,ret=0;

    if(x==-1) return 0;

    if(dp[x][p]!=-1) return dp[x][p];

    for(i=0;i+p<=e;i++)
    {
        j=max(i+p-r,0LL);

        ret=max(ret,v[x]*i+f(x-1,j));

    }

    return dp[x][p]=ret;
}

int main()
{
    ll i,j,k,t,T,ret,a,b;

    freopen("B-small-attempt1.in","r",stdin);


    freopen("b-small.txt","w",stdout);
    //freopen("a-large.txt","w",stdout);

    cin>>T;



    for(t=1;t<=T;t++)
    {
        ret=0;
        cin>>e>>r>>n;

       // cout<<e<<" "<<r<<" "<<n<<endl;

       memset(dp,-1,sizeof(dp));

        for(i=0;i<n;i++)
        {
           cin>>v[i];
        }

        cout<<"Case #"<<t<<": "<<f(n-1,0)<<endl;


    }

    return 0;
}

