#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
typedef long long LL;

int n;
int cnt[2501];
int main() {
	int T; scanf("%d",&T);
	for (int tt=1;tt<=T;tt++) {
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for (int i=1,d;i<=2*n-1;i++)
			for (int j=1;j<=n;j++) scanf("%d",&d),cnt[d]++;
		printf("Case #%d: ",tt);
		vector<int> ans;
		for (int i=1;i<=2500;i++)
			if (cnt[i]&1) ans.pb(i);
		for (int i=0;i<ans.size();i++) printf("%d%c",ans[i],i==ans.size()-1?10:32);
	}
	return 0;
}
