#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define oo 1e9
#define pi 3.1415926536
#define all(x) x.begin(),x.end()
#define sorta(x) sort(all(x))
#define sortam(x,comp) sort(all(x),comp)
#define sortd(x) sort(x.rbegin(),x.rend())
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
#define sfd(x) scanf("%f", &x)

typedef long long ll;
using namespace std;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	sf(t);
	for(int tc = 1; tc <= t; tc++) {
		int b;
		ll m;
		sf(b); sfll(m);
		printf("Case #%d: ", tc);

		ll dp[55] = {0};
		dp[b] = 1;
		vector<pair<int, int> >edg;
		for(int i = b - 1; i >= 1; i--) {
			for(int j = i + 1; j <= b; j++) {
				if(dp[i] + dp[j] <= m)
					dp[i] += dp[j], edg.push_back({i, j});
			}
		}
		
		if(dp[1] != m) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		cout << "POSSIBLE\n";
		vector<vector<int> >res(b, vector<int>(b, 0));
		for(int i = 0; i < edg.size(); i++)
			res[edg[i].first - 1][edg[i].second - 1] = 1;

		for(int i = 0; i < b; i++) {
			for(int j = 0; j < b; j++)
				cout << res[i][j];
			cout << endl;
		}
	}
	return 0;
}
