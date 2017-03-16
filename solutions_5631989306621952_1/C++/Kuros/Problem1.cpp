#include <bits/stdc++.h>

using namespace std;

int T;

char s[1100];

int main() {
	freopen("A-large.in","r",stdin);
	freopen("ans.txt","w",stdout);

	scanf("%d", &T);
	int cas = 1;
	while(T--) {
		scanf("%s", s);
		int n = strlen(s);
		string ans = "";
		ans += s[0];
		for(int i = 1; i < n; i++) {
			if(s[i] >= ans[0]) ans = s[i] + ans;
			else ans += s[i];
		}
		printf("Case #%d: %s\n", cas++, ans.c_str());
	}
}