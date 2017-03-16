#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m;
string Z[64];
string res, cur;
int vis[50 * 50*2+12];
vector<vector<pair<int, int> > > g;
int S;
bool done[64];
void calc(int u, int msk, int len){
	if (msk + 1 == (1 << n) && !len){
		bool c = true;
		for (int i = 1; c && i <= m*2+5; ++i)
			if (vis[i])
				c = false;
		if (c){
			if (cur.size()<res.size() || res>cur)
				res = cur;
			return;
		}
	}
	if (!len)
		return;
	for (int i = 0; i < g[u].size(); ++i)
	if (g[u][i].second > 0 && g[u][i].first!=S && !done[g[u][i].first]){
		++vis[g[u][i].second];
		done[g[u][i].first] = true;
		bool f = (msk | (1 << g[u][i].first)) == msk;
		if (!f)
			cur += Z[g[u][i].first];
		calc(g[u][i].first, msk | (1 << g[u][i].first), len - 1);
		done[g[u][i].first] = false;
		if (!f)
			cur.resize(cur.size() - 5);
		--vis[g[u][i].second];
	}
	else if (g[u][i].second < 0 && vis[-g[u][i].second]){
		--vis[-g[u][i].second];
		bool f = (msk | (1 << g[u][i].first)) == msk;
		if (!f)
			cur += Z[g[u][i].first];
		calc(g[u][i].first, msk | (1 << g[u][i].first), len - 1);
		if (!f)
			cur.resize(cur.size() - 5);
		++vis[-g[u][i].second];
	}
}
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int kk = 1; kk <= t; ++kk){
		printf("Case #%d: ", kk);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			cin >> Z[i];
		res = string(1024, '9');
		g.clear();
		g.resize(n);
		for (int a, b, i = 0; i < m; ++i){
			scanf("%d%d", &a, &b);
			--a; --b;
			g[a].push_back(make_pair(b, i + 1));
			g[b].push_back(make_pair(a, -(i + 1)));
			g[b].push_back(make_pair(a, i + 1 + m + 1));
			g[a].push_back(make_pair(b, -(i + 1 + m + 1)));
		}
		if (n == 1){
			cout << Z[0] << endl;
			continue;
		}
		memset(vis, 0, sizeof(vis));
		memset(done, 0, sizeof(done));
		for (int mid = 2; mid <= 2 * n + 2; mid += 2){
			for (int i = 0; i < n; ++i){
				S = i;
				cur = Z[i];
				calc(i, 1 << i, mid);
			}
			if (res.size() != 1024)
				break;
		}
		printf("%s\n", res.c_str());
	}
	return 0;
}