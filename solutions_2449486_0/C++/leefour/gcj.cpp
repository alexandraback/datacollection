#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long int64;
const double pi = acos (-1.0);
const double eps = 1.0e-10;

void solve()
{
	bool res = true;
	int n, m, g[110][110];
	int left[110][110], right[110][110], up[110][110], down[110][110];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &g[i][j]);
			if (i == 0)
				up[i][j] = 0;
			else
				up[i][j] = max(up[i - 1][j], g[i - 1][j]);
			if (j == 0)
				left[i][j] = 0;
			else
				left[i][j] = max(left[i][j - 1], g[i][j - 1]);
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i == n - 1)
				down[i][j] = 0;
			else
				down[i][j] = max(down[i + 1][j], g[i + 1][j]);
			if (j == m - 1)
				right[i][j] = 0;
			else
				right[i][j] = max(right[i][j + 1], g[i][j + 1]);
			if (!(left[i][j] <= g[i][j] && right[i][j] <= g[i][j]) && !(up[i][j] <= g[i][j] && down[i][j] <= g[i][j])) {
				res = false;
				goto out;
			}
		}
	}
out:
	if (res)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int icase = 1; icase <= ncase; ++icase) {
		printf("Case #%d: ", icase);
		solve();
	}
}
