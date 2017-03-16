#include <algorithm>
#include <bitset>
#include <cctype>
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
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define irep(i,n) REP(i,1,n+1)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define all(i) (i).begin(),(i).end()
#define aall(i) (i),((i)+sizeof(i)/sizeof((i)[0]))
#define CLR(i,n) memset(i,n,sizeof(i))
#define clr(i) CLR(i,0)
#define mod_add(a,b) a = ( a + b ) % MOD

#define _N 10005

ll v[_N], E, R, N;

ll solve_left( int a, int b, ll e )
{
	if( a == b ) return 0;
	if( R * ( b - a ) + e <= E ) return 0;
	int c = a;
	for( int i = a; i < b; i++ ) if( v[i] > v[c] ) c = i;
	ll lo = max( 0ll, E - R * ( b - c ) );
	ll hi = min( E, e + R * ( c - a ) );
	ll largest = ( hi - lo ) * v[c];
	ll ans = solve_left( a, c, e ) + largest + solve_left( c + 1, b, lo + R );
	//printf( "%d %d %lld %lld\n", a, b, e, ans );
	return ans;
}

ll solve_right( int a, int b, ll e )
{
	if( a == b ) return 0;
	int c = a;
	for( int i = a; i < b; i++ ) if( v[i] > v[c] ) c = i;
	ll largest = min( E, R * ( c - a ) + e ) * v[c];
	ll ans = solve_left( a, c, e ) + largest + solve_right( c + 1, b, R );
	//printf( "%d %d %lld %lld\n", a, b, e, ans );
	return ans;
}

ll solve()
{
	scanf( "%lld%lld%lld", &E, &R, &N );
	rep(i,N) scanf( "%lld", &v[i] );
	return solve_right( 0, N, E );
}

int main()
{
	int T;
	scanf( "%d", &T );
	for( int t = 1; t <= T; t++ ) printf( "Case #%d: %lld\n", t, solve() );
	return 0;
}
