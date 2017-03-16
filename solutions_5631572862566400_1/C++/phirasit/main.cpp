#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(int);

int main() {
	int t;
	cin >> t;
	for(int case_id = 1;case_id <= t;case_id++) {
		solve(case_id);
	}
	return 0;
}

const int N = 1010;

vector<int> inv[N];
int bff[N], pass[N];
int n;

int ans, ans1;

int dfs_length(int u) {
	int res = 0;
	for(int v : inv[u]) {
		if(v == bff[u]) continue;
		res = max(res, dfs_length(v));
	}
	return res + 1;
}
int dfs_circle(int u, int depth) {
	if(pass[u]) return depth - pass[u];
	pass[u] = depth;
	int r = dfs_circle(bff[u], depth + 1);
	pass[u] = 0;
	return r;
}
void solve(int case_id) {
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> bff[i];
		inv[i].clear();
		pass[i] = 0;
	}

	ans = ans1 = 0;
	for(int i = 1;i <= n;i++) {
		ans = max(ans, dfs_circle(i, 1));
	}

	for(int i = 1;i <= n;i++) {
		inv[bff[i]].push_back(i);
	}
	for(int i = 1;i <= n;i++) {
		if(bff[bff[i]] == i and i < bff[i]) {
			ans1 += dfs_length(i) + dfs_length(bff[i]);
		}
	}
	ans = max(ans, ans1);
	cout << "Case #" << case_id << ": " << ans << endl;
	cerr << case_id << endl;
}