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
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 20 + 3;

int n, a[N];

inline bool read()
{
	if (scanf("%d", &n) != 1)
		return false;
		
	forn(i, n)
		assert(scanf("%d", &a[i]) == 1);
		
	return true;
}

int sum[(1 << 20) + 3];

inline void solve(int test)
{
	sort(a, a + n);
	
	cerr << "Test #" << test + 1 << endl;
	
	printf("Case #%d:\n", test + 1);
	
	forn(mask, (1 << n))
	{
		sum[mask] = 0;
		
		forn(i, n)
			if (mask & (1 << i))
				sum[mask] += a[i];
	}
	
	forl(mask1, (1 << n) - 1)
	{
		int smask = (~mask1) & ((1 << n) - 1);
		
		for (int mask2 = smask; mask2 > 0; mask2 = (mask2 - 1) & smask)
			if (sum[mask1] == sum[mask2])
			{
				int ans1 = 0;
				bool is = false;
				
				forn(i, n)
					if (mask1 & (1 << i))
					{
						ans1 += a[i];
						
						if (is)
							putchar(' ');
						else
							is = true;
							
						printf("%d", a[i]);
					}
					
				puts("");
				
				is = false;
				
				int ans2 = 0;
				
				forn(i, n)
					if (mask2 & (1 << i))
					{
						ans2 += a[i];
						
						if (is)
							putchar(' ');
						else
							is = true;
							
						printf("%d", a[i]);
					}
					
				puts("");
				
				assert(ans1 == ans2);
				
				return;
			}
	}
	
	puts("Impossible");
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
