#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;

map<pair<pair<ll, ll>, ll>, ll> dp;

ll slow(ll a, ll b, ll k) {
	ll res = 0;
	for(int i = 0; i < a; i++) {
		for(int j = 0; j < b; j++) {
			if((i & j) < k) res++;
		}
	}
	return res;
}

ll solve(ll a, ll b, ll k) {
	if(a == 0 || b == 0 || k == 0) return 0;
	if(a > b) swap(a, b);

	//cerr << a << ' ' << b << ' ' << k << '\n';

	pair<pair<ll, ll>, ll> st = make_pair(make_pair(a, b), k);
	if(dp.count(st)) return dp[st];

	ll e = 0;
	while((1 << e) < b) e++;
	if(e == 0) {
		//a = b = 1, k = ?
		return 1;
	}
	e --;
	ll v = 1 << e;

	//cerr << a << ' ' << b << ' ' << k << ' ' << v << '\n';
	if(k > 2 * v) k = 2 * v;
	ll res = 0;
	if(a > v && b > v) {
		if(k >= v) {
			res += solve(a - v, b - v, k - v);
			res += (a - v) * v;
			res += (b - v) * v;
			res += v * v;
		} else {
			res += solve(a - v, v, k);
			res += solve(b - v, v, k);
			res += solve(v, v, k);
		}
	} else {
		if(k > v) k = v;
		res += solve(a, b - v, k);
		res += solve(a, v, k);
	}

	//cerr << a << ' ' << b << ' ' << k << ' ' << v << ' ' << res << ' ' << slow(a, b, k) << '\n';
	return dp[st] = res;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		ll a, b, k; cin >> a >> b >> k;
		ll res = solve(a, b, k);
		ll check = slow(a, b, k);
		if(res != check)  cerr << a << ' ' << b << ' ' << k << ' ' << res << ' ' << check << '\n';
		cout << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}

