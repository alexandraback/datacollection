#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void Open() {
	freopen ("P1.in", "r", stdin);
	freopen ("P1.out", "w", stdout);
}

void Close() {
	fclose(stdin);
	fclose(stdout);
}

vector<vector<int>> edges;
vector<bool> visited;

bool CheckOnePoint(int k) {
	visited[k] = true;
	for (int i = 0; i < edges[k].size(); i++) {
		int j = edges[k][i];
		if (visited[j]) return true;
		if (CheckOnePoint(j)) return true;
	}
	return false;
}

bool Work() {
	int N;
	scanf ("%d", &N);
	edges.clear();
	edges.resize(N);
	for (int i = 0; i < N; i++) {
		int M;
		edges[i].clear();
		scanf ("%d", &M);
		for (int j = 0; j < M; j++) {
			int tmp;
			scanf ("%d", &tmp);
			edges[i].push_back(tmp - 1);
		}
	}

	for (int i = 0; i < N; i++) {
		visited.clear();
		visited.resize(N, false);

		if (CheckOnePoint(i)) return true;
	}

	return false;
}

int main() {
	int T;
	Open();
	scanf ("%d", &T);
	for (int i = 0; i < T; i++) {
		bool ans = Work();
		printf ("Case #%d: ", i + 1);
		if (ans) printf ("Yes\n");
		else
			printf ("No\n");
	}
	Close();
	return 0;
}