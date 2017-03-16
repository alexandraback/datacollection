#include<cstdio>

int main() {
	int T;
	scanf("%d", &T);
	for (int nm=1;nm<=T;nm++) {
		int n;
		scanf("%d", &n);
		int x[2], y[2], z[2];
		for (int i=0;i<n;i++) {
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
		}
		int ans = 0;
		if (n == 2 && z[0] != z[1]) {
			ans = 1;
		}
		printf("Case #%d: %d\n", nm, ans);
	}
	return 0;
}
