#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<utility>
#include<cmath>
#include<sstream>
#define ull unsigned long long int
#define ll long long int
using namespace std;
vector<ll> v(41);
ll gcd (ll a, ll b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}
bool isin(ll x)
{
    for(int i=0;i<=40;++i)
    {
        if(v[i]==x)
            return 1;
    }
    return 0;
}
main()
{
    //v[0]=0;
    for(int i=0;i<=40;++i)
    {
        v[i]=pow(2,i);
    }
    int t;
    cin>>t;
    for(int z=1;z<=t;++z)
    {
        ll p,q;
        //scanf("%ll/%ll",p,q);
        //scanf("%lld[^,],%lld[\n]",p,q);
        scanf("%lld/%lld",&p,&q);
        ll g=gcd(p,q);
        p=p/g;
        q=q/g;
        if(p>q || !isin(q))
        {
            cout<<"Case #"<<z<<": impossible"<<endl;
            continue;
        }
        int count=0;
        while(p<q)
        {
            p*=2;
            ++count;
        }
        cout<<"Case #"<<z<<": "<<count<<endl;
    }
}
