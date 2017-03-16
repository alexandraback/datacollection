#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX_N 1005

using namespace std;

typedef unsigned long long ull;

vector<int> adjList[MAX_N];
int cache[MAX_N][MAX_N];

int num_paths(int start, int end) {
	if (start == end) return 1;
	else if (cache[start][end] != -1) return cache[start][end];
	else {
		int res = 0;
		for (int i = 0; i < adjList[start].size(); i++) {
			res += num_paths(adjList[start][i], end);
		}
		return cache[start][end] = res;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int rayge = 1; rayge <= T; rayge++) {
		for (int i = 0; i < MAX_N; i++) adjList[i].clear();
		for (int i = 0; i < MAX_N; i++)
			for (int j = 0; j < MAX_N; j++) cache[i][j] = -1;
		printf("Case #%d: ", rayge);
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; j++) {
				int k;
				scanf("%d", &k);
				adjList[i].push_back(k);
			}
		}

		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				if (num_paths(start, end) > 1) {
					printf("Yes\n");
					goto nxt;
				}
			}
		}

		printf("No\n");

		nxt:;
	}
}
