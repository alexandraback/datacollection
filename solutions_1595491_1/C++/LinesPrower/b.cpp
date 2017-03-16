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

#define inf 1000000

bool f[31][2];
bool g[31][2][11];

void init()
{
	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 10; j++)
			for (int k = 0; k <= 10; k++)
			{
				int mi = min(i, min(j, k));
				int mx = max(i, max(j, k));
				if (mx - mi > 2) continue;
				int sc = i + j + k;
				bool surp = mx - mi == 2;
				f[sc][surp] = true;
				for (int t = 0; t <= mx; t++) g[sc][surp][t] = true;
			}
}

int n, s, p;
int a[105];
int dp[105][105];

void solvecase()
{
	scanf("%d%d%d", &n, &s, &p);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = -inf;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			if (dp[i][j] != -inf)
			{
				// surprising
				if (f[a[i]][1]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + g[a[i]][1][p]);
				// not surprising
				if (f[a[i]][0]) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + g[a[i]][0][p]);
			}
	printf("%d", dp[n][s]);
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

#define problem_letter "B"
//#define fname "test"
//#define fname problem_letter "-small-attempt0"
//#define fname problem_letter "-small-attempt1"
//#define fname problem_letter "-small-attempt2"
#define fname problem_letter "-large"

int main()
{
	freopen(fname ".in", "r", stdin);
	freopen(fname ".out", "w", stdout);
	solve();
	return 0;
}