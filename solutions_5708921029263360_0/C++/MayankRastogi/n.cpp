#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pi 3.14159265
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define MEM(x, y) memset(x, y, sizeof(x))
#define round(x) x + 0.5
using namespace std ;

int sp[12][12], pj[12][12], sj[12][12];
vector<pair<int, pii > > ans;
int main() {
	freopen("C-small-attempt4.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		int sh, pa, ja, k;
		cin >> ja >> pa >> sh >> k;
		
		ans.clear();
		MEM(sp, 0);
		MEM(pj, 0);
		MEM(sj, 0);
		
		for (int s = 1; s <= sh; s++) {
			for (int p = 1; p <= pa; p++) {
				for (int j = 1; j <= ja; j++) {
					if (sp[s][p] < k && pj[p][j] < k && sj[s][j] < k) {
						ans.pb(mp(j, mp(p, s)));
						sp[s][p]++;
						pj[p][j]++;
						sj[s][j]++;
					}
				}
			}
		}
		
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].f << " " << ans[i].s.f << " " << ans[i].s.s << endl;
		}
	}
	return 0;
}