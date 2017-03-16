#include <stdio.h>
#include <string.h>

const int MAXN = 105;

char s[MAXN];

int solve() {
	int n = strlen(s);
	int ret = 0;
	while (1) {
		int pos = -1;
		if (s[0] == '+') {
			int i;
			for (i = 0; i < n; i++) {
				if (s[i] == '-') break;
			}
			if (i == n)  {
				break;
			} else {
				pos = i;
			}
		} else {
			int i;
			for (i = 0; i < n; i++) {
				if (s[i] == '+') break;
			}
			pos = i;
		}
		++ret;
		for (int i = 0; i < pos; i++) {
			if (s[i] == '-') {
				s[i] = '+';
			} else {
				s[i] = '-';
			}
		}
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%s", s);
		printf("Case #%d: %d\n", i, solve());
	}
}