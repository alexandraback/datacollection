#include <bits/stdc++.h>
using namespace std;
int T, N;
char s[1050];
int main () {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d%s", &N, s);
		int sum = 0, ans = 0;
		for (int i = 0; i <= N; ++i) {
			if (s[i] == '0') continue;
			if (sum < i) {
				ans += i - sum;
				sum = i;
			}
			sum += s[i] - '0';
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
