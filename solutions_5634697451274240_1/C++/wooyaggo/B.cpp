#include <stdio.h>
#include <string.h>

char S[111];

int main(void) {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s", S);
		int len = strlen(S);
		int cnt = 0;
		for (int i = 0; i < len - 1; i++) {
			if (S[i] != S[i+1]) cnt++;
		}
		if (S[len-1] == '-') cnt++;
		printf("Case #%d: %d\n", tc, cnt);
	}

	return 0;
}