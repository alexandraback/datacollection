#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAXN = 1000;

int graph[MAXN][MAXN];
bitset<MAXN> visited;
bitset<MAXN> root;
int n;

bool diamond_free(int v) {
	visited.set(v);
	bool result = true;
	for (int i = 0; i < n && result; ++i) {
		if (graph[v][i]) {
			if (visited[i])
				return false;
			result = diamond_free(i);
		}
	}
	return result;
}

void solveCase(int caseNum) {
	memset(graph, 0, MAXN * MAXN);
	root.set();

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int k;
			cin >> k;
			graph[i][--k] = 1;
			root.reset(k);
		}
	}

	bool result = true;
	for (int i = 0; i < n && result; ++i) {
		if (!root[i])
			continue;
		visited.reset();
		result = diamond_free(i);
	}

	cout << "Case #" << caseNum << ": "
			<< (result ? "No" : "Yes") << endl;
}

int main() {
	int t;

	cin >> t;
	for (int i = 1; i <= t; ++i)
		solveCase(i);

	return EXIT_SUCCESS;
}
