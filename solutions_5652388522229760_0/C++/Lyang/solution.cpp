#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	int t, c;
	ll n;
	cin >> t;
	c = 0;
	while (c++ < t) {
		cin >> n;
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", c);
			continue;
		}
		int digits[10] = {};
		int seen = 0;
		ll x = 0;
		while (seen < 10) {
			x += n;
			ll y = x;
			while (y) {
				int last = y % 10;
				if (!digits[last]) {
					seen++;
					digits[last] = 1;
				}
				y /= 10;
			}
		}
		printf("Case #%d: %lld\n", c, x);
	}
	exit(0);
}