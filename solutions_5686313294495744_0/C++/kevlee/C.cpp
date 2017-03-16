#include <bits/stdc++.h>
using namespace std;
int T, n;
char s[25][25], t[25][25];
int main () {
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	scanf("%d", &T);
	for (int test=1; test<=T; test++) {
		int ans=0;
		scanf("%d", &n);
		for (int i=0; i<n; i++) scanf(" %s %s", s[i], t[i]);
		for (int i=0; i<(1<<n); i++) {
			map<string, int>la, ra;
			int cnt=0;
			for (int j=0; j<n; j++) {
				if (i&(1<<j)) {
					la[s[j]]=2;
					ra[t[j]]=2;
				}
			}
			bool ok=true;
			for (int j=0; j<n; j++) {
				if (!(i&(1<<j))) {
					cnt++;
					if (la.find(s[j])==la.end()) {
						ok=false;
						break;
					}
					if (ra.find(t[j])==ra.end()) {
						ok=false;
						break;
					}
				}
			}
			if (ok) ans=max(ans, cnt);
		}
		printf("Case #%d: %d\n", test, ans);
	}
}
