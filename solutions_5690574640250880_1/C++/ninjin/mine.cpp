#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> vec;

int main(){
	int T;
	cin >> T;
	for( int t=0; t<T; t++ ){
		int R, C, M;
		cin >> R >> C >> M;
		vector<vec> grid(R, vec(C, '.'));
		bool impossible = true;
		int sx = 0, sy = 0, m = M;
		while( 0 < m ){
			if( R-sy < C-sx ){
				for( int i=sy; i<R; i++ ){
					if( 0 < m ){
						if( m == 1 && i == R-2 ) break;
						grid[i][sx] = '*';
						m--;
						if( m == 0 && sx != C-2 && i != R-2 ) impossible = false;
					}
				}
				sx++;
			}else{
				for( int i=sx; i<C; i++ ){
					if( 0 < m ){
						if( m == 1 && i == C-2 ) break;
						grid[sy][i] = '*';
						m--;
						if( m == 0 && i != C-2 && sy != R-2 ) impossible = false;
					}
				}
				sy++;
			}
		}
		
		grid[R-1][C-1] = 'c';

		cout << "Case #" << t+1 << ":" << endl;
		if( impossible && M != R*C-1 && M != 0 ) cout << "Impossible" << endl;
		else{
			for( int i=0; i<R; i++ ){
				for( int j=0; j<C; j++ ){
					cout << grid[i][j];
				}
				cout << endl;
			}
		}
	}
}
