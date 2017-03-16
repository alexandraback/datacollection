#include <stdio.h>

int n;
char s[1024];

void Solve() {
	scanf("%d%s", &n, s);
	int standup = 0;
	int add = 0;
	for (int i=0; i<=n; i++) {
		int p = s[i] - '0';
		if (p > 0 && standup < i) {
			add += i - standup;
			standup = i;
		}
		standup += p;
	}
	printf("%d\n", add);
}

int main() {
	int t = 0;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
