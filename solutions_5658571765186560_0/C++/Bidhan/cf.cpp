#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("bid","r",stdin);
	freopen("bidhan","w",stdout);
	int test,kas=0;
	cin >> test;
	while( test-- ) {
		int x, r, c;
		cin >> x >> r >> c;
		
		auto ok = "GABRIEL";
		if( x >= 7 ) ok = "RICHARD";
		else if( x > r && x > c ) ok = "RICHARD";
		else if( ( r * c ) % x ) ok = "RICHARD";
		else if( ( x + 1 ) / 2 > min( r, c ) ) ok = "RICHARD";
		else if( x == 4 && !( min( r, c ) > 2 ) ) ok = "RICHARD";
		else if( x == 5 && ( min( r , c ) == 3 && max( r , c ) == 5 ) ) ok = "RICHARD";
		else if( x == 6 && !( min( r , c ) > 3 ) ) ok = "RICHARD";
		
		cout << "Case #" << ++kas << ": " << ok << endl;
	}
	return 0;
}
