#include <algorithm>
#include <bitset>
#include <cmath>
#include <climits>
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
#include <utility>
#include <vector>
 
using namespace std ;

#define all(n) n.begin(), n.end()
#define fb(i, n) fv (i, 0, n)
#define fe(i, n) fb (i, n.size())
#define fi(i, n) for (typeof (n.begin()) i = n.begin() ; i != n.end() ; i++)
#define fv(i, s, n) for ( int i = s ; i < n ; i++ )
#define LOG cerr << "[" << __LINE__ << "] "
#define pb push_back

const int lm = 1500 ;

int C[lm] ;
vector <list <int> > P ;
vector <set <int> > G ;

bool solve()
{
	int n ; cin >> n ;
	memset (C, 0, sizeof C) ;
	P = vector <list<int> > (n) ;
	G = vector <set<int> > (n) ;

	fb (i, n)
	{
		int h ; cin >> h ;
		fb (u, h)
		{
			int l ; cin >> l ;
			P[i].pb(l - 1) ;
			C[l - 1]++ ;
		}
	}

	queue <int> d ;
	fb (i, n) if (C[i] == 0) d.push(i) ;

	while (!d.empty())
	{
		int a = d.front() ; d.pop() ;
		fi (i, P[a])
		{
			G[*i].insert(a) ;
			fi (u, G[a])
			{
				if (G[*i].find(*u) != G[*i].end()) return true ;
				G[*i].insert(*u) ;
			}
			
			if (--C[*i] == 0) d.push(*i) ;
		}
	}

	return false ;
}


int main()
{
	int t ; cin >> t ;
	fb (i, t)
		printf ("Case #%d: %s\n", i + 1, solve() ? "Yes" : "No") ;

	return 0 ;
}

