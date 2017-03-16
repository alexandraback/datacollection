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

int comp( const void * i1, const void * i2 ) {
	return (*(int*)i1 - *(int*)i2);
}

vector<vector<int> > table;

int solve( const int * const mot, int size, int& A, bool del ) {
	if( size == 0 ) return 0;
	else {
		int idel=0, indel;
		int A1 = A, A2 = A;
		if ( del ) {
			idel = solve( mot, size-1, A1, true );
		}
		indel = solve( mot, size-1, A2, false );
		
		int i = 0;
		while ( A2 <= mot[size-1] && i < 24 ) {
			A2 += A2 - 1;
			i++;
		}
		
		if ( del && idel+1 > indel + i || !del ) {
			A = A2 > mot[size-1] ? A2+mot[size-1] : A2;
			return indel+i;
		} else {
			for( int kj = 0; kj < size; kj++ ) {
				cout << mot[kj] << " ";
			}
			cout << endl;
			A = A1;
			return idel+1;
		}
		
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
		table.clear();
		
		int A, N;
		f >> A >> N;
		
		table.resize(N);
		
		int * mot = new int [N];
		for ( int i = 0; i < N; i++ ) {
			f >> mot[i];
		}
		
		qsort( mot, N, sizeof(int), comp );
		
		//int min = 100000;
		//for( int j = N-1; j >= 0; j-- ) {
			//int i = 0, k1 = 0;
			//int ops = N-1-j;
			//const int k = 8;
			
			//while( A <= mot[j] && k1 <= k ) {
				
				
				//while( A > mot[i] && i <= j ) {
					//A += mot[i];
					//i++;
				//}
				
				//if ( A <= mot[i] && i <= j ) {
					//A += A-1;
					//ops++;
				//}
				//k1++;
				
				
			//}
			//if ( A > mot[j] ) min = min > ops ? ops : min;
		//}
		
		//if ( min == 100000 ) min = N;
		fprintf( g, "Case #%d: %d\n", num1+1, solve(mot,N,A,true) );
		
		delete[] mot;
	}
	
	fclose(g);
	f.close();
}
