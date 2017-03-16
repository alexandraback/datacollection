#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <climits>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forn1(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define fs first
#define ft first
#define sc second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned char byte;
typedef vector<vector<int> > matrix;

const int INF = INT_MAX / 2;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int N = 20 + 1;

int n;
int a[N];

int sza, szb, suma, sumb;
int za[N], zb[N];

inline bool read()
{
	if (scanf("%d", &n) != 1)
		return false;

	forn(i, n)
		assert(scanf("%d", &a[i]) == 1);

	return true;
}

vector<int> ansa, ansb;

bool ok;

void solve(int idx)
{
	if (ok)
		return;

	if (suma == sumb && suma > 0)
	{
		forn(i, sza)
			ansa.pb(za[i]);

		forn(i, szb)
			ansb.pb(zb[i]);

		ok = true;

		return;
	}

	if (idx == n)
		return;

	{
		suma += a[idx];
		za[sza++] = a[idx];

		solve(idx + 1);

		suma -= a[idx];
		sza--;
	}

	{
		sumb += a[idx];
		zb[szb++] = a[idx];

		solve(idx + 1);

		sumb -= a[idx];
		szb--;
	}

	solve(idx + 1);
}

inline void solveTest(int test)
{
	printf("Case #%d:\n", test + 1);

	sza = 0, szb = 0;
	suma = 0, sumb = 0;
	ansa.clear(); ansb.clear();
	ok = false;

	solve(0);

	if (ansa.empty())
		puts("Impossible");
	else
	{
		forn(i, sz(ansa))
			cout << ansa[i] << " ";

		cout << endl;

		forn(i, sz(ansb))
			cout << ansb[i] << " ";

		cout << endl;
	}
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int testCnt;

    assert(scanf("%d\n", &testCnt) == 1);

    forn(test, testCnt)
    {
    	assert(read());
		solveTest(test);
	}

    return 0;
}
