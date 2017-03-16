#include <cstdio>

int ts, n;
double a[222], X;

double sol(double w) {
	double l = 0., r = 1.;
	for (int i = 0; i < 100; i++) {
		double m = (l+r)/2.;
		double c = 0.;
		for (int k = 0; k < n; k++)
			if (a[k] < w+X*m)
				c += (w+X*m-a[k])/X;
		if (c > 1.)
			r = m;
		else
			l = m;
	}
	return l*100.;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &ts);
	for (int t = 1; t <= ts; t++) {
		scanf("%d", &n);
		X = 0.;
		for (int i = 0; i < n; i++) {
			scanf("%lf", &a[i]);
			X += a[i];
		}
		printf("Case #%d:", t);
		for (int i = 0; i < n; i++)
			printf(" %.6lf", sol(a[i]));
		puts("");
	}
	return 0;
}