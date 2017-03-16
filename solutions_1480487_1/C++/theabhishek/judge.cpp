#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define MAX 200
double S[MAX+5];

bool check( double val, int idx, double sum, int N ){
	double point = S[idx] + val*sum;
	double left = 1.0 - val;
	
	int i;
	for( i=0; i<N; i++ ){
		if( i != idx && S[i] < point ){
			left -= ( point - S[i] )/sum;
			if( left < 0.0 )
				return true;
		}
	}
	return false;
}

bool compare( float a, float b ){
	return ( !( a > b ) );
}

void performtest(){
	int i, j, N;
	double sum = 0;
	scanf( "%d", &N );
	for( i=0; i<N; i++ ){
		scanf( "%lf", S + i );
		sum += S[i];
	}
		
	for( i=0; i<N; i++ ){
		double low = 0.0, high = 1.0, mid;
		while( abs(high - low) > 0.000000001 ){
			mid = ( low + high )/2.0;
			if( check( mid, i, sum, N ) )
				high = mid;
			else
				low = mid + 0.000000001;
		}
		
		printf( " %lf", low*100.0 );
	}
	printf( "\n" );
}

int main(){
	int tests;
	scanf( "%d", &tests );
	for( int i=1; i<=tests; i++ ){
		printf( "Case #%d:", i );
		performtest();
	}
	return 0;
}