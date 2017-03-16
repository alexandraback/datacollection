#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

typedef long long ll;

const double eps = 1E-9;

vector<int> used, pr;
vector<vector<int>> g;

int ccolor = 1;

void dfs1(int u) {
	used[u] = ccolor;
	for(int i = 0; i < g[u].size(); ++i) {
		int to = g[u][i];
		if(used[to] != ccolor) {
			dfs1(to);
			pr[to] = u;
		}
	}
}

bool dfs2(int u) {
	used[u] = ccolor;
	bool result = false;
	for(int i = 0; i < g[u].size(); ++i) {
		int to = g[u][i];
		if(pr[to] != u)	return true;
		if(used[to] == ccolor)	continue;
		result |= dfs2(to);
	}
	return result;
}

bool s1(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.first < p2.first;
}

int main(int argc, char** argv) {
    
    ios::sync_with_stdio(false);
	ifstream cin("A-small-practice.in");
	ofstream cout("A-smalAl-practice.out");

	int t, n, m;
	cin >> t;

	pr.resize(1005);
	used.resize(1005);
	for(int i = 0; i < t; ++i) {
		cin >> n;
		g.assign(n, vector<int>());
		for(int j = 0; j < n; ++j) {
			cin >> m;
			for(int k = 0; k < m; ++k) {
				int u;
				cin >> u;
				g[u - 1].push_back(j);
			}
		}

		bool f = true;
		cout << "Case #" << i + 1 << ": ";
		for(int j = 0; j < n && f; ++j) {
			fill(pr.begin(), pr.end(), -1);
			dfs1(j);
			++ccolor;
			if(dfs2(j)) {
				cout << "Yes" << endl;
				f = false;
			}
			++ccolor;
		}
		if(f)	cout << "No" << endl;
	}
    return 0;
}