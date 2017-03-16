#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 21;
int R, C, W;

int main() {
#ifdef _SHANGKE_
	time_t _t1 = clock();
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d%d%d", &R, &C, &W);
		int ans = 0;
		for (int i = 1; i < R; i++) {
			ans += (C + W - 1) / W;
		}
		ans += (C + W - 1) / W + W - 1;
		printf("Case #%d: %d\n", ca, ans);
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
