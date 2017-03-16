#include <cstdio>

int S;
char count[1005];

int main() {
	freopen("A-large.in.txt", "r", stdin);	
	freopen("A-large.out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d%s", &S, count);
		int ans = 0, sum = 0;
		for (int i = 0; i <= S; ++i) {
			if (sum < i) {
				ans += i - sum;
				sum = i;
			}
			sum += count[i] - '0';
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
