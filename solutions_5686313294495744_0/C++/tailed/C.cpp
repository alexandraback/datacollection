#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define each(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
typedef long long ll;


int TC;


class BipartiteMatching {
public:
	vector<vector<int> > G;
	void add_edge(int u, int v) {
		G.resize(max<int>(G.size(), max(u, v)+1), vector<int>());
		G[u].push_back(v);
	}
	int run() {
		size_t n = G.size();
		match.assign(n, -1);
		int res = 0;
		rep(u, n) used.assign(n, false), res += dfs(u);
		return res;
	}
private:
	vector<bool> used;
	vector<int> match;
	bool dfs(int u) {
		used[u] = true;
		each(it, G[u]) {
			int w = match[*it];
			if (w == -1 || (!used[w] && dfs(w)))
				return match[*it] = u, true;
		}
		return false;
	}
};

void solve() {
	int m;
	cin >> m;
	BipartiteMatching bm;
	map<string, int> name2id;
	int cur = 0;
	rep(i, m) {
		string a, b;
		cin >> a >> b;
		a = "$" + a;
		b = "^" + b;
		for(auto x : {a, b}) {
			if (!name2id.count(x)) {
				name2id[x] = cur++;
			}
		}
		int x = name2id[a], y = name2id[b];
		bm.add_edge(x, y);
	}
	int k = bm.run();
	cout << m - sz(name2id) + k << endl;
}
int main() {
	int T; cin >> T;
	for(TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

