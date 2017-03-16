#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int N = 1000;

int n, p[N], t[N];

bool f(int k) {
	forn(l, k) {
		int left = l;
		int sz = k - l;
		forn(i, n) {
			left -= (p[i] + sz - 1) / sz - 1;
		}

		if (left >= 0)
			return true;
	}
	return false;
}

bool read() {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &p[i]);
	return true;
}

void solve() {
	int l = 0, r = 1000;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (f(m))
			r = m;
		else
			l = m;
	}

	for (int i = l; i <= r; ++i)
		if (f(i)) {
			printf("%d\n", i);
			return;
		}

	assert(false);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifdef TASK_NAME
	freopen(TASK_NAME ".in", "r", stdin);
	freopen(TASK_NAME ".out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);

	int test = 1;

	while (read()) {
		printf("Case #%d: ", test++);
		solve();
	}

	assert(T == test - 1);
	
	return 0;
}
