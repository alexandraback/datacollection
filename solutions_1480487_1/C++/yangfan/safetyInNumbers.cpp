#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	
	int T, N; 
	
	int s[201];
	
	scanf( "%d\n", &T );
	
	for ( int t = 0; t < T; t ++ ) {
		
		scanf( "%d ", &N );
		
		double X = 0;
			
		for ( int n = 0; n < N; n ++ ) {
			scanf( "%d ", &s[n] );
			X = X + s[n];
		}
		
		printf( "Case #%d: ", t + 1);
		
		double average = 2 * X / N;
		int count = 0;
		int taken = 0;
		
		for ( int n = 0; n < N; n ++ ) {
			if ( s[n] >= average ) {
				count ++;
				taken = taken + s[n];
			}
		}
		
		average = ( X * 2 - taken ) / ( N - count);
		
		for ( int n = 0; n < N; n ++ ) {
			double yi;
			
			if ( s[n] >= average) {
				yi = 0;
			} else {
				yi = (average - s[n]) / X * 100;
			}
			
			printf( "%f ",  yi);		
		}
		
		printf( "\n" );
		
	}
	
	return 0;
}