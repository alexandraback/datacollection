#include <stdio.h>
int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D_small.out", "w", stdout);
	int t, tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++){
		int k, c, s, i;
		scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d: ",t);
		for (i = 1; i <= k; i++) printf("%d ", i);
		printf("\n");
	}
	return 0;	
}