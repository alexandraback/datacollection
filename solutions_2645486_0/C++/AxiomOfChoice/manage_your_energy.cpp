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

#define _E 10
#define _N 15

int v[_N], E, R, N, best[_N][_E];

int rec( int i, int e )
{
	int & ans = best[i][e];
	if( ans != -1 ) return ans;
	ans = 0;
	if( i < N ) rep(j,e+1) ans = max( ans, v[i] * j + rec( i + 1, min( e - j + R, E ) ) );
	return ans;
}

int solve()
{
	scanf( "%d%d%d", &E, &R, &N );
	rep(i,N) scanf( "%d", &v[i] );
	rep(i,N+1) rep(j,E+1) best[i][j] = -1;
	return rec( 0, E );
}

int main()
{
	int T;
	scanf( "%d", &T );
	for( int t = 1; t <= T; t++ ) printf( "Case #%d: %d\n", t, solve() );
	return 0;
}
