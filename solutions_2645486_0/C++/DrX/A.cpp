#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>

using namespace std;

int d[11][10];
int v[11], n;
int E, R;

int DFS (int x, int y) {
	if (x == n + 1) return 0;
	if (d[x][y] != -1) return d[x][y];
	int i, j, k;
	int ans = -1;
	for (k = 0; k <= y; ++k)
		ans = max(ans, k * v[x] + DFS(x+1, min(y - k + R, E)));
	return d[x][y] = ans;
}

int main () {
	int i, j, k, T, ca;
	scanf ("%d", &T);
	for (ca = 1; ca <= T; ++ca) {
		memset (d, -1, sizeof (d));
		scanf ("%d%d%d", &E, &R, &n);
		for (i = 1; i <= n; ++i) scanf ("%d", &v[i]);
		printf ("Case #%d: %d\n", ca, DFS(1, E));
	}
	return 0;
}
