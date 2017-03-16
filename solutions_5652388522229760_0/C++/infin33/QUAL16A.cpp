#include <stdio.h>
int T, N, C, check[11],i,j,k,l;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		++C;
		scanf("%d", &N);
		for (j = 0; j <= 9; j++) check[j] = 0;
		int flag = 0;
		for (k = 1; k <= 10000; k++) {
			l = N*k;
			while (l != 0) {
				check[l % 10] = 1;
				l /= 10;
			}
			for (j = 0; j <= 9; j++) {
				if (check[j] == 0) break;
			}
			if (j == 10) {
				flag = 1; printf("Case #%d: %d\n", C,N*k); break;
			}
		}
		if (flag == 0) printf("Case #%d: INSOMNIA\n", C);
	}
	return 0;
}