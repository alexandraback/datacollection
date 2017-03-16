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

int R, n, m, k;
int a[10];

inline bool read()
{
	if (scanf("%d%d%d%d", &R, &n, &m, &k) != 4)
		return false;
		
	return true;
}

int s[10];
int cnt;

inline bool check (int a, int b, int c)
{
	set <int> can;
	int z[3] = {a, b, c};
	forn(mask, 8)
	{
		int cur = 1;
		forn(i, 3) if (mask & (1 << i)) cur *= z[i];
		can.insert(cur);
		//cerr << cur << endl;
	}
	forn(i, k) if (!can.count(s[i])) return false;
	return true;
}

inline void solve()
{
	forn(i, k) assert(scanf("%d", &s[i]) == 1);
	
	cnt = 0;
	for (int i = 2; i <= m; i++) a[cnt++] = i;
	
	random_shuffle(a, a + cnt);
	
	assert(n == 3);
	
	forn(i, cnt)
		forn(j, cnt)
			forn(p, cnt)
				if (check(a[i], a[j], a[p]))
				{
					printf("%d%d%d\n", a[i], a[j], a[p]);
					return;
				}
	puts("222");
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	int testCount;
	cin >> testCount;
	
	assert(read());
	printf("Case #1:\n");
	forn(i, R) solve();
	
	return 0;
}
