#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		double c, f, x, t = 0, v = 2, ans = 1e10;
		scanf("%lf%lf%lf", &c, &f, &x);
		for (; ; v += f) {
			if (t + x / v < ans) {
				ans = t + x / v;
			} else break;
			t += c / v;
		}
		printf("Case #%d: %.10f\n", cas, ans);
	}
}