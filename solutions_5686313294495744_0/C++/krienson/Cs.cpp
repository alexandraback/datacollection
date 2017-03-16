#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;



int main(){
	int kases; cin >> kases;
	for( int kase = 1; kase <= kases; kase++ ){
		int R; cin >> R;
		vector<pair<string,string> > vs( R );
		set< string > ss;
		for( int r = 0; r < R; r++ ) {
			cin >> vs[ r ].first >> vs[ r ].second;
			ss.insert( vs[ r].second + "-" + vs[ r ].first );
		}
		int res = 0;
		for( int fakes = 0; fakes < (1<<R); fakes++ ){
			bool ok = true;
			vector< string > sF, sS;
			set< string > dF, dS;
			for( int j = 0; j < R; j++ ){
				if( (fakes & (1<<j)) ){ // fake
					sF.push_back( vs[ j ].first );
					sS.push_back( vs[ j ].second );
				}
				else{ // no fake
					dF.insert( vs[ j ].first );
					dS.insert( vs[ j ].second );
				}
			}
			
			for( int i = 0; i < int(sF.size()); i++ ){
				if( dF.find( sF[ i ] ) == dF.end() ){ ok = false; break; }
				if( dS.find( sS[ i ] ) == dS.end() ){ ok = false; break; }
			}
			if( ok && int(sF.size()) > res )
				res = int(sF.size());
		}
		cout << "Case #" << kase <<": " << res << endl;
	}
}
