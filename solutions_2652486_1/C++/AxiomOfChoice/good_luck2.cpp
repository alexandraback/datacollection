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

#define N 12
#define M 8
#define K 12
#define NP 4

int R = 8000;
//int R = 1;
int ps[] = { 2, 3, 5, 7 }, digs[] = { 7, 5, 2, 3, 4, 6, 8 };
ll prod[K];
int p[K][NP], best[M-1], lo[NP], tot[NP];

void solve()
{
	rep(j,NP) lo[j] = tot[j] = 0;
	rep(i,K)
	{
		scanf( "%lld", &prod[i] );
		ll tmp = prod[i];
		rep(j,NP)
		{
			p[i][j] = 0;
			while( ( tmp % ps[j] ) == 0 ) tmp /= ps[j], p[i][j]++;
			lo[j] = max( lo[j], p[i][j] );
			tot[j] += p[i][j];
		}
	}
	int n7 = max( lo[3], 2 * tot[3] / K );
	int n5 = max( lo[2], 2 * tot[2] / K );
	if( n7 + n5 > K ) n7 = lo[3], n5 = lo[2];
	best[0] = n7, best[1] = n5;

	int tot = n7 + n5;

	for( int a = 0; a + tot <= K; a++ ) // 2
	{
	tot += a;
	for( int b = 0; b + tot <= K; b++ ) // 3
	{
	tot += b;
	for( int c = 0; c + tot <= K; c++ ) // 4
	{
	tot += c;
	for( int d = 0; d + tot <= K; d++ ) // 6
	{
	tot += d;
	int e = K - tot; // 8
	if( a + 2 * c + d + 3 * e >= lo[0] && b + d >= lo[1] )
	{
		best[2] = a;
		best[3] = b;
		best[4] = c;
		best[5] = d;
		best[6] = e;
	}

	tot -= d;
	}

	tot -= c;
	}

	tot -= b;
	}

	tot -= a;
	}
	end:

	rep(i,M-1) rep(j,best[i]) printf( "%d", digs[i] );
	printf( "\n" );
}

int main()
{
	int t0, t1, t2, t3, t4;
	scanf( "%d%d%d%d%d", &t0, &t1, &t2, &t3, &t4 );
	printf( "Case #1:\n" );
	while( R-- ) solve();
	return 0;
}
