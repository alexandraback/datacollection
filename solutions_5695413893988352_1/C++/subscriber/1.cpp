#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 111111
using namespace std;
typedef pair<int,int> pt;

string a, b;
vector<pair<long long, pair<long long, long long> > > dp[33][2];

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> a >> b;

		for (int i = 0; i <= 20; i++)for (int j = 0; j < 2; j++) dp[i][j].clear();
		dp[0][0].pb(mp(0, mp(0, 0)));

		for (int i = 0; i < a.size(); i++) for (int j = 0; j < 2; j++) {

		sort(dp[i][j].begin(), dp[i][j].end());
		
		for (int k = 0; k < dp[i][j].size(); k++) {
			int bad = 0;
			int end = 0;
			if (k > 0) {
				if (dp[i][j][k].F == dp[i][j][0].F) {
					bad = 1;
				} else end = 1;
			}
			if (bad) continue;

			for (int x = 0; x < 10; x++) for (int y = 0; y < 10; y++) {
				if (a[i] != '?' && a[i] - '0' != x) continue;
				if (b[i] != '?' && b[i] - '0' != y) continue;

				if (j == 0) {
					long long d = dp[i][j][k].F * 10 + x - y;
					if (d >= 0) {
						dp[i + 1][0].pb(mp(d, mp(dp[i][j][k].S.F * 10 + x, dp[i][j][k].S.S * 10 + y)));
					} else {
						d = -d;
						dp[i + 1][1].pb(mp(d, mp(dp[i][j][k].S.F * 10 + x, dp[i][j][k].S.S * 10 + y)));
					}
				} else {
					long long d = dp[i][j][k].F * 10 + y - x;
					if (d >= 0) {
						dp[i + 1][1].pb(mp(d, mp(dp[i][j][k].S.F * 10 + x, dp[i][j][k].S.S * 10 + y)));
					} else {
						d = -d;
						dp[i + 1][0].pb(mp(d, mp(dp[i][j][k].S.F * 10 + x, dp[i][j][k].S.S * 10 + y)));
					}
				}
			}
			if (end) break;

		}
	        }

		cout << "Case #" << tt << ": ";
		pair<long long, pair<long long, long long> > ans = mp((long long)3e18, mp(-1, -1));

		for (int j = 0; j < 2; j++) for (int k = 0; k < dp[a.size()][j].size(); k++) ans = min(ans, dp[a.size()][j][k]);


		SS h;
		h << ans.S.F;
		string t = h.str();
		while (t.size() < a.size()) t = '0' + t;
		cout << t << " ";
		
		
		SS hh;
		hh << ans.S.S;
		t = hh.str();
		while (t.size() < a.size()) t = '0' + t;
		cout << t;
		cout << endl;

	}
	return 0;
}