#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

const int maxN = 1042;

int graph[maxN][maxN];
int M[maxN];
bool used[maxN];

bool dfs (int vertix) {
	used[vertix] = true;
	for (int i = 0; i < M[vertix]; ++i) {
		if (used[graph[vertix][i]])
			return true;
		else if (dfs (graph[vertix][i]))
			return true;
	}
	return false;
}


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> M[j];
			for (int k = 0; k < M[j]; ++k) {
				cin >> graph[j][k];
				--graph[j][k];
			}
		}
		cout << "Case #" << i + 1 << ": ";
		for (int j = 0; j < N; ++j) {
			memset (used, false, N);
			if (dfs (j)) {
				cout << "Yes\n";
				break;
			}
			if (j == N - 1) {
				cout << "No\n";
			}
		}
	}
	return 0;
}

