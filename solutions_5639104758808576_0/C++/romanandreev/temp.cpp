#include <bits/stdc++.h>
using namespace std;
int n;
char s[10000];
void solve() {
	scanf("%d %s", &n, s);	
	int ans = 0;
	int c = 0;
	for (int i = 0; i <= n; i++) {
		int d = max(0, i - c);
		ans += d;
		c += d;
		c += s[i] - '0';	
	}
	printf("%d\n", ans);
}       
int main() {
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		printf("Case #%d: ", ti);
		solve();
	}
	return 0;
}