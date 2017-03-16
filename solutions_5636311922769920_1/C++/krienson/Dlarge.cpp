#include<iostream>
#include<vector>

using namespace std;

int main(){
	int kases; cin >> kases;
	for( int kase = 1; kase <= kases; kase++ ){
		cout << "Case #" << kase << ":";
		unsigned long long K, C, S;
		cin >> K >> C >> S;
		if( C == 1 ){
			if( K > S ){
				cout << " IMPOSSIBLE" << endl;
			}
			else{
				for( int s = 0; s < S; s++ ){
					cout << " " << s+1;
				}
				cout << endl;
			}
			continue;
		}
		else if( K > 2*S ){
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		vector< unsigned long long > tiles;
		unsigned long long bigroup = 1, limit;
		for( int c = 1; c < C; c++ ){
			bigroup *= K;
		}
		limit = bigroup * K;
		unsigned long long tile = 2;
		while( tile <= limit ){
			tiles.push_back( tile );
			tile += 2*bigroup + 2;
		}
		if( (K & 1)==1 && (tiles.size() < S) ){
			tiles.push_back( limit );
		}

		for( int s = 0; s < int( tiles.size() ); s++ )
			cout << " " << tiles[ s ];
		cout << endl;
	}
}
