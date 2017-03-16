#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
#define pb push_back

bool check(ll x) {
	vector<char> v;
	while (x) {
		v.pb(x%10);
		x /= 10;
	}
	for (int i=0; i<v.size(); i++) if (v[i] != v[v.size() - 1 - i])
		return false;
	return true;
}


int main () {
	int T;
	scanf("%d", &T);
	vector<ll> key;
	key.pb(0);
	vector<pair<ll, ll> > q;

	while (T--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		q.pb(make_pair(a, b));
		key.pb(a-1); key.pb(a); key.pb(b);
	}
	sort(key.begin(), key.end());
	key.resize(unique(key.begin(), key.end()) - key.begin());
	vector<ll> ans(key.size()); ans[0] = 0;

	ll i = 1;
	for (int j=1; j<key.size(); j++) {
		ans[j] += ans[j-1];
		while (i*i <= key[j]) {
			if (check(i) && check(i*i)) ans[j]++;
			i++;
		}
	}

	for (int j=0; j<q.size(); j++) {
		printf("Case #%d: %lld\n", j + 1,
  				ans[lower_bound(key.begin(), key.end(), q[j].second) - key.begin()]
  				-
  				ans[lower_bound(key.begin(), key.end(), q[j].first) - key.begin() - 1]
			);
	}
} 
