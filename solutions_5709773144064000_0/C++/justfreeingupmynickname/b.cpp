#include <cstdio>

int t; long double c, f, x, r, tm, ans;
int main() {
	freopen("b.in", "r", stdin); freopen("b.out", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%Lf %Lf %Lf", &c, &f, &x);
		r = 2; tm = 0; ans = x/r;
		while (1) {
			tm += c/r; r += f;
			if (tm + x/r > ans) break;
			ans = tm + x/r;
		}
		printf("Case #%d: %.10Lf\n", tc, ans);
	}

	return 0;
}