/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

string s[2] = {"RICHARD","GABRIEL"};
int calc() { 
	int x,r,c;
	cin >> x >> r >> c; 
	if( r * c % x != 0 ) 
		return 0;
	if( r > c ) swap( r , c ) ;
	if( x <= 2 ) return 1; 

	if( r < (x+1)/2 ) return 0;
	if( c < x ) return 0;

	if( x == 3 ) return 1;
	if( x == 4 ) return ( r != 2 );
	if( x == 5 ) {
		if( r > 3 ) return 1;
		return 0;
	}
	if( x == 6 ) {
		if( r == 3 && c == 6 ) return 0;
		return 1;
	}
	return 0;
}

int main() { 
	int t;
	cin >> t;
	for( int i = 0 ; i < t; i++ ) 
		cout << "Case #" << i+1 << ": " << s[calc()] << endl;
}
