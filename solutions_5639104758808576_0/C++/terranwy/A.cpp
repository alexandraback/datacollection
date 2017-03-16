#include <cstdio>


int casei, cases;
int ans, n;
char st[1010];

int main() {
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d", &n);
		int ans = 0;
		scanf(" %s", st);
		int sum = 0;
		for (int i = 0; i <= n; ++i) {
			int now = st[i] - '0';
			if (now > 0 && sum + ans < i) {
				ans += i - sum - ans;
			}
			sum += now;
		}
		printf("Case #%d: %d\n", casei, ans);
	}
	
	return 0;
}
