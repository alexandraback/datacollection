#include <cstdio>
#include <algorithm>

using namespace std;

int i, j, m, ans, nans;
int T, t, D, pi[1000 + 1];

int main() {
	/*for(i = 1; i <= 1000; ++i) {
		dp[i] = 0;
		mx[i] = i;
		for(j = 1; j <= i; ++j) {
			d = 1 + dp[i - j];
			m = max(j, mx[i - j]);
			if(d + m < dp[i] + mx[i]) {
				dp[i] = d;
				mx[i] = m;
			}
		}
	}*/
	scanf("%d", &T);
	for(t = 1; t <= T; ++t) {
		scanf("%d", &D);
		m = 0;
		for(i = 0; i < D; ++i) {
			scanf("%d", pi + i);
			m = max(m, pi[i]);
		}
		ans = nans = m;
		for(j = 1; j < m; ++j) {
			nans = j;
			for(i = 0; i < D; ++i)
				nans += pi[i] / j - ((pi[i] % j) ? 0 : 1);
			ans = min(nans, ans);
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
