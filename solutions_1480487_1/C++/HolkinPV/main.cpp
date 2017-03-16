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
const ld EPS = 1e-15;
const ld PI = 3.1415926535897932384626433832795;

const int N = 200 + 3;

int n;
int a[N], sum;
ld maxv;

inline bool read()
{
	if (scanf("%d", &n) != 1)
		return false;

	sum = 0;
	maxv = ld(-1e9);

	forn(i, n)
	{
		assert(scanf("%d", &a[i]) == 1);
		sum += a[i];
		maxv = max(maxv, ld(a[i]));
	}

	return true;
}

ld ans[N];

inline bool check(int i, ld mid)
{
    ld cur = ld(0.0);

    ld need = a[i] + sum * mid;

    forn(j, n)
    {
    	ld val = (need - ld(a[j])) / ld(sum);

    	if (val > EPS)
    		cur += val;
    }

    return (cur > ld(1.0) - EPS);
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);

	assert(sum > 0);

	forn(i, n)
	{
    	ld lf = ld(0.0), rg = ld(1.0);

    	forn(it, 600)
    	{
    		ld mid = (lf + rg) / ld(2.0);

    		if (check(i, mid))	
	  			rg = mid;
    		else
    			lf = mid;
    	}

    	assert(check(i, rg));

    	ans[i] = rg;
	}

	cout << setprecision(10) << fixed;

	forn(i, n)
		cout << ans[i] * ld(100.0) << " ";

	cout << endl;
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
		solve(test);
	}

    return 0;
}
