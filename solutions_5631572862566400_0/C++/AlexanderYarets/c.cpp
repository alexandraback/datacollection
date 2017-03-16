#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1024;

int u[maxn];
int c[maxn];
int p[maxn];
int d[maxn];
vector<int> g[maxn];
int N;

int dfs(int x) {
	u[x] = 1;
	int res = 0;
	for (int y : g[x]) if (!u[y]) res = max(res, 1 + dfs(y));
	return res;
}

int solve() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) u[j] = 0;
		d[i] = dfs(i);
		//cout << d[i] << " ";
	}
	//cout << endl;
	int res = 0;
	int sum = 0;
	for (int i = 0; i < N; ++i) if (i < p[i] && p[p[i]] == i) {
		//cout << i << " " << p[i] << endl;
		//cout << d[i] << " " << d[p[i]] << endl;
		sum += 2 + d[i] + d[p[i]];
	}
	for (int i = 0; i < N; ++i) u[i] = c[i] = -1;
	//cout << "xx" << endl;

	int cc = 0;
	for (int i = 0; i < N; ++i) if (c[i] == -1) {
		int k = 0;
		int j = i;
		for (j = i; c[j] == -1; j = p[j]) {
			c[j] = cc;
			u[j] = k++;
		}
		if (c[j] == cc) res = max(res, k - u[j]);
		cc++;
	}
	return max(res, sum);
}

int main() {
	int T; cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			g[i].clear();
			cin >> p[i]; p[i]--;
		}
		for (int i = 0; i < N; ++i) {
			if (p[p[i]] != i)
				g[p[i]].push_back(i);
		}
		cout << "Case #" << tt << ": " << solve() << endl;
	}
	return 0;
}