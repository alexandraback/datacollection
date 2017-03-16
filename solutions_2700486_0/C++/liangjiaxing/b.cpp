#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

double C(int n, int m) {
	double ret = 1;
	if (m > n) return 0;
	for (int i = 1; i <= m; i++) {
		ret *= n + 1 - i;
		ret /= i;
	}
	return ret;
}

int main() {
	int T;
	freopen("B-small-attempt2 (1).in", "r", stdin); freopen("w.txt", "w", stdout);
	scanf("%d", &T);
	for (int re = 1; re <= T; re++) {
		int m = 0, step = 1;
		int N, X, Y;
		scanf("%d%d%d", &N, &X, &Y);
		int n, p = -2;
		n = N;
		while (m + step <= n) {
			p += 2;
			m += step;
			step += 4;
		}
		// printf("m = %d p = %d  ", m, p);
		X = abs(X);
		// printf("X + Y = %d, %d ", X, Y);
		if (X + Y <= p) {
			printf("Case #%d: 1.0\n", re);
		} else if (n - m == 0 || X + Y != p + 2) {
			printf("Case #%d: 0.0\n", re);
		} else {
			double ans = 0, d = 0;
			p += 2;
			int rem = n - m;
			for (int i = 0; i <= p && i <= rem; i++) {
				if (rem - i > p) continue;
				d += C(rem, i);
			}
			for (int i = 0; i <= p - X && i <= p && i <= rem; i++) {
				// printf("%d\n", i);
				if (rem - i > p) continue;
				ans += C(rem, i);
				// printf("C(%d, %d)\n", rem, i);
			}
			printf("Case #%d: %.10f\n", re, 1 - ans / d);
		}
	}
}
