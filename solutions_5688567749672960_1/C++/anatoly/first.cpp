#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

ll reverse(ll n) {
	ll r = 0;
	while (n) {
		r = r * 10 + n % 10;
		n /= 10;
	}

	return r;
}

ll add(ll from, ll to, ll x, ll baseCost) {
	ll n1 = from + x;
	ll revn1 = reverse(n1);

	if (revn1 > to) {
		return LLONG_MAX;
	}

	return baseCost + x + (to - revn1) + (revn1 != n1 ? 1 : 0);
}

ll calc(ll from, ll to) {
	if (from == to) return 0;

	ll revto = reverse(to);

	ll k = 1;
	ll cost = 0;

	ll mincost = to - from;

	while (k < to) {
		ll d = revto % 10;
		revto /= 10;

		if (d == 0) d = 9;

		ll newfrom = from;
		ll newcost = cost;

		ll cost1 = add(from, to, d * k, cost);
		if (cost1 <= mincost) {
			newcost = cost + d * k;
			newfrom = from + d * k;
			mincost = cost1;
		}

		ll cost2 = add(from, to, (d - 1) * k, cost);
		if (cost2 <= mincost) {
			newcost = cost + (d - 1) * k;
			newfrom = from + (d - 1) * k;
			mincost = cost2;
		}

		cost = newcost;
		from = newfrom;
		k *= 10;
	}

	return mincost;
}

ll solve() {
	ll n;
	cin >> n;

	ll i = 1;
	ll ans = 1;

	while (i * 10 <= n) {
		ans += calc(i, i * 10 - 1) + 1;
		i *= 10;
	}

	ans += calc(i, n);
	return ans;
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ": " << solve() << endl;
	}
}