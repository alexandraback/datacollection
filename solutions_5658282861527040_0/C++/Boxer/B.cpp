#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) v.size()

typedef vector< string > vs;
typedef vector< int > vi;
typedef vector< vi > vvi;

int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases , A , B , K;
	cin >> cases;
	REP( tc , cases ){
		cin >> A >> B >> K;
		int ans = 0;
		REP( i , A ){
			REP( j , B ){
				int target = i & j;
				if( target < K ) ans++;
			}
		}
		cout << "Case #" << tc + 1 << ": " << ans << "\n";
	}
	
}
