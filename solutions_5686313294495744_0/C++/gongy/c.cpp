#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define PB push_back
typedef long long ll;

int T, N, ans;
vector<pair<string, string>> u;
set<string> a, b, ta, tb;
map<string, int> ma, mb;
string x, y;

int main () {
	cin >> T;
	for (int _ = 1; _ <= T; _++) {
		ans = 0, u.clear(), a.clear(), b.clear();
		ma.clear(), mb.clear();
		cin >> N;
		fo(i, N) {
			cin >> x >> y;
			a.insert(x), b.insert(y);
			ma[x]++, mb[y]++;
			u.PB({x, y});
		}
		fo(i, 1<<N) {
			ta.clear(), tb.clear();
			fo(j, N) if (i&(1<<j)) ta.insert(u[j].first), tb.insert(u[j].second);
			if (ta.size() == a.size() && tb.size() == b.size()) {
				ans = max(ans, N - __builtin_popcount(i));
			}
		}
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
