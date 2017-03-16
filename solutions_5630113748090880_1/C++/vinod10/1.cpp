#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define pb push_back
using namespace std;

string ans,s;
ll a[2501];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out4.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	for(ll x=1;x<=t;++x)
	{
		memset(a,0,sizeof(a));
		ll n;
		scanf("%lld",&n);
		for(ll i=0;i<2*n-1;++i)
		{
			for(ll j=0;j<n;++j)
			{
				ll tt;
				cin>>tt;
				a[tt]++;
			}
		}
		vector<ll> v;
		for(ll i=0;i<2501;++i)
		{
			if(a[i]%2==1)
			v.pb(i);
		}
		sort(v.begin(),v.end());
		printf("Case #%lld: ",x);
		for(ll i=0;i<v.size();++i)
		cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}
