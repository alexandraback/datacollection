#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef long long llong;

#define mp make_pair
#define lowbit(x) ((x) & (-(x)))
#define pf(x) ((x) * (x))
#define two(x) (1 << (x))
#define twoL(x) ((llong) 1 << (x))
#define clr(x, c) memset(x, c, sizeof(x))

void ch_max(int &x, int y) {if (x < y) x = y;}
void ch_min(int &x, int y) {if (x > y) x = y;}

const double pi = acos(-1.0);
const double eps = 1e-9;

const int N = 105;
int n, S, p, a[N];
int d[N][N];

void update(int &x, int y) {
	if (x == -1 || x < y) x = y;
}
int main() {
	freopen("GCJ\\B-large.in", "r", stdin);
//	freopen("GCJ\\in.txt", "r", stdin);
	freopen("GCJ\\out.txt", "w", stdout);
	
	int i, j, k, t, nc = 0;

	scanf("%d", &t);

	while (t--) {
		scanf("%d%d%d", &n, &S, &p);
		for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
		clr(d, -1);
		d[0][0] = 0;
		for (i = 1; i <= n; ++i) {
			int t0 = 0, t1 = 0;
			int w = a[i] / 3;
			if (a[i] % 3) w++;
			
			if (w >= p) t0 = 1;
			if (a[i] > 0 && a[i] % 3 != 1 && w + 1 >= p || a[i] > 3 && a[i] % 3 == 1 && w >= p) t1++;
			for (j = 0; j < i; ++j) {
				if (d[i - 1][j] == -1) continue;
				if (t0) update(d[i][j], d[i - 1][j] + 1);
				else update(d[i][j], d[i - 1][j]);
				if (t1) update(d[i][j + 1], d[i - 1][j] + 1);
				else if (a[i] > 1) update(d[i][j + 1], d[i - 1][j]);
			}
		}
		int ans = d[n][S];
		printf("Case #%d: %d\n", ++nc, ans);
	}
	return 0;
}