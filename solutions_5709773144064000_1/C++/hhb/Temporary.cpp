#include <stdio.h>

double solve() {
	double C, F, X;
	scanf("%lf%lf%lf", &C, &F, &X);
	double mint = X / 2, t = 0, r = 2;
	for (int i = 1; i <= X; i++) {
		t += C / r;
		r += F;
		double tt = t + X / r;
		if (tt < mint) mint = tt;
	}
	return mint;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int c = 1; c <= T; c++) {
		printf("Case #%d: %.7lf\n", c, solve());
	}
}