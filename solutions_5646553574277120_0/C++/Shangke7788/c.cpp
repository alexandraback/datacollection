#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int C, D, V, a[10];
int use[33], ans;
int all[33];

bool judge(int n) {
	memset(all, 0, sizeof all);
	all[0] = 1;
	for (int i = 0; i < n; i++) {
		int v = a[i];
		for (int j = V; j >= v; j--) {
			all[j] |= all[j - v];
		}
	}
	for (int j = 1; j <= V; j++) {
		if (all[j] == 0) {
			return false;
		}
	}
	return true;
}

void gao(int cur, int T) {
	if (T >= ans) {
		return;
	}
	if (judge(D + T)) {
		ans = T;
	} else {
		for (int i = cur; i <= V; i++) {
			if (!use[i]) {
				use[i] = 1;
				a[D + T] = i;
				gao(i + 1, T + 1);
				use[i] = 0;
				if (T >= ans) {
					return;
				}
			}
		}
	}
}

int main() {
#ifdef _SHANGKE_
	time_t _t1 = clock();
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d%d%d", &C, &D, &V);
		memset(use, 0, sizeof use);
		for (int i = 0; i < D; i++) {
			scanf("%d", a + i);
			use[a[i]] = 1;
		}
		ans = 5;
		gao(1, 0);
		printf("Case #%d: %d\n", ca, ans);
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
