#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#undef HOME

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

int n, m, k, sq;
char matr[32][32];
bool vis[32][32];

const int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void DFS(int u, int v) {
	vis[u][v] = true;
	for (int d = 0; d<4; d++) {
		int nu = u + dir[d][0];
		int nv = v + dir[d][1];
		if (nu < 0 || nv < 0 || nu >= n || nv >= m)
			continue;
		if (matr[nu][nv] == 'X')
			continue;
		if (vis[nu][nv])
			continue;
		DFS(nu, nv);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d%d", &n, &m, &k);
		sq = n * m;

		int ans = 1000000000;
		for (int s = 0; s < (1<<sq); s++) {
			int idx = 0;
			int ccnt = 0;
			for (int i = 0; i<n; i++) {
				for (int j = 0; j<m; j++) {
					if (s & (1 << idx++)) {
						matr[i][j] = 'X';
						ccnt++;
					}
					else
						matr[i][j] = '.';
				}
				matr[i][m] = 0;
				Ef("%s\n", matr[i]);
			}
			Ef("\n");

			memset(vis, 0, sizeof(vis));
			for (int i = 0; i<n; i++)
				for (int j = 0; j<m; j++)
					if ((i == 0 || j == 0 || i == n-1 || j == m-1) && matr[i][j] == '.')
						DFS(i, j);
			
			int tres = sq;
			for (int i = 0; i<n; i++)
				for (int j = 0; j<m; j++)
					if (vis[i][j]) {
						matr[i][j] = '*';
						tres--;
					}
		
			for (int i = 0; i<n; i++)
				Ef("%s\n", matr[i]);
			Ef("\n");

			if (tres >= k)
				if (ans > ccnt)
					ans = ccnt;
		}

		printf("Case #%d: %d\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}

