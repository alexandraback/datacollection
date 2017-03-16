#include <stdio.h>
#include <string.h>
int T, i, j, k, l, C,N;
char S[105],S2[105];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &T);
	while (T--) {
		scanf("%s\n", S + 1);
		C++;
		N = strlen(S + 1); k = 0;
		for (i = N; i >= 1; i--) {
			if (S[i] == '-') {
				for (l = 1; l <= i; l++) {
					if (S[l] == '-') break;
				}
				if (l != 1) {
					k++;
					for (j = 1; j <= l; j++) S[j] = '-';
				}
				for (j = 1; j <= i; j++) {
					S2[j] = S[i - j + 1];
					if (S2[j] == '-') S2[j] = '+';
					else S2[j] = '-';
				}
				k++;
				for (j = 1; j <= i; j++) S[j] = S2[j];
			}
		}
		printf("Case #%d: %d\n", C, k);
	}
}