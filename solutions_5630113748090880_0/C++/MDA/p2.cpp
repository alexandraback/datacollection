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



void solvecase()
{
	int n;
	cin >> n;
	/*vector<vector<int> > lists(n, vector<int>(n, 0));
	for (int i = 0; i+1 < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> lists[i][j];
	}
	int k = n - 1;
	int mis = -1;
	for (int r = n - 1; r >= 0; --r) {
		int best = 0;
		for (int i = 0; i < k; ++i) {
			best = max(best, lists[i][r]);
		}
		for (int i = 0; i < k; ++i) {
			int cnt = 0;
			if (lists[i][r] == best) {
				--k;
				lists[k].swap(lists[i]);
				++cnt;
			}
			if (cnt < 2) {
				mis = r;
			}
		}
	}*/
	int c[5000];
	CLR(c, 0);
	for (int i = 0; i < n * (2*n - 1); ++i) {
		int a; cin >> a; c[a]++;
	}
	vector<int> res;
	for (int i = 0; i < 3000; ++i) {
		if (c[i] % 2 == 1)
			res.push_back(i);
	}
	sort(ALL(res));
	cout << res[0];
	for (int i = 1; i < n; ++i)
		printf(" %d", res[i]);
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
#define problem_letter "B"
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
