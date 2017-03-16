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

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)

using namespace std;

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

int a, b, k;

bool read() {
	if (!(cin >> a >> b >> k))
		return false;
	return true;
}

void solve() {
	int res = 0;
	forn(i, a)
		forn(j, b)
			if ((i & j) < k)
				++res;
	cout << res;
}

int main() {
#ifdef dans
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifdef TASK_NAME
	freopen(TASK_NAME ".in", "r", stdin);
	freopen(TASK_NAME ".out", "w", stdout);
#endif
	int t, test = 0;
	cin >> t;
	while (read()) {
		test++;
		cout << "Case #" << test << ": ";
		solve();
		cout << endl;
	}
	
	return 0;
}
