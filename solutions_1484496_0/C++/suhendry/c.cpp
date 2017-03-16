#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int (i)=0,_n=(n);(i)<_n;(i)++)
#define FOR(i,a,b) for(int (i)=(a),_n=(b);(i)<=_n;(i)++)
#define FORD(i,a,b) for(int (i)=(a),_n=(b);(i)>=_n;(i)--)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

int n;
int s[25];

int m;
int r[25];
vector <int> b;

int sum;
int dp[21][2000005];
int f(int x, int t) {
	if ( dp[x][t] != -1 ) return dp[x][t];
	int &ret = dp[x][t] = 0;
	if ( t == sum ) return ret = 1;
	if ( x == m   ) return ret = 0;
	if ( f(x+1,t) ) return ret = 1;
	if ( f(x+1,t+r[x]) ) {
		b.push_back(r[x]);
		return ret = 1;
	}
	return ret;
}

int main()
{
	int T;
	scanf( "%d", &T );
	FOR(tcase,1,T) {
		scanf( "%d", &n );
		REP(i,n) scanf( "%d", &s[i] );

		printf( "Case #%d:\n", tcase );
		
		bool found = false;
		REP(bit,1<<n) {
			sum = 0;
			REP(i,n) if ( bit & (1 << i) ) sum += s[i];
			if ( sum == 0 ) continue;

			m = 0;
			REP(i,n) if ( !(bit & (1 << i)) ) r[m++] = s[i];
			
			b.clear();
			memset(dp,-1,sizeof(dp));
			if ( f(0,0) ) {
				vector <int> a;
				REP(i,n) if ( bit & (1 << i) ) a.push_back(s[i]);
				REP(i,a.size()) printf( "%d%c", a[i], i+1==a.size()?'\n':' ');
				REP(i,b.size()) printf( "%d%c", b[i], i+1==b.size()?'\n':' ');
				REP(i,a.size()) fprintf( stderr, "%d%c", a[i], i+1==a.size()?'\n':' ');
				REP(i,b.size()) fprintf( stderr, "%d%c", b[i], i+1==b.size()?'\n':' ');
				found = true;
				goto done;
			}
		}
		
		done:
		if ( !found ) puts( "Impossible" );

	}
	return 0;
}
