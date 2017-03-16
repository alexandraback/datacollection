#include <cstdio>

int solve(char *s)
{
	int n = 0;

	for (int i = 0; s[i]; i++) {
		if (i == 0 || s[i] != s[i-1]) {
			n++;
		}
	}

	if (s[0] == '+') {
		return (n / 2) * 2;
	} else {
		return ((n-1) / 2) * 2 + 1;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		char S[105];
		scanf(" %s", S);
		int ans = solve(S);
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
