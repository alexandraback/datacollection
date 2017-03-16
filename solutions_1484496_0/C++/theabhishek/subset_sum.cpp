#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
#define MAX 20
#define SUM_MAX 2000000
int A[MAX+5];
int B[MAX+5];

vector<int> sum[SUM_MAX+5];

void performtest(){
	int i, j, k, temp_sum, N, M;
	scanf( "%d", &N );
	
	for( i=0; i<N; i++ )
		scanf( "%d", A + i );
	
	for( i=0; i<SUM_MAX+5; i++ )
		sum[i].erase( sum[i].begin(), sum[i].end() );
	temp_sum = 0;
	for( i=0; i< (2<<N); i++ ){
		temp_sum = 0;
		for( j=0; j<N; j++ )
			if( (1<<j) & i )
				temp_sum += A[j];
		for( j=0; j<sum[temp_sum].size(); j++ )
			if( ( ( sum[temp_sum].at(j) ) & i ) == 0 ){
				for( k=0; k<N; k++ )
					if( 1<<k & i )
						printf( "%d ", A[k] );
				printf( "\n" );
				for( k=0; k<N; k++ )
					if( 1<<k & sum[temp_sum].at(j) )
						printf( "%d ", A[k] );
				printf( "\n" );
				return;
			}
		sum[ temp_sum ].push_back( i );
		/*printf( "For %d: ", temp_sum );
		for( j=0; j<sum[temp_sum].size(); j++ )
			printf( "%d ", sum[temp_sum].at(j) );
		printf( "\n" );*/
	}
	
	printf( "Impossible\n" );
	
}

int main(){
	int tests;
	scanf( "%d", &tests );
	for( int i=1; i<=tests; i++ ){
		printf( "Case #%d:\n", i );
		performtest();
	}
	return 0;
}