#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int T;
	int i, k, w, z = 1, q;
	int N, J;

	char sixteen[100] = "1000000000000001";
	char thirtytwo[100] = "10000000000000000000000000000001";

	char str[100];
	char str2[100];

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d %d", &N, &J);
		if (N == 16) {
			strcpy(str, sixteen);
		}
		else {
			strcpy(str, thirtytwo);
		}
		printf("Case #%d:\n", i);
		
		for (q = 0; q < N / 2; q++) {
			str[q] = '1';
			str[N - q - 1] = '1';
			for (k = N - 2 - q; k > 1; k--) {
				for (w = k - 1; w > 0; w -= 2) {
					strcpy(str2, str);
					str2[k] = '1';
					str2[w] = '1';
					printf("%s 3 4 5 6 7 8 9 10 11\n", str2);
					z++;
					if (z == J + 1) {
						return 0;
					}
				}
			}
		}
	}
}