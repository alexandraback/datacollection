#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

// Premature optimization is the root of all evil

using namespace std;

int solveacase() {

	int N;
	cin >> N;
	int _D[N];
	int _H[N];
	int _M[N];
	int hikers = 0;

	forn(i, N) {
		cin >> _D[i];
		cin >> _H[i];
		cin >> _M[i];
		hikers += _H[i];
	}

	int D[hikers];
	int M[hikers];
	int h = 0;

	forn( i, N ) {
		forn( j, _H[i] ) {
			D[h] = _D[i];
			M[h] = _M[i] + j;
			h++;
		}
	}

	if ( hikers == 1 ) { return 0; }

	assert( hikers <= 2 );

	

	double lfinish = max( ((360.0 - D[0]) / 360.0) * M[0],
			   ((360.0 - D[1]) / 360.0) * M[1] );
	double ffinish = min( ((360.0 - D[0]) / 360.0 + 1) * M[0],
			   ((360.0 - D[1]) / 360.0 + 1) * M[1] );

	if ( ffinish > lfinish ) return 0;



	return 1;
}

int main ( int, char** ) {

	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) {
		cout << "Case #" << i << ": ";
		cout << solveacase() << endl;
	}


	return 0;
}
