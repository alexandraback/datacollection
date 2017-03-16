#include<iostream>
#include<vector>

using namespace std;

int main(){
	int kases; cin >> kases;
	for( int kase = 1; kase <= kases; kase++ ){
		long long K, C, S;
		cin >> K >> C >> S;
		vector< int > tiles;
		/*long long offset = 1;
		for( int c = 1; c < C; c++ ){
			offset *= K;
		}
		for( int start = 1; start < offset * K; start += offset )
			tiles.push_back( start );*/
		for( int s = 1; s <= S; s++ )
			tiles.push_back( s );

		cout << "Case #" << kase << ":";
		if( tiles.size() == size_t( 0 ) ){
			cout << " IMPOSSIBLE" << endl;
		}
		else{
			for( int s = 0; s < int( tiles.size() ); s++ )
				cout << " " << tiles[ s ];
			cout << endl;
		}
	}
}
