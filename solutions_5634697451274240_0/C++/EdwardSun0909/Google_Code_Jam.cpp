#include<stdio.h>
#include<string.h>
int main() {
	int T;
	char S[120];
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%s", S);
		printf("Case #%d: ", k);
		int ans = 0;
		int l = strlen(S);
		for (int i = 1; i < l; i++)
			if (S[i] != S[i - 1])
				ans++;
		if (S[l - 1] == '-')
			ans++;
		printf("%d\n", ans);
	}
}