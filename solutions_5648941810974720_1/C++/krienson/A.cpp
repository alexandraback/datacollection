#include<iostream>
#include<string>
#include<vector>

using namespace std;

string L[ 10 ] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
char R[ 10 ] ={ 'Z','W','U', 'X','G', 'O', 'S','H','F','I' };
int RN[ 10 ] = {0,2,4,6,8,1,7,3,5,9};
int Q[ 10 ];
int T[ 300 ];

int main(){
	int kases; cin >> kases;
	for( int kase = 1; kase <= kases; kase++ ){
		string s;
		cin >> s;
		for( int i = int('A'); i <= int('Z');i++)
			T[ i ] = 0;	
		for( int i = 0; i <int( s.length() ); i++ ){
			T[ int(s[i]) ]++;		
		}
		for( int i = 0; i < 10; i++ ) Q[ i ] = 0;
		for( int i = 0; i < 10; i++ ){
			int n = RN[ i ];
			Q[ n ] = T[ int(R[ i ]) ]; //cout << n << " " << Q[ n ] << endl;
			for( int j = 0; j < int(L[ n ].length()); j++ ){
				T[ int(L[n][j]) ] -= Q[ n ];
			}
		}
		cout << "Case #" << kase<<": ";
		for( int q = 0; q < 10; q++ )
			if( Q[ q ] )
				cout << string( Q[ q ], q + '0' );
		cout << endl;
	}
}
