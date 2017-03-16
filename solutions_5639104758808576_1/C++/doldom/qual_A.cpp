#include <stdio.h>

int n;
char s[1010];

int main() {
	freopen("qual\\A-large.in", "r", stdin);
	freopen("qual\\A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%d %s", &n, s);
		int ans = 0, sum = 0;
		for (int i=0; i<=n; ++i) {
			s[i] -= '0';
			if (sum < i)
				ans += i - sum, sum = i;
			sum += s[i];
		}
		printf("Case #%d: ", N);
		printf("%d\n", ans);
	}
	return 0;
}