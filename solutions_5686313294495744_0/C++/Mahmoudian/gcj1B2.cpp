// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

ofstream fout("ans.out");
#define cout fout

const int N = 1005, mod = 0;

int match[N * 2], mark[N * 2];
vector<int> adj[N * 2];
map<string, int> pa, pb;

int dfs(int v) {
	if (v == -1)
		return 1;
	for (auto u : adj[v]) if (!mark[u]++) {
		if (dfs(match[u])) {
			match[u] = v;
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	rep(it, tc) {
		cout << "Case #" << it + 1 << ": ";
		rep(i, N) adj[i].clear();
		int m; cin >> m;
		vector<int> a, b;
		pa.clear(); pb.clear();
		memset(match, -1, sizeof match);
		rep(i, m) {
			string x, y;
			cin >> x >> y;
			int idx = 0, idy = 0;
			if (pa.find(x) == pa.end()) {
				idx = pa.size();
				pa[x] = idx << 1;
			}
			idx = pa[x];
			if (pb.find(y) == pb.end()) {
				idy = pb.size();
				pb[y] = idy << 1 | 1;
			}
			idy = pb[y];
			adj[idx].push_back(idy);
			adj[idy].push_back(idx);
		}
		int res = m - pa.size() - pb.size(), mm = 0;
		rep(i, pa.size()) {
			memset(mark, 0, sizeof mark);
			if (match[i << 1] == -1) {
				int x = dfs(i << 1);
		//		cout << x << endl;
				mm += x;
			}
		}
		cout << res + mm << endl;
	}
	return 0;
}
