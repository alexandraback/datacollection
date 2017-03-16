#include <stdio.h>

int T;
int n;
double v[205], s;

double max(double a, double b)
{ return a > b ? a : b; }

bool can(int idx, double rate)
{
	double sumrate = rate;
	double score = v[idx] + s * rate;
	for (int i = 1; i <= n; ++i) if (i != idx)
		sumrate += max(0, (score - v[i]) / s);
	return sumrate > 1;
}

void work()
{
	scanf("%d", &n);
	s = 0;
	for (int i = 1; i <= n; ++i) { scanf("%lf", &v[i]); s += v[i]; }
	static int ttt = 0;
	printf("Case #%d: ", ++ttt);
	for (int i = 1; i <= n; ++i) {
		double l = 0, r = 1;
		for (int iter = 1; iter <= 100; ++iter) {
			double mid = (l + r) / 2;
			if (can(i, mid)) r = mid; else l = mid;
		}
		printf("%0.6lf", r * 100);
		if (i < n) printf(" "); else printf("\n");
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) work();
}