#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f

using namespace std;

const double PI = acos(-1.0);
typedef pair<int, int> pii;
typedef long long ll;

int matrix[7][7];
int n; ll m; 
int ways[7];
bool vis[7];
int dfs (int u) {
	if (u == n-1) return ways[u] = 1;
	vis[u] = true;

	int x = 0;
	for (int v = 0; v < n; v++) {
		if (matrix[u][v] and !vis[v]) dfs (v);
		if (matrix[u][v] and u != v) x += ways[v];
	}
	return ways[u] = x;
}

int main (void) {
	int t; scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++) {
		scanf("%d %lld", &n, &m);

		int limite = 1 << ((n-1) * (n-1));
		bool have_ans = false;
//		printf("%d\n", limite);
		for (int mask = 0; mask < limite; mask++) {
			int k = 0;
			memset (matrix, false, sizeof matrix);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j) continue ;
					if ((1 << k) & mask) matrix[i][j] = 1;
					k++;
					if (k == ((n-1) * (n-1))) break;
				}
			}
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < n; j++) printf("%d", matrix[i][j]);
//				cout << endl;
//			}
			memset (vis, false, sizeof vis);
			memset (ways, 0, sizeof ways);

			int way = dfs (0);
			if (way == m) {
				have_ans = true;
				break;
			}
		}
		if (!have_ans) {
			printf("Case #%d: IMPOSSIBLE\n", cases);
		} else {
			printf("Case #%d: POSSIBLE\n", cases);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) printf("%d", matrix[i][j]);
				printf("\n");
			}
		}

	}
	return 0;
}
