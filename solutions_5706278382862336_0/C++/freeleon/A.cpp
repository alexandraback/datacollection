#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
	while (b) {
		LL c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int cb1(LL a) {
	int c = 0;
	while (a) {
		c++;
		a >>= 1;
	}
	return c;
}

int lb1(LL a) {
	for (int i = 63; i >= 0; i--) {
		if (a & (1LL << i)) return i + 1;
	}
	return 0;
}

LL lowbit(LL x) {
	return x & -x;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		printf("Case #%d: ", ca);

		LL p, q;
		scanf("%lld/%lld\n", &p, &q);
		LL g = gcd(p, q);
		p /= g;
		q /= g;
		//printf("P %lld Q %lld\n", p, q);

		if (lowbit(q) != q) {
			puts("impossible");
		} else {
			printf("%d\n", abs( lb1(p) - lb1(q)) );
		}
	}
	return 0;
}
