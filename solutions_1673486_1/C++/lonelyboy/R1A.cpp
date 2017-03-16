#include <stdio.h>
#include <string.h>

int n, m;
double in[120000];
double dp[120000];

double solve() {
	double now = 1.0;
	double ret = m + 2;
	dp[0] = m + 1;
	for(int i = 0; i < n; ++i) {
		now *= in[i];
		//dp[i + 1] = now * (m - i) + (1 - now) * (m - i + m + 1);
		dp[i + 1] = m - i + (1 - now) * (m + 1);
		if(dp[i + 1] + n - i - 1 < ret) ret = dp[i + 1] + n - i - 1;
	}
	return ret;
	
}

int main() {
	int t;
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i < t; ++i) {
		scanf("%d %d", &n, &m);
		for(int j = 0; j < n; ++j) scanf("%lf", in + j);
		printf("Case #%d: %.6lf\n", i + 1, solve());
	}
	//scanf("%d");
}
