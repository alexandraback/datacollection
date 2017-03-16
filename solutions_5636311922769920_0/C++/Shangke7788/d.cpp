#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main() {
#ifdef _SHANGKE_
	time_t _t1 = clock();
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		printf("Case #%d: ", ca);
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);
		for (int i = 0; i < S; i++) {
			printf("%d%c", i + 1, " \n"[i == S - 1]);
		}
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
