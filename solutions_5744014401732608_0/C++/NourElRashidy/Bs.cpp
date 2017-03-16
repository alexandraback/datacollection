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

vector<vector<int> >g;
int b, msk;
int dp[10];
int go(int i) {
	if(i == b)
		return 1;

	if(dp[i] != -1)
		return dp[i];

	dp[i] = -oo;
	int ret = 0;
	for(int j = 0; j < g[i].size(); j++) {
		ret += go(g[i][j]);
	}

	return dp[i] = ret;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	sf(t);
	for(int tc = 1; tc <= t; tc++) {
		ll m;
		sf(b); sfll(m);
		printf("Case #%d: ", tc);
		vector<pair<int, int> >edg;
		for(int i = 2; i <= b; i++)
			edg.push_back({1, i});
		for(int i = 2; i < b; i++)
			edg.push_back({i, b});
		for(int i = 2; i < b; i++)
		for(int j = 2; j < b; j++)
		if(i != j)
			edg.push_back({i, j});

		int n = edg.size();
		for(msk = 0; msk < (1 << n); msk++) {
			memset(dp, -1, sizeof dp);
			g.clear();
			g.resize(b + 1);
			for(int i = 0; i < n; i++) {
				if(msk&(1 << i))
					g[edg[i].first].push_back(edg[i].second);
			}
			if(go(1) == m)
				break;
		}

		if(msk == (1 << n)) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		cout << "POSSIBLE\n";
		vector<vector<int> >res(b, vector<int>(b, 0));
		for(int i = 0; i < n; i++) {
			if(msk&(1 << i))
				res[edg[i].first - 1][edg[i].second - 1] = 1;
		}

		for(int i = 0; i < b; i++) {
			for(int j = 0; j < b; j++)
				cout << res[i][j];
			cout << endl;
		}
	}
	return 0;
}
