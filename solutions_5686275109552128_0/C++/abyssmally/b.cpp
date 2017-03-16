#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)

int t, n, p[12345];
int main() {
	freopen("b.in", "r", stdin); freopen("b.out", "w", stdout);
	scanf("%d", &t);
	fo(tc,1,t+1) {
		int ans = 1e9;
		scanf("%d", &n);
		fo(j,0,n) scanf("%d", p+j);
		fo(trg,1,1002) {
			int cur = trg;
			fo(j,0,n) cur += (p[j]-1)/trg;
			ans = min(ans, cur);
		}
		printf("Case #%d: %d\n", tc, ans);
	}




	return 0;
}