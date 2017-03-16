#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
const int N = 1e3 + 10;
int been[N];
vector<int> g[N];
int n;

bool dfs (int u) {
	been[u] = 1;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (been[v] == 2) {
			return true;
		}
		else if (been[v] == 1) {
			cerr << "Exist a cycle!" << endl;
			exit(1);
		}
		else {
			if (dfs(v)) {
				return true;
			}
		}
	}
	been[u] = 2;
	return false;
}

void sol (int test_number) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		g[i].clear();
	}

	for (int u = 0; u < n; ++u) {
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int v;
			cin >> v;
			g[u].push_back(v - 1);
		}
	}	

	cout << "Case #" << test_number + 1 << ": ";
	bool exist_diamond = false;
	for (int u = 0; u < n && !exist_diamond; ++u) {
		for (int i = 0; i < n; ++i) {
			been[i] = 0;
		}
		if (dfs(u)) {
			exist_diamond = true;
		}
	}
	cout << (exist_diamond ? "Yes" : "No") << endl;
}

int main () {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int tests_count;
	cin >> tests_count;

	for (int i = 0; i < tests_count; ++i) {
		sol(i);
	}
	return 0;
}