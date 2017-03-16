#include <iostream>
#include <algorithm>
#include <string>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int t, n;
string s;
int bucket[30];

string numbers[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int len[10] = { 4, 3, 3, 5, 4, 4, 3, 5, 5, 4 };

void remove( int k ){
	for( int i = 0; i < len[k]; i++ )
		bucket[ numbers[k][i] - 'A' ]--;
	n -= len[k];
}

int main(){
	
	optimizar_io
	cin >> t;
	for( int k = 1; k <= t; k++ ){
		
		cin >> s;
		n = s.size();
		for( int i = 0; i < n; i++ )
			bucket[ s[i] - 'A' ]++;
		
		string ans = "";
		while( n ){
			if( bucket[ 'Z' - 'A' ] ){
				remove( 0 );
				ans += "0";
				continue;
			}
			if( bucket[ 'X' - 'A' ] ){
				remove( 6 );
				ans += "6";
				continue;
			}
			if( bucket[ 'W' - 'A' ] ){
				remove( 2 );
				ans += "2";
				continue;
			}
			if( bucket[ 'U' - 'A' ] ){
				remove( 4 );
				ans += "4";
				continue;
			}
			if( bucket[ 'S' - 'A' ] ){
				remove( 7 );
				ans += "7";
				continue;
			}
			if( bucket[ 'F' - 'A' ] ){
				remove( 5 );
				ans += "5";
				continue;
			}
			if( bucket[ 'G' - 'A' ] ){
				remove( 8 );
				ans += "8";
				continue;
			}
			if( bucket[ 'O' - 'A' ] ){
				remove( 1 );
				ans += "1";
				continue;
			}
			if( bucket[ 'T' - 'A' ] ){
				remove( 3 );
				ans += "3";
				continue;
			}
			remove( 9 );
			ans += "9";
		}
		
		for( int i = 0; i < 26; i++ )
			bucket[i] = 0;

		sort( ans.begin(), ans.end() );
		cout << "Case #" << k << ": " << ans << "\n";
		
	}
	return 0;
	
}