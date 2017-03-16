#include <bits/stdc++.h>
#define ff first
#define ss second
#define D(x) cout << ">> " << #x << " = >" << x << "<\n"
#define FOR(i,a,b) for ( decltype( a ) i = (a); i < (b); ++i )
#define FORD(i,a,b) for ( int i = int(a); i >= (b); --i )
#define PB push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int n;
vector<string> firstW, secondW;

bool test( int state ) {
	set<string> f, s;
	FOR( i, 0, n ) {
		if ( !(state & (1 << i)) ) {
			f.insert( firstW[i] );
			s.insert( secondW[i] );
		}
	}
	FOR( i, 0, n ) {
		if ( state & (1 << i) ) {
			if ( !f.count( firstW[i] ) || !s.count( secondW[i] ) )
				return false;
		}
	}
	return true;
}

int main( ) {
	int t;
	string a, b;

	cin >> t;
	FOR( caseNr, 1, t+1 ) {
		firstW.clear( );
		secondW.clear( );
		cout << "Case #" << caseNr << ": " ;
		cin >> n;
		FOR( i, 0, n ) {
			cin >> a >> b;
			firstW.PB( a );
			secondW.PB( b );
		}
		int res = 0;
		FOR( s, 0, (1 << n) ) {
			if ( test( s ) ) {
				int cnt = 0;
				FOR( i, 0, n )
					if ( s & ( 1 << i ) )
						++cnt;
				res = max( res, cnt );
			}
		}
		cout << res << endl;
	}
	return 0;
}