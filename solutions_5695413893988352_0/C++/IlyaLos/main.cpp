#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(2e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

const int N = 20 + 3;
int n;
char s[N], t[N];

inline bool read()
{
	if (scanf ("%s%s", s, t) != 2)
		return false;
	
	n = int(strlen(s));

	return true;
}

pair<li, pair<li, li> > d[N][3];
pair<pt, pt> p[N][3];
li st[N];

inline void update (int ni, int nj, int i, int j, pair<li, pair<li, li> > val, int c1, int c2)
{
	if (d[ni][nj] <= val)
		return;
		
	d[ni][nj] = val;
	p[ni][nj] = mp(mp(i, j), mp(c1, c2));
}

inline void solve(int test)
{
	printf ("Case #%d: ", test + 1);
	
	forn (i, n + 1)
		forn (j, 3)
			d[i][j] = mp(INF64, mp(INF64, INF64));
			
	d[0][1] = mp(0, mp(0, 0));
	forn(i, n)
		forn (j, 3)
		{
			if (d[i][j].ft == INF64)
				continue;
				
			if (s[i] == '?')
			{
				forn (c1, 10)
				{
    				if (t[i] == '?')
    				{
    					forn (c2, 10)
    					{
        					li val1 = d[i][j].sc.ft + c1 * st[n - 1 - i], val2 = d[i][j].sc.sc + c2 * st[n - 1 - i];
        					li ndiff = abs(val1 - val2);
        					
        					if (val1 == val2)
        						update(i + 1, 1, i, j, mp(ndiff, mp(val1, val2)), c1, c2);
        					else
        					if (val1 < val2)
        						update(i + 1, 0, i, j, mp(ndiff, mp(val1, val2)), c1, c2);
        					else
        						update(i + 1, 2, i, j, mp(ndiff, mp(val1, val2)), c1, c2);					
    					}
    				}
    				else
    				{
    					int c2 = t[i] - '0';
    					
    					li val1 = d[i][j].sc.ft + c1 * st[n - 1 - i], val2 = d[i][j].sc.sc + c2 * st[n - 1 - i];
    					li ndiff = abs(val1 - val2);
    					
    					if (val1 == val2)
    						update(i + 1, 1, i, j, mp(ndiff, mp(val1, val2)), c1, c2);
    					else
    					if (val1 < val2)
    						update(i + 1, 0, i, j, mp(ndiff, mp(val1, val2)), c1, c2);
    					else
    						update(i + 1, 2, i, j, mp(ndiff, mp(val1, val2)), c1, c2);
    				}					
				}	
			}
			else
			{
				int c1 = s[i] - '0';
				
				if (t[i] == '?')
				{
					forn (c2, 10)
					{
    					li val1 = d[i][j].sc.ft + c1 * st[n - 1 - i], val2 = d[i][j].sc.sc + c2 * st[n - 1 - i];
    					li ndiff = abs(val1 - val2);
    					
    					if (val1 == val2)
    						update(i + 1, 1, i, j, mp(ndiff, mp(val1, val2)), c1, c2);
    					else
    					if (val1 < val2)
    						update(i + 1, 0, i, j, mp(ndiff, mp(val1, val2)), c1, c2);
    					else
    						update(i + 1, 2, i, j, mp(ndiff, mp(val1, val2)), c1, c2);					
					}
				}
				else
				{
					int c2 = t[i] - '0';
					
					li val1 = d[i][j].sc.ft + c1 * st[n - 1 - i], val2 = d[i][j].sc.sc + c2 * st[n - 1 - i];
					li ndiff = abs(val1 - val2);
					
					if (val1 == val2)
						update(i + 1, 1, i, j, mp(ndiff, mp(val1, val2)), c1, c2);
					else
					if (val1 < val2)
						update(i + 1, 0, i, j, mp(ndiff, mp(val1, val2)), c1, c2);
					else
						update(i + 1, 2, i, j, mp(ndiff, mp(val1, val2)), c1, c2);
				}
			}
		}
		
	int j = 0;
	forn (i, 3)
		if (d[n][i] < d[n][j])
			j = i;
			
	//cerr << d[n][j].sc.ft << ' ' << d[n][j].sc.sc << endl;
			
	for (int i = n; i > 0; i--)
	{
		s[i - 1] = p[i][j].sc.ft + '0';
		t[i - 1] = p[i][j].sc.sc + '0';

		j = p[i][j].ft.sc;
	}
	
	printf ("%s %s\n", s, t);
}

inline void precalc ()
{
	st[0] = 1;
	fore (i, 1, 18)
		st[i] = st[i - 1] * 10;
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));
	
	precalc();
	
	int testCnt;
	assert(scanf ("%d", &testCnt) == 1);

	forn (test, testCnt)
	{
		assert(read());
		solve(test);
	}

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}
