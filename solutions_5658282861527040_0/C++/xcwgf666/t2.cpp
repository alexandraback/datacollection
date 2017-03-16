#include <cstdio>

int ans, Tn, Ti, n, m, k, i, j;

int main () {
	freopen("input.txt", "r", stdin);
	scanf("%d", &Tn);
	for(Ti = 1; Ti <= Tn; Ti++) {
		scanf("%d %d %d", &n, &m, &k);
		ans = 0;
		for(i = 0; i < n; i++) for(j = 0; j < m; j++) if ((i & j) < k) ++ans;
		printf("Case #%d: %d\n", Ti, ans);
	}
	return 0;
}