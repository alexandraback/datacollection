#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int p[maxn];
int main() {
#ifdef youmu
	freopen("B-large.in", "r", stdin);
	freopen("B-large.ou", "w", stdout);
#endif
	int T, n, cases = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		int m = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
			m = max(m, p[i]);
		}
		int ans = INT_MAX;
		for(int i = 1; i <= m; i++) {
			int extra = 0;
			for(int j = 1; j <= n; j++) {
				if(p[j] > i) {
					extra += (p[j] / i) - (p[j] % i == 0);
				}
			}
			ans = min(ans, extra + i);
		}
		printf("Case #%d: %d\n", ++cases, ans);
	}
	return 0;
}
