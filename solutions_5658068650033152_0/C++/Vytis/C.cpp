#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define FILE_IN  "C-small-attempt0.in"
#define FILE_OUT "C-small-attempt0.out"

#define MAXN 40
#define MAXM 1000
#define MAXP 1000

int d[2][MAXN][MAXN][MAXP];

int solve() {
    int n, m, k;
    scanf("%d%d%d\n", &n, &m, &k);
    if (n > m) {
        swap(n, m);
    }
    if (n <= 2) {
        return k;
    }
    fill(d[0][0][0], d[0][MAXN][0], -1);
    for (int i = 1; i < n - 1; ++i) {
        for (int j = i; j < n - 1; ++j) {
            d[0][i][j][j - i + 1 + 2] = j - i + 1;
        }
    }
    int mp = (n + m) * 2;
    int x = 0, xx = 1;
    int r = k;
    for (int z = 2; z < m; ++z, swap(x, xx)) {
        fill(d[xx][0][0], d[xx][MAXN][0], -1);
        for (int i = 1; i < n - 1; ++i) {
            for (int j = i; j < n - 1; ++j) {
                for (int p = 0; p < mp; ++p) {
                    if (d[x][i][j][p] < 0) continue;
                    int pp = p + (j - i + 1);
                    int e = d[x][i][j][p] + pp;
                    if (e < k) {
                        pp += k - e;
                    }
                    r = min(r, pp);
                    if (z >= m - 1) continue;
                    for (int ii = 1; ii <= j; ++ii) {
                        for (int jj = max(ii, i); jj < n - 1; ++jj) {
                            int np = p + 2 + max(i - ii - 1, 0) + max(jj - j - 1, 0);
                            if (np >= mp) continue;
                            d[xx][ii][jj][np] = max(d[xx][ii][jj][np], d[x][i][j][p] + (jj - ii + 1));
                        }
                    }
                }
            }
        }
    }
    return r;
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int r = solve();
		printf("Case #%d: %d\n", i, r);
	}
	return 0;
}
