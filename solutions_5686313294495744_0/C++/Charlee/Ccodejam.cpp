#include <iostream>
#include <string>
#include <set>
using namespace std;

int t, n;
int M;
pair<string, string> A[22];

int main(){	
	
	cin >> t;
	for( int k = 1; k <= t; k++ ){
		
		cin >> n;
		for( int i = 0; i < n; i++ )
			cin >> A[i].first >> A[i].second;
		
		int ans = 0;
		for( int M = 1; M < (1 << n); M++ ){
			set<string> f, s;
			for( int i = 0; i < n; i++ )
				if( M & (1 << i) ){
					f.insert( A[i].first );
					s.insert( A[i].second );
				}
			int r = 0;
			for( int i = 0; i < n; i++ )
				if( !( M & (1 << i) ) )
					if( f.find( A[i].first ) != f.end() && s.find( A[i].second ) != s.end() )
						r++;
			ans = max( ans, r );
		}
		
		cout << "Case #" << k << ": " << ans << "\n";
		
	}
	
	return 0;

}