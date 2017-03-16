#include <stdio.h>
#include <cstring>
#define maxl 100010
#define min(a,b) ((a) < (b) ? (a) : (b))

double f[maxl][2], p[maxl];
int n, m;

double calc(int d) {
	double ans = f[d][1] * (m - d + n - d + 1 + n + 1);
	ans += f[d][0] * (m - d + n - d + 1);
	//printf("n %d %d %d\n", d, m - d + n - d + 1 + n + 1, m - d + n - d + 1);
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int q=1; q<=t; ++q) {
		scanf("%d%d", &m, &n);
		memset(f, 0, sizeof f);
		f[0][0] = 1.0;
		f[0][1] = 0.0;
		for(int i=1; i<=m; ++i) {
			scanf("%lf", &p[i]);
			f[i][0] = f[i-1][0] * p[i];
			f[i][1] = f[i-1][1] + f[i-1][0] * (1 - p[i]);
			
			//printf("%d %lf %lf\n", i, f[i][0], f[i][1]);
		}

		double ans = n + 2;
		for(int i=1; i<=m; ++i) {
			double tmp = calc(i);
			ans = min(ans, tmp);
			//printf("%d %lf\n", i, tmp);
		}
		printf("Case #%d: %.10lf\n", q, ans);
	}
	return 0;
}

