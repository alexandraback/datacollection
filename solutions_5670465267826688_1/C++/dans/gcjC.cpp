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

const int N = 1000 * 1000 + 5;
int l;
li x;
char s[N];

int geti(char c) {
	return string("ijk").find(c) + 2;
}

bool read() {
	if (scanf("%d %I64d", &l, &x) != 2)
		return false;
	scanf("%s", s);
	return true;
}

int sign(int a) {
	return a < 0 ? -1 : +1;
}

int mul(int i, int j) {
	int s = sign(i) * sign(j);
	i = abs(i); j = abs(j);

	int res = 0;

	if (i == j)
		res = (i == 1) ? 1 : -1;
	else
	if (i == 1 || j == 1)
		res = max(i, j);
	else {
		if (i > j)
			swap(i, j), s *= -1;

		if (i == 2 && j == 3)
			res = 4;

		if (i == 3 && j == 4)
			res = 2;

		if (i == 2 && j == 4)
			res = -3;
	}

	return res * s;
}

void solve() {
	int bl = 1;

	forn(i, l)
		bl = mul(bl, geti(s[i]));

	int cur = 1;
	forn(i, x % 4)
		cur = mul(cur, bl);

	if (cur != -1) {
		puts("NO");
		return;
	}

	int need[2], npos = 0;
	need[0] = 2;
	need[1] = 4;

	cur = 1;

	forn(i, min(16LL, x) * l) {
		if (npos == 2)
			break;
		
		cur = mul(cur, geti(s[i % l]));

		if (cur == need[npos])
			npos++;
	}

	if (npos < 2) {
		puts("NO");
	} else {
		puts("YES");
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
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
	
	return 0;
}
