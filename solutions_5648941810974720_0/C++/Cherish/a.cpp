#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

string ss[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[200], ans[2020], tot;
char s[2020];

bool judge() {
	for(int i = 'A'; i <= 'Z'; ++i) if(cnt[i] != 0) return false;
	return true;
}

bool dfs(int x) {
//	if(x == 10) {
//		for(int i = 'A'; i <= 'Z'; ++i) if(cnt[i] != 0) return false;
//		return true;
//	}
	for(int i = x; i < 10; ++i) {
		rep(j, ss[i].size()) --cnt[ss[i][j]];
		bool flag = true;
		rep(j, ss[i].size()) if(cnt[ss[i][j]] < 0) flag = false;
		if(flag) {
			ans[tot++] = i;
			if(dfs(i)) return true;
			--tot;
		}
		rep(j, ss[i].size()) ++cnt[ss[i][j]];
	}
	return judge();
}

int main()
{
	int t, cas = 0;
	cin >> t;
	while(cas++ < t) {
		cin >> s;
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; s[i]; ++i) ++cnt[s[i]];
		tot = 0;
		dfs(0);
//		rep(i, 10) {
//			bool flag = true;
//			while(flag) {
//				rep(j, ss[i].size()) if(!cnt[ss[i][j]]) flag = false;
//				if(!flag) break;
//				rep(j, ss[i].size()) --cnt[ss[i][j]];
//				ans[tot++] = i;
//			}
//		}
		printf("Case #%d: ", cas);
		rep(i, tot) cout << ans[i];
		puts("");
	}
	return 0;
}

