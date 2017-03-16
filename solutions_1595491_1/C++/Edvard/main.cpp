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
#define X first
#define Y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 + 3;

int n, s, p;
int a[N];

inline bool read()
{
	if (scanf("%d%d%d", &n, &s, &p) != 3)
		return false;
		
	forn(i, n)
		assert(scanf("%d", &a[i]) == 1);
		
	return true;
}

int z[N][N];

int solve(int idx, int cnt)
{
	if (cnt < 0)
		return -2;
		
	int& ans = z[idx][cnt];
	
	if (ans != -1)
		return ans;
		
	if (idx == n)
		return ans = cnt > 0 ? -2 : 0;
		
	ans = -2;
	
	forn(i, 11)
		forn(d, 3)
		{
			int j = i + d;
			int k = a[idx] - i - j;
			
			if (k < 0 || k > 10)
				continue;
				
			if (abs(i - j) > 2 || abs(i - k) > 2 || abs(j - k) > 2)
				continue;
				
			//cerr << idx << ' ' << i << ' ' << j << ' ' << k << endl;
			
			int is = abs(i - j) == 2 || abs(i - k) == 2 || abs(j - k) == 2;
			
			int next = solve(idx + 1, cnt - is);
			
			if (next != -2)
				ans = max(ans, next + (max(i, max(j, k)) >= p));
		}
		
	return ans;
}

inline void solve(int test)
{
	memset(z, -1, sizeof(z));
	
	printf("Case #%d: %d\n", test + 1, solve(0, s));
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
