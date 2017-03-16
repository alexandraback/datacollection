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

int r, c, w;

bool read() {
	if (scanf("%d %d %d", &r, &c, &w) != 3)
		return false;
	return true;
}

void solve() {
	int res = 0;
	if (w == c) {
		res = r - 1 + w;
	} else if (w * 2 > c) {
		res = r + w;
	} else {
		res = r * (c / w) + (w - (c % w == 0));
	}
	printf("%d\n", res);
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

	forn(t, T) {
		assert(read());
		printf("Case #%d: ", t + 1);
		solve();
	}
	
	return 0;
}
