#include <iostream>
#include <vector>
using namespace std;

int n;
int dfs(int root, vector<int> &vis, vector<int> &f) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i] && f[i] == root) {
			vis[i] = 1;
			ans = max(ans, dfs(i, vis, f));
			vis[i] = 0;
		}
	}
	return ans + 1;
}

int main() {
	int kase;
	cin >> kase;
	for (int ii = 1; ii <= kase; ii++) {
		cin >> n;
		vector<int> f(n);
		for (int i = 0; i < n; i++) {
			cin >> f[i];
			f[i]--;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			vector<int> vis(n, 0);
			int u = i;
			vis[u] = 1;
			while (!vis[f[u]]) {
				vis[f[u]] = vis[u] + 1;
				u = f[u];
			}
			ans = max(ans, vis[u] - vis[f[u]] + 1);
		}
		int len = 0;

		vector<int> vis(n, 0);
		for (int i = 0; i < n; i++) {
			// a->b , b->a
			if (f[f[i]] == i && !vis[i]) {
				vis[i] = vis[f[i]] = 1;
				len += dfs(i, vis, f);
				len += dfs(f[i], vis, f);
			}
		}
		cout << "Case #" << ii << ": " << max(ans,len) << endl;
	}
	return 0;
}