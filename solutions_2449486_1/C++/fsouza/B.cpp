#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

#define MAXM 200
#define MAXN 200

typedef long long lint;

using namespace std;

int table[MAXM][MAXN], r[MAXN], c[MAXM];

int main(int argc, char ** argv)
{
	int ntest;

	scanf("%d", &ntest);
	
	for (int t = 0; t < ntest; t++) {
		int n, m;

		scanf("%d %d", &n, &m);

		for (int y = 0; y < n; y++)
			r[y] = 0;
		for (int x = 0; x < m; x++)
			c[x] = 0;
		
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++) {
				scanf("%d", &table[y][x]);
				r[y] = max(r[y], table[y][x]);
				c[x] = max(c[x], table[y][x]);
			}
		
		int ok = 1;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				if (table[y][x] != min(r[y], c[x]))
					ok = 0;
		
		printf("Case #%d: %s\n", t+1, ok ? "YES" : "NO");
	}

	return 0;
}
