#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>


using namespace std;

int choose ( int n, int k ) {
	if( k > n ) return 0;
	else {
		int i = 1;
		for ( int j = 0; j < k; j++ ) {
			i = i*(n-j);
		}
		return i;
	}
}

int main ( int argn, const char * argv[] ) {
	ifstream f;
	f.open( argv[1] );
	
	FILE * g;
	g = fopen( argv[2], "w" );
	
	int num;
	f >> num;
	
	for ( int num1 = 0; num1 < num; num1++ ) {
		// megoldas
		int N, X, Y;
		f >> N >> X >> Y;
		
		double p = 0;
		if ( abs(X)+Y > 6 ) {;
		} else if ( X+Y == 0 ) {
			p = 1.0;
		} else if ( N <= 8 ) {
			switch (N) {
				case 2: if ( X+Y == 2 && X*Y == 0 ) p = 0.5; break;
				case 3: if ( X+Y == 2 && X*Y == 0 ) p = 0.75;
					else if ( abs(X) == 1 && Y == 1 ) p = 0.25;
					break;
				case 4: if ( abs(X) == 2 && Y == 0 ) p = 1.0;
					else if ( abs(X) == 1 && Y == 1 ) p = 0.5;
					break;
				case 5: if ( abs(X) == 2 && Y == 0 ) p = 1.0;
					else if ( abs(X) == 1 && Y == 1 ) p = 1.0;
					break;
				case 6:	if ( abs(X) == 2 && Y == 0 ) p = 1.0;
					else if ( abs(X) == 1 && Y == 1 ) p = 1.0;
					else if ( abs(X) == 0 && Y == 2 ) p = 1.0;
					break;
				case 7: if ( abs(X) == 2 && Y == 0 ) p = 1.0;
					else if ( abs(X) == 1 && Y == 1 ) p = 1.0;
					else if ( abs(X) == 0 && Y == 2 ) p = 1.0;
					else if ( abs(X) == 4 && Y == 0 ) p = 0.5;
					break;
				case 8: if ( abs(X) == 2 && Y == 0 ) p = 1.0;
					else if ( abs(X) == 1 && Y == 1 ) p = 1.0;
					else if ( abs(X) == 0 && Y == 2 ) p = 1.0;
					else if ( abs(X) == 4 && Y == 0 ) p = 0.75;
					else if ( abs(X) == 3 && Y == 1 ) p = 0.25;
					break;
				//case 9: if ( abs(X) == 2 && Y == 0 ) p = 1.0;
					//else if ( abs(X) == 1 && Y == 1 ) p = 1.0;
					//else if ( abs(X) == 0 && Y == 2 ) p = 1.0;
					//else if ( abs(X) == 4 && Y == 0 ) p = 0.875;
					//else if ( abs(X) == 3 && Y == 1 ) p = 0.25;
					//break;
				default: break;
			} }else if ( N <= 15 ) {
				if ( abs(X)+Y <= 2 ) {p = 1.0;}
				else if ( Y > N-7 ) {;}
				else {
					int n = N - 6;
					for( int k = 0; k < n; k++ ) {
						p=choose(n,Y-1)*pow(0.5,n);
					}
				}
			} else {
				if ( abs(X)+Y <= 4 ) p = 1.0;
				
				else if ( Y > N-16 ) ;
				else {
					int n = N - 15;
					for( int k = 0; k < n; k++ ) {
						p=choose(n,Y-1)*pow(0.5,n);
					}
				}
			}
			
			
		
		fprintf( g, "Case #%d: %.6f\n", num1+1, p );
	}
	
	fclose(g);
}
