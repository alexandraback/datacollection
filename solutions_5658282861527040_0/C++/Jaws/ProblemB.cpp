#include <stdio.h>

int main() {
	freopen ("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);
		int count = 0;
		for (int m = 0; m < a; m++) {
			for (int n = 0; n < b; n++) {
				if ((m & n) < k) {
					count++;
				}
			}
		}
		printf("Case #%d: %d\n", i + 1, count);
	}		
	fclose(stdout);
	return 0;
}