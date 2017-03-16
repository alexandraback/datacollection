#include <bits/stdc++.h>
using namespace std;
char shy[1005];
int main() {
#ifdef youmu
	freopen("A.in", "r", stdin);
	freopen("A.ou", "w", stdout);
#endif
	int T, n, cases = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		scanf("%s", shy);
		int ans = 0, now = shy[0] - '0';
		for(int i = 1; i <= n; i++) {
			if(now < i) {
				ans += i - now;
				now = i;
			}
			now += shy[i] - '0';
		}
		printf("Case #%d: %d\n", ++cases, ans);
	}
	return 0;
}
