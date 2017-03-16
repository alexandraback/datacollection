#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100;
const int MOD = 1e9 + 7;

char w[MAXN][2];
int p[MAXN];
char train[100 * MAXN];
string ww[MAXN];
bool used[26];
vector<vector<int> > g;

void dfs(int v) {
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
}

ll fact(int n) {
	ll res = 1;
	for (int i = 1; i <= n; ++i) {
		res = (res * i) % MOD;
	}
	return res;
}

void solve() {
	int n;
	scanf("%d\n", &n);
	vector<bool> has(26, false);
	vector<int> middle(26, 0), same(26, 0), in(26, 0);
	g.clear();
	g.resize(26);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		w[i][0] = s[0];
		w[i][1] = s[s.size() - 1];
		if (w[i][0] == w[i][1]) {
			same[w[i][0] - 'a']++;
		} else {
			g[w[i][0] - 'a'].push_back(w[i][1] - 'a');
			in[w[i][1] - 'a']++;
		}
		has[w[i][0] - 'a'] = true;
		has[w[i][1] - 'a'] = true;
		int l = 0;
		while (l < s.size() && s[l] == w[i][0]) {
			l++;
		}
		int r = s.size() - 1;
		while (r >= 0 && s[r] == w[i][1]) {
			r--;
		}
		//fprintf(stderr, "%c%c\n", w[i][0], w[i][1]);
		if (r > l && w[i][0] == w[i][1]) {
			printf("0");
			return;
		}
		for (int j = l; j <= r; ++j) {
			if (j > l && s[j] == s[j - 1]) {
				continue;
			}
			middle[s[j] - 'a']++;
		}
	}
	for (int i = 0; i < 26; ++i) {
		if ((has[i] && middle[i]) || middle[i] > 1 || g[i].size() > 1) {
			printf("0");
			return;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (w[i][0] == w[i][1]) {
			g[w[i][0] - 'a'].push_back(w[i][1] - 'a');	
		}
	}
	int blocks = 0;
	memset(used, 0, sizeof(used));
	for (int i = 0; i < 26; ++i) {
		if (!used[i] && g[i].size() && in[i] == 0) {
			//fprintf(stderr, "%c->%c\n", i + 'a', g[i][0] + 'a');
			dfs(i);
			blocks++;
		}
	}
	fprintf(stderr, "blocks: %d\n", blocks);
	ll ans = 1;
	if (blocks == 0) {
		ans = 0;
	}
	for (int i = 0; i < 26; ++i) {
		ans = (ans * fact(same[i])) % MOD;
	}
	ans = (ans * fact(blocks)) % MOD;
	cout << ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		fprintf(stderr, "Test: %d\n", i + 1);
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}