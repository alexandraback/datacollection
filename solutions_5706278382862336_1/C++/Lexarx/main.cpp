#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "math.h"

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fori(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

int main() {
	int ntc;
	cin >> ntc;
	fori(tc, 1, ntc) {
		ll p, q;
		scanf("%lld/%lld", &p, &q);
		cout << "Case #" << tc << ": ";
		ll d = gcd(p, q);
		p /= d;
		q /= d;
		ll x = q;
		while (x % 2 == 0) {
			x /= 2;
		}
		if (x > 1) {
			cout << "impossible";
		} else {
			int g = 1;
			while (p * 2 < q) {
				p *= 2;
				g++;
			}
			cout << g;
		}
		cout << endl;
	}
	return 0;
}

