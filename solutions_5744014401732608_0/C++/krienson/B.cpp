#include<iostream>
#include<vector>

using namespace std;

int B;
long long M;
bool possible;
int main(){
	int T; cin >> T;
	for( int t = 1; t <= T; t++ ){
		possible = true;
		cout << "Case #" << t <<": ";
		cin >> B >> M;	
		vector< vector< long long > > v( B, vector< long long >(B,0) );
		vector< long long > s( B );
		s[ 0 ] = 1;
		long long acum = 1;
		for( int i = 0; i+1 < B; i++ ){
			for( int j = i+1; j+1 < B; j++ ){
				v[ i ][ j ]  = 1;
			}
			if( i ){
				s[ i ] = acum; 
				acum <<= 1;
			}
		}
		if( M > acum ) possible = false;
		else if( M == acum ){
			for( int i = 0; i + 1 < B; i++ )
				v[ i ][ B-1 ] = 1;
		}
		else{
			int pos = 1;
			while( M ){
				if( M&1 )
					v[ pos ][ B-1 ] = 1;
				M>>=1;
				pos++;
			}
		}
		if( !possible ) cout << "IMPOSSIBLE" << endl;
		else{
			cout << "POSSIBLE" << endl;
			for( int i = 0; i < B; i++ ){
				for( int j = 0; j < B; j++ ){
					cout << v[ i ][ j ];
				}
				cout << endl;
			}
		}
	}
}
