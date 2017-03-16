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

typedef unsigned int uint;
//typedef long long numt;
//typedef __int128 numt;


int dfs(vector<int> g[], int p, int bad = -1) {
	int r = 1;
	for (int q : g[p]) if (q != bad) {
		r = max(r, dfs(g, q) + 1);
	}
	return r;
}

void solvecase()
{
	int n;
	int g[1000];
	vector<int> g2[1000];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> g[i];
		--g[i];
		g2[g[i]].push_back(i);
	}
	// longest cycle
	int longest = 0;
	int r[1000];
	CLR(r, -1);
	for (int i = 0; i < n; ++i) if (r[i] == -1) {
		int k = i * n;
		int j = i;
		while (r[j] == -1) {
			r[j] = k++;
			j = g[j];
		}
		if (r[j] >= i * n)
			longest = max(longest, k - r[j]);
	}
	int c = 0;
	for (int i = 0; i < n; ++i)
		if (g[g[i]] == i && g[i] < i) {
			c += dfs(g2, i, g[i]) + dfs(g2, g[i], i);
		}
	printf("%d", max(c, longest));
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

#define dir "C:/Users/dmarin3/Downloads/"
#define problem_letter "C"
//#define fname "test"
#define fname dir problem_letter "-small-attempt0"
//#define fname dir problem_letter "-small-attempt1"
//#define fname dir problem_letter "-small-attempt2"
//#define fname dir problem_letter "-large"

int main()
{
	freopen(fname ".in", "r", stdin);
	freopen(fname ".out", "w", stdout);
	solve();
	return 0;
}
