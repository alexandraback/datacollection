#pragma warning(disable:4996)
#include <stdio.h>

typedef long long LL;

char S[128];
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s", S);
		int sol = (S[0] == '-') ? 1 : 0;
		for (int i = 1; S[i] != '\0'; i++) {
			if (S[i] != S[i - 1]) {
				if (S[i] == '-') sol += 2;
			}
		}
		printf("Case #%d: %d\n", tc, sol);
	}
	return 0;
}