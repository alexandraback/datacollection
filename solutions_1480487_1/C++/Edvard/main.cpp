#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-13, PI = 3.1415926535897932384626433832795;

const int N = 200 + 3;

int n;
ld sum, a[N];

inline bool read()
{
	if (scanf("%d", &n) != 1)
		return false;
		
	sum = 0;
	
	forn(i, n)
	{
		int x;
		assert(scanf("%d", &x) == 1);
		a[i] = x;
		sum += a[i];
	}
	
	return true;
}

inline bool check(int idx, ld mid)
{
	ld val = a[idx] + mid * sum;
	
	ld curSum = mid;
	
	forn(i, n)
		if (i != idx)
		{
			ld cur = a[i];
			
			//cerr << val << ' ' << cur << ' ';
			
			if (val < cur + EPS)
				continue;
				
			ld dif = val - cur;
			//cerr << dif << ' ' << dif / sum << endl;
			
			curSum += dif / sum;
		}
		
	return curSum + EPS < 1.0;
}

inline void solve(int test)
{
	//cerr << check(0, 0.34) << endl;
	//exit(0);
	
	printf("Case #%d:", test + 1);
	
	forn(i, n)
	{
		ld lf = 0.0, rg = 1.0;
		
		forn(j, 200)
		{
			ld mid = (lf + rg) / 2.0;
			
			if (!check(i, mid))
				rg = mid;
			else
				lf = mid;
		}
		
		printf(" %.10lf", double(rg * 100));
	}
	
	puts("");
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    int testCount;
    cin >> testCount;
    
    forn(test, testCount)
    {
        assert(read());
        solve(test);
    }
    
    return 0;
}
