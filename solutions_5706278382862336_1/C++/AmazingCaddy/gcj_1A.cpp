#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

int solve (ll p, ll q) {
	ll qq = q;
	while (qq > 1) {
		if (qq % 2 == 0) {
			qq /= 2;
		} else {
			return -1;
		}
	}
	int cnt = 0;
	while (p < q) {
		if (q % 2 == 0) {
			q /= 2;
		} else {
			return -1;
		}
		cnt ++;
	}
	return cnt;
}

int main(int argc, char *argv[]) {
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cas;
	scanf ("%d", &cas);
	for (int t = 1; t <= cas; t ++) {
		ll p, q;
		char ch;
		cin >> p >> ch >> q;
		//cout << p << " " << q << "\n";
		ll d = gcd (p, q);
		//cout << "d = " << d << "\n";
		if (d > 1) {
			p /= d;
			q /= d;
		}
		int ans = solve(p, q);
		if (ans == -1) {
			cout << "Case #" << t << ": " << "impossible" << "\n";
		} else {
			cout << "Case #" << t << ": " << ans << "\n";
		}
	}
	return 0;
}
