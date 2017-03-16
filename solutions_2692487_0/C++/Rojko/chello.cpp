#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef unsigned long long ll;

ll count(vector<ll> &v, ll x, ll zac) {
	if (zac == v.size()) return 0;
	ll mini = v.size()-zac;
	if (v[zac] < x) mini = count(v, x+v[zac], zac+1);
	else if (x != 1) mini = min(count(v, 2*x-1,zac) + 1, v.size()-zac);
	return mini;
}

int main(){
	ll T;
	scanf("%lld", &T);
	for (ll t = 0; t<T; ++t) {
		ll A,n;
		vector<ll> v;
		scanf("%lld %lld", &A, &n);
		for (ll i = 0; i<n; ++i) {
			ll a;
			scanf("%lld", &a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		printf("Case #%lld: %lld\n", t+1, count(v,A,0));
	}
	return 0;
}
