#include <cstdio>

long long gcd(long long a, long long b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		printf("Case #%d: ", ca);
		long long p, q;
		scanf("%lld/%lld", &p, &q);
		long long d = gcd(p, q);
		p /= d;
		q /= d;
		long long t = q;
		while (t % 2 == 0)
			t /= 2;
		if (t > 1) {
			puts("impossible");
			continue;
		}
		t = 0;
		while (p < q) {
			p *= 2;
			++t;
		}
		printf("%lld\n", t);
	}
	return 0;
}
