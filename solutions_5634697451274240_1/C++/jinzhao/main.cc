#include <cstdio>
#include <cstring>

char s[101];

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%s", s);
		int ls = strlen(s);
		int ans = 0;
		for (int i = 1; i < ls; i++) {
			if (s[i] != s[i - 1]) ans++;
		}
		if (s[ls - 1] == '-') ans++;
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
