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

string s;
int n;

inline bool read()
{
	cin >> n >> s;
	return true;
}

inline void solve(int t)
{
	int sum = 0;
	int ans = 0;
	for(int i = 0; i < sz(s); i++)
	{
		int cur = (int)(s[i] - '0');
		if(cur == 0)
			continue;
		if(sum >= i)
		{
			sum += cur;
			continue;
		}
		ans += i - sum;
		sum = i;
		sum += cur;
	}
	printf("Case #%d: %d\n", t, ans);
}

int main()
{
#ifdef fcspartakm
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cerr << setprecision(10) << fixed;
    cout << setprecision(15) << fixed;
    
    srand(time(NULL));
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
    	assert(read());
	    solve(i + 1);
	}        
#ifdef fcspartakm
    cerr << "TIME: " << clock() << endl;
#endif      
    
    return 0;
}