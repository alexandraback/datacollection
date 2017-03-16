#include <cstdio>

int main() {
	int r;
	int cs = 0;
	scanf("%d", &r);
	while (r--) {
		printf("Case #%d: ", ++cs);
		int n;
		double d, sum = 0.0;
		double a[200] = {0};
		int chk[200] = {0};
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &a[i]);
			sum += a[i];
		}
		
		int cnt = 0;
		double sum2 = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > sum * 2 / n) chk[i] = 1;
			else {
				cnt++;
				sum2 += a[i];
			}
		}
		d = (sum2 + sum) / cnt;
		
		for (int i = 0; i < n; ++i) {			
			double t;
			if (chk[i]) t = 0.0f;
			else t = (d - a[i]) / sum * 100;
			printf("%.7lf%c", t, (i == n - 1) ? '\n' : ' ');
		}
	}
	return 0;
}
