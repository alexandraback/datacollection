#pragma comment(linker, "/STACK:32000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdarg.h>
#include <memory.h>
#include <string.h>

using namespace std;

const double pi = 3.1415926535897932384626433832795;
#define ALL(x) x.begin(), x.end()
#define LL long long
#define MP make_pair
#define PB push_back
#define CLR(a,b) memset(a, b, sizeof(a))
template<class T> inline T Sqr(const T &x) { return x*x; }
template<class T> inline T Abs(const T &x) { return x >= 0 ? x : -x; }
#define fo(i, n) for (int i = 0; i < (n); i++)
#define foz(i, a) for (int i = 0; i < (a).size(); i++)

void init()
{

}

#define maxn 33
#define eps 1e-12

int h, w, d;
char a[maxn][maxn];

inline bool eq(double x, double y)
{
	return Abs(x - y) < eps;
}

inline double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(Sqr(x1 - x2) + Sqr(y1 - y2));
}

template<class T> T gcd(T x, T y) { return y == 0 ? x : gcd(y, x % y); }

pair<int, int> normalize(int x, int y)
{
	int g = gcd(Abs(x), Abs(y));
	return make_pair(x / g, y / g);
}

void solvecase()
{
	int x0, y0;	
	scanf("%d%d%d", &h, &w, &d);
	for (int i = 0; i < h; i++) scanf("%s", a[i]);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (a[i][j] == 'X')
			{
				x0 = 2 * j - 1;
				y0 = 2 * i - 1;
			}

	h = 2 * (h - 2);
	w = 2 * (w - 2);
	set<pair<int, int> > res;
	for (int i = -50; i <= 50; i++)
		for (int j = -50; j <= 50; j++) if (i != 0 || j != 0)
		{
			int x = i * w + (i % 2 == 0 ? x0 : w - x0);
			int y = j * h + (j % 2 == 0 ? y0 : h - y0);
			if (dist(x0, y0, x, y) < 2 * d + eps)
			{
				res.insert(normalize(x - x0, y - y0));
			}
		}

	printf("%d", res.size());
}

void solve() {
	init();
	int n_tests;
	scanf("%d", &n_tests);
	for (int i = 1; i <= n_tests; i++)
	{
		printf("Case #%d: ", i);
		solvecase();
		printf("\n");
	}
}

#define problem_letter "D"
//#define fname "test"
#define fname problem_letter "-small-attempt0"
//#define fname problem_letter "-small-attempt1"
//#define fname problem_letter "-small-attempt2"
//#define fname problem_letter "-large"

int main()
{
	freopen(fname ".in", "r", stdin);
	freopen(fname ".out", "w", stdout);
	solve();
	return 0;
}