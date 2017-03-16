#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)

int t, n, ans; char s[12345];
int main() {
	freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	scanf("%d", &t);
	fo(tc,1,t+1) {
		scanf("%d", &n); ans = 0;
		scanf("%s", s);
		int c = 0;
		fo(i,0,n) {
			c += s[i] - '0';
			ans = max(ans, i+1 - c);
		}
		printf("Case #%d: %d\n", tc, ans);
	}

	return 0;
}