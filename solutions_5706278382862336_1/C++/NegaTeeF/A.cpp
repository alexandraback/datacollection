#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(ll p, ll q) {
	int fin = 0;
	while (q != 1) {
		fin++;
		if (q % 2 != 0) {
			printf ("impossible\n");
			return;
		}
		q /= 2;
	}
	for (ll ans = 1; ans <= fin; ans++) {
		ll maxSum = 0;
		for (ll i = fin - 1; i >= fin - ans; i--)
			maxSum += (1 << i);
		maxSum += (1 << (fin - ans));
		ll minSum = (1 << (fin - ans));
		if (maxSum >= p && p >= minSum) {
			printf ("%lld\n", ans);
			return;
		}
	}
	printf ("impossible\n");
}

int main () {
	int t;
	scanf ("%d", &t);
	for (int tests = 0; tests < t; tests++) {
		ll p, q;
		scanf ("%lld/%lld", &p, &q);
		ll g = __gcd(p, q);
		p /= g;
		q /= g;
		printf ("Case #%d: ", tests + 1);
		solve(p, q);
	}
}

