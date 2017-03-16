#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll p, q;

ll gcd(ll a, ll b) {
	while (b != 0) {
		ll temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void clean() {
	ll d = gcd(p, q);
	p /= d;
	q /= d;
}

int solve() {
	clean();
	for (int i = 0; i < 40; ++i) {
		if (q == 1) {
			ll last = p;
			p *= 2;
			if (p < last)
				return -1;
		}
		else if (q % 2 == 0) {
			q /= 2;
		}
		else
			return -1;
	}

	clean();
	if (q != 1)
		return -1;
	int level = 0;
	while (p >= 2) {
		level++;
		p /= 2;
	}
	return 40-level;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		scanf("%lld/%lld\n", &p, &q);
		cout << "Case #" << i << ": ";
		int a = solve();
		if (a == -1)
			cout << "impossible";
		else
			cout << a;
		cout << endl;
	}
}
