#include <cstdio>

int T, n, d[200], tot, rem, sum;
double ans[200];
bool f;

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d:", r);
		scanf("%d", &n);
		tot = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", d + i);
			tot += d[i];
			ans[i] = -1;
		}
		sum = tot;
		tot += tot;
		rem = n;
		do {
			f = 0;
			for (int i = 0; i < n; ++i)
				if (ans[i] < -.5 && d[i]*rem > tot) {
					ans[i] = 0;
					--rem;
					tot -= d[i];
					f = 1;
				}
		} while (f);
		for (int i = 0; i < n; ++i)
			if (ans[i] < -.5)
				ans[i] = (1.*tot/rem - d[i])/sum;
		for (int i = 0; i < n; ++i)
			printf(" %.6lf", ans[i]*100);
		puts("");
	}
	return 0;
}
