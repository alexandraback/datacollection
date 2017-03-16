#include <stdio.h>

const int MAXN = 100010;

int m, n;
double p[MAXN];
double right[MAXN];
double ans;

int main() {
	int cases;
	scanf("%d", &cases);
	for (int k = 1; k <= cases; ++k) {
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m; ++i) scanf("%lf", &p[i]);
		right[0] = 1;
		for (int i = 1; i <= m; ++i)
			right[i] = right[i - 1] * p[i];
		ans = 1 + n + 1;
		for (int i = m; i >= 0; --i) {
			double count = (m - i) + (n - i + 1);
			count += (1 - right[i]) * (n + 1);
			if (count < ans) ans = count;
		}
		printf("Case #%d: %.6lf\n", k, ans);
	}
	return 0;
}
