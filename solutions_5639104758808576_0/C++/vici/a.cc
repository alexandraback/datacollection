#include <bits/stdc++.h>
using namespace std;
char s[1110];

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-ans.txt", "w", stdout);
	int T, n, ca = 1;
	for (scanf("%d", &T); T--; ) {
		scanf("%d %s", &n, s);
		int t = 0, ret = 0;
		for (int i = 0; i <= n; ++i) {
			if (t < i) {
				ret += i - t;
				t = i;
			}
			t += s[i] - '0';
		}
		printf("Case #%d: %d\n", ca++, ret);
	}
	return 0;
}

