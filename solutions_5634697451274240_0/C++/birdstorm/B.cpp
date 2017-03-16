#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
char s[MAXN];
int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T; cin>>T;
	for(int cs = 1; cs <= T; cs ++) {
		cerr << "Processing Case #" << cs <<"...\n";
		scanf("%s", s);
		int n = strlen(s);
		int ans = s[0] == '-';
		for(int i = 1; i < n; i ++) {
			if(s[i] == s[i - 1]) continue;
			if(s[i] == '-') {
				ans += 2;
			}
		}
		printf("Case #%d: %d\n", cs, ans);
	}
	return 0;
}
