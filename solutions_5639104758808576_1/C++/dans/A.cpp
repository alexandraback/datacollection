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

int n;
char s[N];

bool read() {
	if (scanf("%d", &n) != 1)
		return false;	

	scanf("%s", s);
	forn(i, n + 1)
		s[i] -= '0';
	return true;
}

void solve() {
	int res = 0;
	int stand = 0;
	forn(i, n + 1) {
		if (s[i] > 0) {
			int need = max(0, i - stand);
			stand += need;
			res += need;

			stand += s[i];
		}
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

	int test = 1;

	while (read()) {
		printf("Case #%d: ", test++);
		solve();
	}

	assert(T == test - 1);
	
	return 0;
}
