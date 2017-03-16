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

#define _K 15

int R, N, M, K;
ll prod[_K];

void solve()
{
	rep(i,K) scanf( "%lld", &prod[i] );
	for( int a = 2; a <= M; a++ )
	for( int b = 2; b <= M; b++ )
	for( int c = 2; c <= M; c++ )
	{
		bool ok = true;
		rep(i,K)
		{
			if(
				prod[i] == 1 ||
				prod[i] == a ||
				prod[i] == b ||
				prod[i] == c ||
				prod[i] == a * b ||
				prod[i] == b * c ||
				prod[i] == c * a ||
				prod[i] == a * b * c
			)
				continue;
			ok = false;
			break;
		}
		if( ok )
		{
			printf( "%d%d%d\n", a, b, c );
			return;
		}
	}
	//rep(i,N) printf( "2" );
	//printf( "\n" );
	printf( "222\n" );
}

int main()
{
	int T;
	scanf( "%d", &T );
	printf( "Case #1:\n" );
	scanf( "%d%d%d%d", &R, &N, &M, &K );
	while( R-- ) solve();
	return 0;
}
