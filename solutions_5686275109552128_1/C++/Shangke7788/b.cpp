#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 1010;
int a[MAX_N], n;

int main() {
#ifdef _SHANGKE_
	time_t _t1 = clock();
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		sort(a, a + n), reverse(a, a + n);
		int ans = a[0];
		for (int x = a[0]; x >= 1; x--) {
			int tmp = 0;
			for (int i = 0; i < n; i++) {
				tmp += (a[i] - 1) / x;
			}
			ans = min(ans, tmp + x);
		}
		printf("Case #%d: %d\n", ca, ans);
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
