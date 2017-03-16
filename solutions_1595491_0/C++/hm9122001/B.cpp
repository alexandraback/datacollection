#include <iostream>

using namespace std;

int t[105];
int x[105][105];

int main() {
	int C;
	cin >> C;
	for( int c = 0; c < C; ++c ) {
		int N, S, p;
		cin >> N >> S >> p;
		for( int i = 0; i < N; ++i ) {
			cin >> t[i];
		}
		x[N][0] = 0;
		for( int i = 1; i <= S; ++i ) {
			x[N][i] = -1;
		}
		for( int i = N-1; i >= 0; --i ) {
			for( int j = 0; j <= S; ++j ) {
				// x[i][j]
				x[i][j] = -1;
				// not surp
				int max = t[i]/3+(t[i]%3>0);
				if( x[i+1][j] >= 0 ) x[i][j] = x[i+1][j]+(max>=p);
				// surp
				if( j > 0 ) {
					max = -1;
					if( t[i]%3 == 2 ) {
						max = t[i]/3+2;
					} else if( t[i]%3 == 1 && t[i]/3 > 0 ) {
						max = t[i]/3+1;
					} else if( t[i]%3 == 0 && t[i]/3 > 0 ) {
						max = t[i]/3+1;
					}
					if( max > -1 && x[i+1][j-1] >= 0 )
						x[i][j] = ::max( x[i][j], x[i+1][j-1]+(max>=p) );
				}
			}
		}

		int y = x[0][S];
		if( y < 0 ) y = 0;
		cout << "Case #" << c+1 << ": " << y << endl;
	}
	return 0;
}
