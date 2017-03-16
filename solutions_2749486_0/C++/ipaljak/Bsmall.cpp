#include <cstdio>
#include <string>

using namespace std;

int T, X, Y;

inline void solve( int t ){

	scanf( "%d%d", &X, &Y );
	string sol = "";
	
	if ( X < 0 ) {
		for ( int i = 0; i < (-1) * X; ++i ) sol += "EW";
	}

	if ( X > 0 ) {
		for ( int i = 0; i < X; ++i ) sol += "WE";
	}
	
	if ( Y < 0 ) {
		for ( int i = 0; i < (-1) * Y; ++i ) sol += "NS";
	}
	
	if ( Y > 0 ) {
		for ( int i = 0; i < Y; ++i ) sol += "SN";
	}
	
	printf( "Case #%d: ", t );
	for ( int i = 0; i < sol.size(); ++i ) printf( "%c", sol[i] );
	printf( "\n" ); 

}

int main( void ){

	scanf( "%d", &T );	
	for ( int i = 0; i < T; ++i ) solve( i + 1 ); 

	return 0;

}
