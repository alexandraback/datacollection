#include <cstdio>

int T, l;
double c, f, x, t, ans, p;

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		scanf("%lf%lf%lf", &c, &f, &x);
		t = 0.; l = 0; p = t + x/(l*f + 2.);
		do {
			ans = p;
			t += c/(l*f + 2.);
			++l;
			p = t + x/(l*f + 2.);
		} while (p < ans);
		printf("Case #%d: %.7f\n", r, ans);
	}
	return 0;
}
