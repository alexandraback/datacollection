#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

void solve() {
	long long p, q;
	scanf("%lld/%ldd", &p, &q);
	if (p == q) {
		cout << 0 << endl;
		return;
	}
	ll d = gcd(p, q);
	p /= d; q /= d;
	for (int t = 1; t <= 40; ++t) {
		ll r1 = (1ll << (40 - t));
		ll r2 = (1ll << t);
		ll rd = max(r1, r2);
		ll a = rd / r1;
		ll b = rd / r2;
		if (rd % q == 0) {
			rd /= q;
			rd *= p;
			if ((rd - b) % a == 0) {
				ll x = (rd - b) / a;
				if (x >= 0 && x <= r1) {
					cout << t << endl;
					return;
				}
			}
		}
	}
	cout << "impossible" << endl;
}

int main(int argc, char **argv) {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	forn(t, tt) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
	}
	return 0;
}
