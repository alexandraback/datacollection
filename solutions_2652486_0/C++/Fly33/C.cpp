#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <omp.h>
#include <functional>
#include <algorithm>
#include <cctype>
#include <set>
#include <map>
using namespace std;

int R, N, M, K;

int P[ 12 ];

void Read()
{
	scanf( "%d%d%d%d", &R, &N, &M, &K );
}

void Work( int test )
{
	int i, j, k;
	map< int, set< int > > pd;

	for( i = 2; i <= M; ++i )
	{
		for( j = i; j <= M; ++j )
		{
			for( k = j; k <= M; ++k )
			{
				set< int > & pds = pd[ ( i * 10 + j ) * 10 + k ];
				pds.insert( 1 );
				pds.insert( i );
				pds.insert( j );
				pds.insert( k );
				pds.insert( i * j );
				pds.insert( i * k );
				pds.insert( j * k );
				pds.insert( i * j * k );
			}
		}
	}

	printf( "Case #%d:\n", test );
	for( i = 0; i < R; ++i )
	{
		for( k = 0; k < K; ++k )
		{
			scanf( "%d", &P[ k ] );
		}

		for( map< int, set< int > >::const_iterator pd_it = pd.begin(); pd_it != pd.end(); ++pd_it )
		{
			for( k = 0; k < K; ++k )
			{
				if( pd_it->second.find( P[ k ] ) == pd_it->second.end() )
					break;
			}
			if( k < K )
				continue;
			printf( "%d\n", pd_it->first );
			break;
		}
	}
}

int main()
{
	int i, t;
	scanf( "%d", &t );
	for( i = 0; i < t; ++i )
	{
		Read();
		Work( i + 1 );
	}
	return 0;
}
