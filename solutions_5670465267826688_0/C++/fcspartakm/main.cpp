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
const int N = 10 * 1000 + 13;

bool oki[N];
bool okk[N];
int a[N];
string s;
int l, x;
int n;

inline bool read()
{
	memset(oki, 0, sizeof(oki));
	memset(okk, 0, sizeof(okk));
	cin >> l >> x;
	cin >> s;
	return true;
}

int pr[5][5] = 
{
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};

inline void solve(int tt)
{
	printf("Case #%d: ", tt + 1);
	string t = "";
	for(int i = 0; i < x; i++)
		t += s;
	s = t;
	n = sz(s);	
	for(int i = 0; i < n; i++)
	{
		if(s[i] == 'i')
			a[i] = 2;
		if(s[i] == 'j')
			a[i] = 3;
		if(s[i] == 'k')
			a[i] = 4;			
	}	
	int cur = 1;
	for(int i = 0; i < n; i++)
	{
		int now = pr[abs(cur)][a[i]];
		if(cur < 0)
			now *= -1;
		if(now == 2)
			oki[i] = 1;
		cur = now;
	}
	cur = 1;
	for(int i = n - 1; i >= 0; i--)
	{
		int now = pr[a[i]][abs(cur)];
		if(cur < 0)
			now *= -1;
		if(now == 4)
			okk[i] = 1;
		cur = now;
	}
	for(int i = 0; i < n - 1; i++)
	{
		if(!oki[i])
			continue;
		int cur = 1;
		for(int j = i + 1; j < n - 1; j++)
		{
			int now = pr[abs(cur)][a[j]];
			if(cur < 0)
				now *= -1;
			if(now == 3 && okk[j + 1])
			{
				puts("YES");
				return;
			} 
			cur = now;
		}			
	}
	puts("NO");
}

int main()
{
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
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
    	solve(i);
    }        
#ifdef fcspartakm
    cerr << "TIME: " << clock() << endl;
#endif      
    
    return 0;
}