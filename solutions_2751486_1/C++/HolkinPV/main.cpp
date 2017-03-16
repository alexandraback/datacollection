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
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
typedef pair<ld, ld> ptd;

const int INF = INT_MAX / 2;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int N = 1000 * 1000 + 13;

char buf[N];
int n;
string s;

inline bool read()
{
	if (scanf("%s%d", buf, &n) != 2)
		return false;
		
	s = string(buf);
	
	return true;
}

inline bool vowel(const char& c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

inline bool cons(const char& c)
{
	return !vowel(c);
}

int sum[N];

inline int getSum(const int& lf, const int& rg)
{
	return sum[rg] - (lf == 0? 0: sum[lf - 1]);
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);

	forn(i, sz(s))
		sum[i] = (i == 0? 0: sum[i - 1]) + cons(s[i]);
	
	li ans = 0;
	
	int j = 0;	
	
	forn(i, sz(s))
	{
		j = max(j, i);	

		while(j + n - 1 <= sz(s) && getSum(j, j + n - 1) != n)	
			j++;
			
		if (j + n - 1 > sz(s))
			break;
			
		li val = sz(s) - (j + n - 1);
		ans += val;
	}
	
	printf("%I64d\n", ans);
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
