#include <bits/stdc++.h>
using namespace std;

char s[113];

void solve() {
	scanf(" %s",&s);
	int ans = 0;
	bool rev = 0;
	for (int i=strlen(s)-1;i>=0;i--) {
		if ((s[i]=='+')==rev) {
			ans+=1;
			rev^=1;
		}
	}
	printf("%d\n",ans);
}

int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		printf("Case #%d: ",t);
		solve();
	}

	return 0;
}
