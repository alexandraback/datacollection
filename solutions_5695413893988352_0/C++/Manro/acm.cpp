#include <bits/stdc++.h>
#define ff first
#define ss second
#define D(x) cout << ">> " << #x << " = >" << x << "<\n"
#define FOR(i,a,b) for ( decltype( a ) i = (a); i < (b); ++i )
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

void solve( const string & a, set<int> & x, int i, int sum ) {
	if ( i == a.size( ) ) {
		x.insert( sum );
		return;
	}
	if ( a[i] != '?' )
		solve( a, x, i+1, sum * 10 + a[i] - '0' );
	else
		FOR( j, 0, 10 )
			solve( a, x, i+1, sum * 10 + j );
}

int main( ) {
	int t;
	string a, b;

	cin >> t;
	FOR( caseNr, 1, t+1 ) {
		cout << "Case #" << caseNr << ": " ;
		set<int> va, vb;
		cin >> a >> b;
		solve( a, va, 0, 0 );
		solve( b, vb, 0, 0 );
		int ra = 1e5, rb = 1e6;
		for ( int ax : va )
			for ( int bx : vb )
					if ( abs( bx - ax ) < abs( rb - ra ) || ( abs( bx - ax ) == abs( rb - ra ) && ( ax < ra || ( ax == ra && bx < rb ) ) ) ) {
						ra = ax;
						rb = bx;
					}
		cout << setw( a.size( ) ) << setfill( '0' ) << ra << " " << setw( b.size( ) ) << setfill( '0' ) << rb << endl;
	}
	return 0;
}