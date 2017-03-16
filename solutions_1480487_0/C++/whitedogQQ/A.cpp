#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#define MAXN 1000

using namespace std;

int v[ MAXN ] = { 0 };

int main()
{
	freopen( "A-small-attempt4.in", "r", stdin );
	freopen( "output2.txt", "w", stdout );
	int datacase, N, t = 0;;
	
	scanf( "%d", &datacase );
	
	while( datacase-- )
	{
		scanf( "%d", &N );
		int sum = 0, SaveSum;
		double need;
		double ans[ MAXN ] = { 0 };
		for( int i = 0; i < N; i++ )
		{
			scanf( "%d", &v[ i ] );
			sum += v[ i ];
		}
		SaveSum = sum;
		sum = sum*2;
		need = sum;

		need /= N;
		int Count = N;
		for( int i = 0; i < N; i++ )
		{
			if( v[ i ] > need )
			{
				sum -= v[ i ];
				Count--;
			}
		}
		need = (double)sum / (double)Count;
	//	printf( "%lf\n", need );
		printf( "Case #%d:", ++t );
		for( int i = 0; i < N; i++ )
		{	
			double now = (double)100*( need - (double)v[ i ] ) / (double)SaveSum;
			//printf( "aaa %lf ", now );
			if( now < 0 )
				printf( " 0.00000000"  );
			else
				printf( " %.8lf", now );
		}
		printf( "\n" );
	}

	return 0;
}
