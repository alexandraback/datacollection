# include <string>
# include <fstream>
# include <algorithm>
# include <set>
# include <map>
# include <iostream>
# include <vector>
using namespace std;

const int maxn = 55;
vector<int> g[maxn];
vector<int> cur;
vector<int> ans;
vector<int> s;

int n, m;

int cmp(vector<int> &first, vector<int> &second) {
	if (first.size() > second.size())
		return 1;
	if (second.size() > first.size())
		return -1;
	for (int i = 0; i < first.size(); i++)
		if (first[i] > second[i])
			return 1;
		else if (second[i] > first[i])
			return -1;
	
	return 0;
}

int cmp(vector<int> &first, vector<int> &second, int len) {
	for (int i = 0; i < len; i++)
	if (first[i] > second[i])
		return 1;
	else
	if (second[i] > first[i])
		return -1;

	return 0;
}

vector<int> path;

void dfs(long long mask, int v) {
	if (ans.size() != 0 && cur.size() > 0) {
		if (cmp(cur, ans, min(cur.size(), ans.size())) > 0)
			return;
	}

	if (cur.size() == n) {
		if ((ans.size() == 0 || cmp(cur, ans) < 0)) {
			ans = cur;
		}
		return;
	}

	path.pop_back();
	if (path.size() > 0)
		dfs(mask, path.back());
	path.push_back(v);

	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if ((mask & (1LL << to)) == 0) {
			path.push_back(to);
			cur.push_back(s[to]);
			dfs(mask | (1LL << to), to);
			cur.pop_back();
			path.pop_back();
		}
	}
}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";

		cin >> n >> m;

		for (int i = 0; i < maxn; i++)
			g[i].clear();
		cur.clear();
		ans.clear();
		path.clear();
		s.resize(n);

		
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < m; i++) {
			int q, w;
			cin >> q >> w;
			q--; w--;
			g[q].push_back(w);
			g[w].push_back(q);
		}

		for (int i = 0; i < n; i++) {
			cur.push_back(s[i]);
			path.push_back(i);
			dfs((1LL << i), i);
			path.pop_back();
			cur.pop_back();
		}

		for (int i = 0; i < n; i++)
			cout << ans[i];

		cout << endl;
	}

	return 0;
}