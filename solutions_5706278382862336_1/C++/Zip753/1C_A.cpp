#include <cstdio>

long long gcd(long long a, long long b) {
	while (b != 0) {
		a %= b;
		long long c = a; a = b; b = c;
	}
	return a;
}

void no() {
	printf("impossible\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int qwe;
	scanf("%d\n", &qwe);
	for (int t = 1; t <= qwe; t++) {
		printf("Case #%d: ", t);
		long long p, q;
		scanf("%lld/%lld\b", &p, &q);
		long long d = gcd(p, q);
		// printf("> %lld\n", d);
		p /= d; q /= d;
		// long long a = 0, b = 1, c = 1; d = 1;
		// long long x, y;
		// int ans;
		// for (ans = 0; ans <= 40; ans++) {
		// 	if (a == p && b == q || c == p && d == q) break;
		// 	x = a * d + b * c;
		// 	y = 2ll * b * d;
		// 	long long gc = gcd(x, y);
		// 	x /= gc; y /= gc;
		// 	if (x * q <= p * y) {
		// 		a = x;
		// 		b = y;
		// 	}
		// 	else {
		// 		c = x;
		// 		d = y;
		// 	}
		// }
		// if (ans > 40) {
		// 	printf("impossible\n");
		// }
		// else {
		// 	printf("%d\n", ans);
		// }
		if ((q & (q - 1)) != 0) {
			no();
		}
		else {
			int ans;
			for (ans = 1; 2ll * p < q; ans++, q /= 2ll);
			printf("%d\n", ans);
		}
	}
	return 0;
}
