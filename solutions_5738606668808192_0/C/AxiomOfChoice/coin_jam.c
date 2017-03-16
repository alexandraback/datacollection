#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

ll factor[11];

ll to_base(int s, int b) {
	if (s == 0) return 0;
	return (s % 2) + b * to_base(s / 2, b);
}

ll factorize(ll x, int b) {
	for (ll y = 2; y * y <= x; y++) {
		if (x % y == 0) {
			return factor[b] = y;
		}
	}
	return -1;
}

int works(int s) {
	ll t;
	for (int b = 2; b <= 10; b++) {
		t = to_base(s, b);
		if (factorize(t, b) == -1) {
			return 0;
		}
	}

	printf("%lld", t);
	for (int b = 2; b <= 10; b++) {
		printf(" %lld", factor[b]);
	}
	printf("\n");
	return 1;
}

int main() {
	printf("Case #1:\n");
	int cnt = 0;
	for (int s = (1<<15) + 1; s < 1<<16; s += 2) {
		if ((cnt += works(s)) == 50) {
			break;
		}
	}
	return 0;
}
