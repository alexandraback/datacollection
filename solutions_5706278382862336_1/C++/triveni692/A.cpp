/*
user  : triveni
date  : 11/05/2014
time  : 14:32:57
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second

typedef long long ll;
ll MOD = 1000000007;

ll gcd(ll a, ll b)
{
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}
void solve()
{
	ll p,q;
	scanf("%lld/%lld",&p,&q);
	if(p>q) {
		puts("impossible");
		return ;
	}
	ll g = gcd(p,q);
	p/=g, q/=g;
	
	double y = log2(q);
	if(ceil(y) != floor(y)){
		puts("impossible");
		return ;
	}

	if(p==1){
		int x = log2(q);
		cout << x << endl;
		return ;
	}
	ll x = log2(p);
	
	
	ll pp = 1LL<<x;

	assert(q%pp==0);

	ll xx = q/pp;
	//cout << q << " " << pp << endl;
	assert((xx&(xx-1)) == 0);
	ll c = log2(xx);
	cout << c << endl;
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;++i)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}