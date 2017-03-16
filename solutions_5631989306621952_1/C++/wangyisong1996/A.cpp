#include <stdio.h>
#include <string.h>
#include <string>

const int MAXN = 1005;

char s[MAXN];

void solve() {
	scanf("%s", s + 1);
	int n = strlen(s+1);
	std::string ans;
	ans = s[1];
	for (int i = 2; i <= n; i++) {
		if (s[i] >= ans[0]) {
			ans = s[i] + ans;
		} else {
			ans = ans + s[i];
		}
	}
	printf("%s\n", ans.c_str());
}

int main() {
	int T;
	scanf("%d", &T);
	int i;
	for (i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}