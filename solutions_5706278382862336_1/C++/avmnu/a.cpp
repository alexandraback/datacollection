#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

#define ll long long int
#define imp printf("Case #%lld: impossible\n", i);
#define res_(res) printf("Case #%lld: %lld\n", i, res);

using namespace std;

ll gcdr(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	
	return gcdr(b % a, a);
}

int main()
{
	ll t;
	ll p2[43];

	p2[0] = 1;

	for (int x = 1; x < 43; x++) {
		p2[x] = p2[x - 1] * 2;
	}

	scanf ("%lld", &t);

	for (ll i = 1; i <= t; i++) {
		ll p, q;

		scanf("%lld/%lld", &p, &q);

		ll l = gcdr(p, q);

		if (l > 1) {
			p /= l;
			q /= l;
		}


		if (binary_search(p2, p2 + 41, q)) {
			if (p > q) {
				imp;
			} else {
				ll res = 1;

				while (true) {
					if (p >= (q / 2)) {
						res_(res);

						break;
					}

					res++;

					if (res > 40) {
						break;
					}

					q /= 2;
				}

				if (res > 40) {
					imp;
				}
			}
		} else {
			imp;
		}
	}

	return 0;
}
