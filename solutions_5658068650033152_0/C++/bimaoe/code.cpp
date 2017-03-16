#include <stdio.h>
#include <iostream>

using namespace std;

int main (void) {
	int n, m, k;
	int T, c, i, j;
	scanf ("%d", &T);
	for (c = 1; c <= T; c++) {
		printf ("Case #%d: ", c);
		scanf ("%d%d%d", &n, &m, &k);
		if (k < 5) {
			printf ("%d\n", k);
			continue;
		}
		int ans = k;
		for (i = 1; i <= n-2; i++) {
			for (j = 1; j <= m-2; j++) {
				int block = 2*i + 2*j + i*j;
				if (block > k)	break;
				int currans = 2*i+2*j+k-block;
				//printf ("%d %d %d\n", i, j, currans);
				ans = min(ans, currans);
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}