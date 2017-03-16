/**
 * Tittle:	2015 Google Code Jam Round1C - PB
 * Author:	Cheng-Shih, Wong
 * Date:	2015/05/10
 */

// include files
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )

typedef map<string,int> MSI;

// declarations
int t;
int k, l, s;
int maxs;
string key, target;
MSI m;

// functions
void dfs( int level, string tmp )
{
	if( level == s ) {
		++m[tmp];
	} else {
		FOR( i, 0, k-1 )
			dfs( level+1, tmp+key[i] );
	}
}

// main function
int main( void )
{
	MSI::iterator it;
	int cnt, maxc, sumc;
	double ans, prob;

	// input
	scanf( "%d", &t );

	FOR( ti, 1, t ) {
		scanf( "%d%d%d", &k, &l, &s );
		cin >> key >> target;
		m.clear();
		sumc = maxc = 0;
		maxs = 1;
		FOR( i, 1, s ) maxs *= k;
		ans = 0;

		// solve
		dfs( 0, "" );
		for( it=m.begin(); it!=m.end(); ++it ) {
			cnt = 0;
			FOR( i, 0, s-l )
				if( target==(*it).first.substr(i,l) )
					++cnt;
			maxc = max( maxc, cnt );
			prob = ((double)(*it).second)*cnt/maxs;
			ans += prob;
		}

		// output
		printf( "Case #%d: %.8lf\n", ti, maxc-ans );
	}
	
	return 0;
}
