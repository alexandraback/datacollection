#include <cstdio>

int T, ans;
long long a, b, d;

long long gcd(long long a, long long b) {
	long long t;
	while (a) {
		t = b%a;
		b = a;
		a = t;
	}
	return b;
}

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%lld/%lld", &a, &b);
		d = gcd(a, b);
		a /= d; b /= d;
		if (b & b - 1) {
			puts("impossible");
			continue;
		}
		ans = 0;
		while (a < b) {
			a += a;
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
