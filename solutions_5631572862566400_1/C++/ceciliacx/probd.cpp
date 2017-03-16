#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int getMaxCycle(int* adj, int start) {
	bool visited[1001] = { 0 };
	int cur = adj[start];
	visited[start] = true;
	int num = 1;
	while (!visited[cur]) {
		
		visited[cur] = true;
		cur = adj[cur];
		++num;
	}
	return cur == start ? num : 0;
}

// get root -> a pair, res[0] depth, res[1] root
void getMaxDepth(int*adj, int node, int& depth, int& cur) {
	cur = node;
	depth = 0;
	bool visited[1001] = { 0 };
	while (!visited[cur]) {
		visited[cur] = true;
		cur = adj[cur];
		++depth;
	}
	--depth;
	cur = adj[adj[cur]] == cur ? cur : 0;
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int adj[1001];

	int N;
	cin >> N;
	for (int prob = 1; prob <= N; prob++) {
		int M;
		cin >> M;
		for (int i = 1; i <= M; ++i) {
			cin >> adj[i];
		}
		// try max cycle
		int maxCycle = 0;
		for (int i = 1; i <= M; ++i) {
			int cycle = getMaxCycle(adj, i);
			maxCycle = cycle > maxCycle ? cycle : maxCycle;
		}
		// try all pairs
		int depth[1001] = { 0 };
		for (int i = 1; i <= M; ++i) {
			int d, k;
			getMaxDepth(adj, i, d, k);
			if (k && d > depth[k]) depth[k] = d;
		}
		int max = 0;
		for (int i = 1; i <= M; ++i) {
			max += depth[i];
		}

		cout << "Case #" << prob << ": " << (maxCycle > max ? maxCycle : max) << endl;
	}
	return 0;
}
