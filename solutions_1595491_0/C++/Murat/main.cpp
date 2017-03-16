#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <memory.h>
#include <ctype.h>
#include <ctime>

#include <iostream>

#include <string>
#include <complex>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>

//#pragma comment(linker, "/stack:64000000")

using namespace std;

template<typename TYPE> inline TYPE sqr(const TYPE& a) { return (a) * (a); }

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 110;

enum {NO_WAY, WITH_SURPRISE, GOOD};

int check(int t, int p)
{
	bool ws = false;
	for (int i = 0; i <= t; ++i) {
		int nj = min(t - i, i + 3);
		for (int j = i; j <= nj; ++j) {
			int k = t - i - j;
			if (j > k)
				continue;
                       	if (k >= p && k - i < 3) {
                       		if (k - i < 2)
                        		return GOOD;
                        	ws = true;
                        }
		}
	}
	if (ws)
		return WITH_SURPRISE;
	return NO_WAY;
}

int check2(int t, int p)
{
	int a = t / 3;
	int r = t % 3;
	if (r == 0) {
		if (p <= a)
			return GOOD;
		if (a > 0 && p <= a + 1)
			return WITH_SURPRISE;
	} else {
		if (p <= a + 1)
			return GOOD;
		if (r == 2 && p <= a + 2)
			return WITH_SURPRISE;
	}
	return NO_WAY;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tests;
	scanf("%d\n", &tests);
	for1(it, tests) {
		int n, s, p;
		scanf("%d%d%d", &n, &s, &p);
		int good = 0, ws = 0;
		forn(i, n) {
			int t;
			scanf("%d", &t);
                        int r = check(t, p);
                        assert(r == check2(t, p));
                        //printf("%d => %d\n", t, r);
                        if (r == GOOD)
                        	++good;
			else if (r == WITH_SURPRISE)
				++ws;
		}
		printf("Case #%d: %d\n", it, good + min(ws, s));
	}

	return 0;
}
