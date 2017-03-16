#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define fi first
#define sc second
#define MP make_pair
#define pb push_back
#define PI acos(-1.0) //alternative #define PI (2.0 * acos(0.0))
#define vi vector<int>
#define vii vector<ii>
#define ALL(c) (c).begin(), (c).end()
#define RESET( c,a ) memset( (c), a, sizeof(c) )
#define REP( a,b,c ) for ( int a=b, _c=c; a<_c; ++a )
#define RED( a,b,c ) for ( int a=b, _c=c; a>=_c; --a )
#define REPI( it, c ) for ( __typeof( (c).begin() ) it=(c).begin(); it!=(c).end(); ++it )

const int big = 2000000000;
const double INF = 1e9;
const double EPS = 1e-9;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

//#define _DEBUG 1
#ifdef _DEBUG
	#define DEBUG printf
#else
	#define DEBUG if (0) printf
#endif

// NTU The Lyons' Template
//----------------------------------------------------------------------

/*
struct attk
{
	int d, w, e, s;
};
*/

/*
bool operator< ( attk &c1, attk &c2 )
{
	if (c1.w != c2.w) return (c1.w < c2.w);
	return (c1.e < c2.e);
}
*/

void solve( int T )
{
	int N;
	int d, n, w, e, s, dd, dp, ds;
	vector < pair< pii, pii > > v;
	
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
		while (n--)
		{
			//v.pb( (attk){ d, w, e, s } );
			v.pb( MP( MP(w,e), MP(d,s) ) );
			d += dd;
			w += dp;
			e += dp;
			s += ds;
		}
	}
	sort( ALL(v) );
	
	int ans=0;
	REPI( x,v )
	{
		pair< pii, pii > cur = *x;
		REPI( y,v )
		{
			if ((y->sc.fi < cur.sc.fi)  &&  (y->sc.sc >= cur.sc.sc))
			{
				if ((y->fi.fi <= cur.fi.fi) && (y->fi.sc >= cur.fi.fi))
					cur.fi.fi = y->fi.sc;
			}
		}
		if (cur.fi.fi < cur.fi.sc) ++ans;
	}
	
	printf("Case #%d: %d\n", T, ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(TT,0,T) solve( TT+1 );
	return 0;
}
