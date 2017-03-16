#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <deque>
#include <list>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair<int, int> pt;
typedef long long li;
typedef long double ld;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define pb push_back
#define sz(a) int(a.size())
#define mp make_pair
#define all(a) a.begin(), a.end()
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++) 
#define ft first
#define sc second
#define x first
#define y second

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = ld(1e-9);
const ld PI = acos(-1.0);
const int N = 1000 + 13;

int a[N];
int sza;
int n;
int ans;

inline bool read()
{
	ans = 0;
	scanf("%d", &n);
	sza = n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		ans = max(ans, a[i]);
	}
	return true;
}

inline void solve(int t)
{
	int ma = 0;
	for(int i = 0; i < sza; i++)
		ma = max(ma, a[i]);
	for(int cur = 1; cur <= 1000; cur++)
	{
		if(cur > ma)
		{
			ans = min(ans, ma);
			break;
		}
		int now = 0;
		for(int i = 0; i < sza; i++)
		{
			if(a[i] <= cur)
				continue;
			now += (a[i] + cur - 1) / cur - 1;		
		}
		ans = min(ans, now + cur);
	}
	printf("Case #%d: %d\n", t + 1, ans);
}

int main()
{
#ifdef fcspartakm
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cerr << setprecision(10) << fixed;
    cout << setprecision(15) << fixed;
    
    srand(time(NULL));
    
    int test;
    cin >> test;
    for(int i = 0; i < test; i++)
    {    
   		assert(read());
    	solve(i);
    }        
#ifdef fcspartakm
    cerr << "TIME: " << clock() << endl;
#endif      
    
    return 0;
}