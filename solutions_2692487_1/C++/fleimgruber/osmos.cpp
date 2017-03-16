#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

#define MAX_N 105
#define MAX_A 1000005
#define mp make_pair

ll v[MAX_N];
map<pair<ll,int>, ll> *m;
int n;

ll f(ll a, int i)
{	
	if (i>=n) return 0;
	if ((*m)[mp(a,i)]==0)
	{
		if (v[i]<a)
			return ((*m)[mp(a,i)]=f(a+v[i],i+1));
		ll x=f(a,i+1);
		if (a!=1)
			x=min(x,f(a+a-1,i));
		return ((*m)[mp(a,i)]=x+1);
	}
	return (*m)[mp(a,i)];
}

int main()
{
	int t;
	ll a;
	scanf("%d", &t);
	for (int i=0; i<t; i++)
	{
		scanf("%lld %d", &a, &n);
		for (int j=0; j<n; j++)
			scanf("%lld", v+j);

		sort(v,v+n);
		
		m = new map<pair<ll,int>, ll>();

		printf("Case #%d: %lld\n", i+1, f(a,0));

	}
	return 0;
}
