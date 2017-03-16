#include <cstdio>
#include <fstream>
#include <algorithm>

using namespace std;

FILE *fin = fopen( "A.in", "r" );
FILE *fout = fopen( "A.out", "w" );

int T, curr, N;
int niz[101];

void solve( int t ){

	scanf( "%d%d", &curr, &N );
	for ( int i = 0; i < N; ++i ) scanf( "%d", &niz[i] );
	
	sort( niz, niz + N );
	
	int el = 0;
	int sol = 10000000, currBest = 0;
	
	while ( el < N ){
	
		printf( "MIRKO" );
		
		while ( el < N && curr > niz[el] ) curr += niz[el++];
		if ( el >= N ){ sol = min( sol, currBest ); break; }
		
		sol = min( sol, currBest + ( N - el ) ); // probaj maknuti sve
		 
		if ( curr - 1 == 0 ) break; 
		while ( curr <= niz[el] ){ curr += curr - 1; ++currBest; }
		
	}
	
	fprintf( fout, "Case #%d: %d\n", t, sol ); 
	
}

int main( void ){
	
	scanf(  "%d", &T ); printf( "-- %d --\n", T );
	for ( int i = 0; i < T; ++i ) solve( i + 1 ); 
	
	return 0;	
	
}	
