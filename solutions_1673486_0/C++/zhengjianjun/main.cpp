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

inline void ch_max(int &x, int y) {if (x < y) x = y;}
inline void ch_min(int &x, int y) {if (x > y) x = y;}

const double pi = acos(-1.0);
const double eps = 1e-9;


const int N = 100005;
int n, m;
double a[N];

double solve1() {
	int i, j, k;
	double tmp = 1;
	for (i = 1; i <= n; ++i) tmp *= a[i];
	double ret = tmp * (m - n + 1) + (1 - tmp) * (m - n + 1 + m + 1);
	return ret;
}
double solve2() {
	int i, j, k;
	double tmp = 1, ret = 1e9;
	for (i = 0; i < n; ++i) {
		tmp *= a[i];
		//double t0 = tmp * (m - n + 3) + (1 - tmp) * (m - n + 3 + m + 1);
		double t0 = tmp * (m - n + 1 + 2 * (n - i) ) + (1 - tmp) * (m - n + 1 + m + 1 + 2 * (n - i));
		if (ret > t0) ret = t0;
	}
	return ret;
}
double solve3() {
	return 1 + m + 1;
}
int main() {
	//freopen("GCJ\\in.txt", "r", stdin);
	freopen("GCJ\\A-small-attempt0.in", "r", stdin);
	freopen("GCJ\\out.txt", "w", stdout);
	int i, j, k, t, nc = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		a[0] = 1;
		for (i = 1; i <= n; ++i) {
			scanf("%lf", &a[i]);
		}
		double ans = 1e9, tmp;
		tmp = solve1();
		if (ans > tmp) ans = tmp;
		tmp = solve2();
		if (ans > tmp) ans = tmp;
		tmp = solve3();
		if (ans > tmp) ans = tmp;
		printf("Case #%d: %.7lf\n", ++nc, ans);
	}
	return 0;
}