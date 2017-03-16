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

bool vow( char i )
{
	return ( i=='a' || i=='u' || i=='i' || i=='o' || i=='e');
}

void solve( int T )
{
	char i[1000005];
	int n, x, y, sz, z=-1;
	LL ans = 0;
	x = y = 0;
	
	scanf("%s%d", i, &n);
	sz = strlen( i );
	DEBUG("%s %i",i,sz);
	
	while (x < sz)
	{
		while (vow( i[x] ) && (x<sz)) ++y, ++x;
		while (!vow( i[y] ) && (y-x < n) && (y<sz)) ++y;
		
		//cout << x << " " << y  << " = " << z << " " << ans << endl;
		
		if (y-x >= n)
		{
			ans += (LL) (sz-y+1LL) * (x-z);
			z = x;
		}
		else
			x = y-1;
		
		
		
		++x;
	}
	
	printf("Case #%d: %I64d\n", T, ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(TT,0,T) solve( TT+1 );
	return 0;
}
