#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
typedef long long LL;

char s[1001];
char ans[10001];
int main() {
	int T; scanf("%d",&T);
	for (int tt=1;tt<=T;tt++) {
		scanf("%s",s);
		int l=5000,r=l-1;
		ans[++r]=s[0];
		for (int i=1;s[i];i++) {
			if (ans[l]<=s[i]) ans[--l]=s[i];
			else ans[++r]=s[i];
		}
		ans[++r]=0;
		printf("Case #%d: %s\n",tt,ans+l);
	}
	return 0;
}
