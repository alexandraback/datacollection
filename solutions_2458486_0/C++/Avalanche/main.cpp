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

const int N = 200 + 3;

int n, m;
int a[N];

int t[N];
vector <int> v[N];

inline bool read()
{
	if (scanf("%d%d", &m, &n) != 2)
		return false;
		
	forn(i, m)
	{
		assert(scanf("%d", &a[i]) == 1);
		a[i]--;
	}
	
	forn(i, n)
	{
		assert(scanf("%d", &t[i]) == 1);
		t[i]--;
		v[i].clear();
		
		int cnt;
		assert(scanf("%d", &cnt) == 1);
		v[i].resize(cnt);
		
		forn(j, sz(v[i]))
		{
			assert(scanf("%d", &v[i][j]) == 1);
			v[i][j]--;			
		}
	}
	
	return true;
}

int z[(1 << 20) + 3];

int solve(int mask)
{
	int& ans = z[mask];
	if (ans != -1)
		return ans;
		
	if (mask + 1 == (1 << n))
		return ans = 1;
		
	ans = 0;
	multiset<int> keys;
	
	forn(i, m) keys.insert(a[i]);
	
	forn(i, n)
		if (mask & (1 << i))
			forn(j, sz(v[i]))
				keys.insert(v[i][j]);
				
	forn(i, n)
		if (mask & (1 << i))
		{
			multiset<int>::iterator it = keys.find(t[i]);
			if (it == keys.end()) continue;
			
			keys.erase(it);
		}
			
	forn(i, n)
		if ((mask & (1 << i)) == 0 && keys.count(t[i]) && solve(mask | (1 << i)))
			ans = 1;
			
	return ans;
}

void restore(int mask)
{
	int& ans = z[mask];
	assert(ans != -1);
		
	if (mask + 1 == (1 << n)) return;
		
	multiset<int> keys;
	
	forn(i, m) keys.insert(a[i]);
	
	forn(i, n)
		if (mask & (1 << i))
			forn(j, sz(v[i]))
				keys.insert(v[i][j]);
				
	forn(i, n)
		if (mask & (1 << i))
		{
			multiset<int>::iterator it = keys.find(t[i]);
			if (it == keys.end()) continue;
			
			keys.erase(it);
		}
			
	forn(i, n)
		if ((mask & (1 << i)) == 0 && keys.count(t[i]) && solve(mask | (1 << i)))
		{
			printf(" %d", i + 1);
			return restore(mask | (1 << i));
		}
		
	throw;
}


inline void _solve(int test)
{
	memset(z, -1, sizeof z);
	int ans = solve(0);
	
	printf("Case #%d:", test + 1);

	if (ans == 0)
	{
		puts(" IMPOSSIBLE");
		return;
	}
	
	restore(0);
	puts("");
}

int main()
{
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
        
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
        
	int testCount;
	cin >> testCount;
	
	forn(test, testCount)
	{
		assert(read());
		_solve(test);
	}
        
	return 0;
}