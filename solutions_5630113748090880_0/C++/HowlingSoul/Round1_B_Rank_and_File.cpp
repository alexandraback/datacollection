#include <stdio.h>
int chkoe[2005];
int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B_small.out", "w", stdout);
	int t, tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++){
		int n, i, j, tm;
		scanf("%d", &n);
		for (i = 1; i <= 2500; i++) chkoe[i] = 0;
		for (i = 1; i <= 2 * n - 1; i++) for (j = 1; j <= n; j++){
			scanf("%d", &tm);
			chkoe[tm]++;
		}
		printf("Case #%d: ", t);
		for (i = 1; i <= 2500; i++) if (chkoe[i] % 2 == 1) printf("%d ", i);
		printf("\n");
	}
	return 0;
}