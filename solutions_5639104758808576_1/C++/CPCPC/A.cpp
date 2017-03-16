#include <cstdio>
const int N = 1005;
char s[N];
int T, n, cnt, ans;
int main() {
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d%s", &n, s);
		cnt = ans = 0;
		for (int i = 0; i <= n; i++) {
			if (cnt < i) {
				ans += i-cnt;
				cnt = i;
			}
			cnt += s[i]-'0';
		}
		printf("Case #%d: %d\n", C, ans);
	}
	return 0;
}
