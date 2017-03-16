#include <stdio.h>

int cs, ct;
int n;
double s[210];
double X;

int main()
{
	int i, j;
	double low, high, mid, t, K;
	scanf("%d", &cs);
	for (ct = 1; ct <= cs; ct++) {
		scanf("%d", &n);
		X = 0;
		for (i = 0; i < n; i++) {
			scanf("%lf", &s[i]);
			X += s[i];
		}
		printf("Case #%d:", ct);
		for (i = 0; i < n; i++) {
			low = 0;
			high = 1;
			while (high - low > 1e-10) {
				mid = (low + high) / 2;
				K = s[i] + X * mid;
				t = 0;
				for (j = 0; j < n; j++) {
					double d = (K - s[j]) / X;
					if (d < 0) d = 0;
					if (d > 1) d = 1;
					t += d;
				}
				if (t >= 1) high = mid;
					else low = mid;
			}
			printf(" %.6lf", mid * 100);
		}
		printf("\n");
	}
	return 0;
}
