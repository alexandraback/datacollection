#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <time.h>

#define M_PI           3.14159265358979323846

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "1"

#pragma comment(linker, "/STACK:56777216")

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int Dfs(const vi& g, vi& depth, int curD, int from, vi& run, int runId) {
	depth[from] = curD;
	run[from] = runId;

	if (run[g[from]] > 0 && run[g[from]] != runId) {
		return 0;
	}

	if (depth[g[from]] != -1) {
		return curD - depth[g[from]] + 1;
	}
	return Dfs(g, depth, curD + 1, g[from], run, runId);
}

int Cicle(const vi& g) {
	int res = 1;

	int n = g.size();
	vi depth(n, -1);
	vi run(n, -1);

	for (int i = 0; i < n; ++i) {
		if (depth[i] != -1)
			continue;
		res = max(res, Dfs(g, depth, 0, i, run, i));
	}
	return res;
}

int GetDepth(const vvi& g, vb& visited, int from, int curD) {
	visited[from] = true;
	int res = curD;
	for (auto to : g[from]) {
		if (!visited[to]) {
			res = max(res, GetDepth(g, visited, to, curD + 1));
		}
	}
	return res;
}

int GetSumMax(const vvi& reversed, int from, int to) {
	int res1 = 0;

	vb visited(reversed.size(), false);
	visited[to] = true;
	visited[from] = true;
	vb visited1 = visited;

	int d = GetDepth(reversed, visited, from, 0);
	int d1 = GetDepth(reversed, visited1, to, 0);
	return d + d1;
}

int main() {
	freopen(PROBLEM_ID".in", "r", stdin);
	freopen(PROBLEM_ID".out", "w", stdout);
	// getline(cin, name)
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		vvi reversed(n, vi());
		vi g(n);
		for (int i = 0; i < n; ++i) {
			cin >> g[i];
			g[i]--;

			reversed[g[i]].push_back(i);
		}

		int maxC = Cicle(g);
		for (int i = 0; i < g.size(); ++i) {
			int to = g[i];
			if (g[to] == i) {
				maxC = max(maxC, 2 + GetSumMax(reversed, i, to));
			}
		}
		cout << "Case #" << i + 1 << ": " << maxC << endl;
	}

	return 0;
}