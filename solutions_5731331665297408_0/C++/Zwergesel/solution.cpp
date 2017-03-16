#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

string zip[50];
bool visit[50];
int order[50];
int reach[50];
vector<int> g[50];
bool a[50][50];
int dfs_inx[50];
int dfs_id;

void dfs(int city) {
	dfs_inx[city] = dfs_id;
	for (size_t i=0; i<g[city].size(); i++) {
		int c = g[city][i];
		if (!visit[c] && dfs_inx[c] != dfs_id) dfs(c);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	// Reset
	for (int i=0; i<n; i++) g[i].resize(0);
	fill_n(visit, n, false);
	fill_n(reach, n, -1);
	fill_n(&a[0][0], 50*50, false);
	fill_n(dfs_inx, n, 0);
	dfs_id = 1;
	// Read
	int start = 0;
	for (int i=0; i<n; i++) {
		cin >> zip[i];
		if (zip[i] < zip[start]) start = i;
	}
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
		a[x][y] = a[y][x] = true;
	}
	// Sort
	//for (int i=0; i<n; i++) {
	//	sort(g[i].begin(), g[i].end(), city_cmp);
	//}
	// Solve
	order[0] = start;
	visit[start] = true;
	int depth = 0;
	cout << zip[start];
	for (int i=0; i<n; i++) {
		reach[i] = -1;
		for (int j=depth; j>=0; j--) {
			if (a[i][order[j]]) reach[i] = j;
			break;
		}
	}
	for (int k=1; k<n; k++) {
		int next = -1;
		//cout << "ROUND " << k << endl;
		for (int i=0; i<n; i++) {
			//cout << "Checking city " << i << ":\n";
			if (visit[i]) continue;
			//cout << "Was not visited!\n";
			if (reach[i] < 0) continue;
			//cout << "Can be reached from " << reach[i] << " (" << order[reach[i]] << ")\n";
			dfs_id++;
			dfs(i);
			for (int j=0; j<=reach[i]; j++) dfs(order[j]);
			bool possible = true;
			for (int j=0; j<n; j++) {
				if (!visit[j] && dfs_inx[j] != dfs_id) {
					//cout << "Node " << j << " failed DFS " << dfs_inx[j] << " != " << dfs_id << "\n";
					possible = false;
					break;
				}
			}
			if (!possible) continue;
			//cout << "DFS works\n";
			if (next < 0 || zip[i] < zip[next]) {
				next = i;
			}
		}
		assert(next >= 0);
		depth = reach[next] + 1;
		order[depth] = next;
		visit[next] = true;
		cout << zip[next];
		for (int i=0; i<n; i++) {
			reach[i] = -1;
			for (int j=depth; j>=0; j--) {
				if (a[i][order[j]]) {
					reach[i] = j;
					break;
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int casenum=1; casenum <= t; casenum++) {
		cout << "Case #" << casenum << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}