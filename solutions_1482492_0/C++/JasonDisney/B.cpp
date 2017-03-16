#include <math.h>
#include <stdio.h>

int N, A;
double H, a[300], t[2100], x[2100];

int main()
{
	int T, tc, i;
	double res, s;

	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%lf%d%d", &H, &N, &A);

		for (i = 1; i <= N; i++) {
			scanf("%lf%lf", &t[i], &x[i]);
		}
		for (i = 1; i <= A; i++)
			scanf("%lf", &a[i]);

		printf("Case #%d:\n", tc);
		if (N == 1 || x[1] >= H) {
			for (i = 1; i <= A; i++) {
				printf("%lf\n", sqrt(2.0 * H / a[i]));
			}
			continue;
		}
		if (N == 2) {
			s = (x[2] - x[1]) / (t[2] - t[1]);
			for (i = 1; i <= A; i++) {
				double rt = (s + sqrt(s * s + 2 * a[i] * x[1])) / a[i];
				if (rt >= t[2]) {
					printf("%lf\n", sqrt(2.0 * H / a[i]));
				}
				else {
					double rx = 0.5 * a[i] * rt * rt;
					if (rx >= H) {
						printf("%lf\n", sqrt(2.0 * H / a[i]));
					}
					else {
						printf("%lf\n", (H - rx) / s + rt);
					}
				}
			}
		}
	}
	return 0;
}
