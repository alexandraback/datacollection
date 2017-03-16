#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

const int N = 20;
int n;
pt a[N];

inline bool read()
{
	int cnt;
	if (scanf ("%d", &cnt) != 1)
		return false;

	n = 0;
	forn (i, cnt)
	{
		int start, c, t;
		assert(scanf ("%d%d%d", &start, &c, &t) == 3);

		forn (j, c)
		{
			a[n++] = mp(start, t);
			t++;
		}
	}

	assert(n <= 2);

	return true;
}

inline void solve(int test)
{
	printf ("Case #%d: ", test + 1);

	if (n < 2)
	{
		puts("0");
		return;
	}

	if (a[0].sc == a[1].sc)
	{
		puts("0");
		return;
	}

	if (a[0].ft > a[1].ft)
		swap(a[0], a[1]);

	if (a[0].sc < a[1].sc) //fist is faster
	{
		ld v0 = ld(360) / ld(a[0].sc), v1 = ld(360) / ld(a[1].sc);
		ld dv = v0 - v1;
		ld t1 = (a[1].ft - a[0].ft) / dv;
		ld t2 = ld(360) / dv;

		if (a[0].ft + t1 * v0 + t2 * v1 > 360 + EPS)
			puts("0");
		else
			puts("1");
	}
	else //second is faster
	{
		ld v0 = ld(360) / ld(a[0].sc), v1 = ld(360) / ld(a[1].sc);
		ld dv = v1 - v0;
		ld t = ld(360 - (a[1].ft - a[0].ft)) / dv;

		if (a[0].ft + t * v0 > 360 + EPS)
			puts("0");
		else
			puts("1");
	}
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	int testCnt;
	assert(scanf ("%d", &testCnt) == 1);

	forn (test, testCnt)
	{
		assert(read());
		solve(test);
	}

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}
