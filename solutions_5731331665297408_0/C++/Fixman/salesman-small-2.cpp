#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std ;
 
#define forsn(i, s, n) for (int i = s ; i < n ; i++)
#define forn(i, n) forsn(i, 0, n)
#define fore(i, n) forn(i, n.size())
#define fori(i, n) for (auto i = n.begin() ; i != n.end() ; i++)
#define all(n) n.begin(), n.end()
#define pb push_back

const int maxn = 10 ;

int N ;
string Z[maxn] ;
set <int> M[maxn] ;

int F[maxn] ;

bool go(const vector <int> &h, int n, int q)
{
	if (n == h.size()) return true ;

	if (M[q].find(h[n]) != M[q].end())
	{
		F[h[n]] = q ;
		if (go(h, n + 1, h[n])) return true ;
	}

	if (F[q] != -1) return go(h, n, F[q]) ;
	return false ;
}

bool valid(const vector <int> &h)
{
	memset(F, -1, sizeof F) ;
	return go(h, 1, h[0]) ;
}

string concat(const vector <int> &h)
{
	string r ;
	fore(i, h) r += Z[h[i]] ;
	//fore(i, h) r += to_string(h[i]) + " " ;
	return r ;
}

int main()
{
	int t ; cin >> t ;
	forn(z, t)
	{
		forn(i, maxn) M[i].clear() ;

		int m ; cin >> N >> m ;
		forn(i, N) cin >> Z[i] ;

		forn(i, m)
		{
			int a, b ; cin >> a >> b ; a-- ; b-- ;
			M[a].insert(b) ; M[b].insert(a) ;
		}

		string r = "x" ;
		
		vector <int> h(N) ;
		fore(i, h) h[i] = i ;
		do
		{
			if (valid(h))
			{
				//fore(i, h) cout << h[i] << ' ' ; cout << endl ;
				r = min(r, concat(h)) ;
			}
		}
		while (next_permutation(all(h))) ;

		printf ("Case #%d: %s\n", z + 1, r.c_str()) ;
	}

	return 0 ;
}
