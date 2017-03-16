#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <omp.h>
#include <functional>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

static const int MAXT = 10012;
#ifdef _DEBUG
static const int MAXLEN = 16;
#else
static const int MAXLEN = 106;
#endif

inline bool compare( const string &a, const string &b )
{
	return a.size() < b.size() || a.size() == b.size() && a < b;
}

vector< string > pal;

int Solve( const char a[], const char b[] )
{
	return upper_bound( pal.begin(), pal.end(), b, compare ) - lower_bound( pal.begin(), pal.end(), a, compare );
}

inline string flip( string x )
{
	reverse( x.begin(), x.end() );
	return x;
}

string sqr( const string &x )
{
	int i, j;
	string result( x.size() * 2 - 1, '0' );

	for( i = 0; i < ( int )x.size(); ++i )
	{
		for( j = 0; j < ( int )x.size(); ++j )
		{
			result[ i + j ] += ( x[ i ] - '0' ) * ( x[ j ] - '0' );
		}
	}
	return result;
}

void Init() 
{
	int i, a, b, c;

	pal.push_back( "1" );
	pal.push_back( "2" );
	pal.push_back( "3" );

	for( i = 1; i <= MAXLEN / 2; ++i )
	{
		string half( ( size_t )i, '0' );

		// 1
		half[ 0 ] = '1';

		pal.push_back( half + flip( half ) );
		pal.push_back( half + '0' + flip( half ) );
		pal.push_back( half + '1' + flip( half ) );
		pal.push_back( half + '2' + flip( half ) );

		for( a = 1; a < i; ++a )
		{
			half[ a ] = '1';

			pal.push_back( half + flip( half ) );
			pal.push_back( half + '0' + flip( half ) );
			pal.push_back( half + '1' + flip( half ) );
			pal.push_back( half + '2' + flip( half ) );

			for( b = a + 1; b < i; ++b )
			{
				half[ b ] = '1';

				pal.push_back( half + flip( half ) );
				pal.push_back( half + '0' + flip( half ) );
				pal.push_back( half + '1' + flip( half ) );

				for( c = b + 1; c < i; ++c )
				{
					half[ c ] = '1';

					pal.push_back( half + flip( half ) );
					pal.push_back( half + '0' + flip( half ) );
					pal.push_back( half + '1' + flip( half ) );

					half[ c ] = '0';
				}

				half[ b ] = '0';
			}
			half[ a ] = '0';
		}

		// 2
		half[ 0 ] = '2';

		pal.push_back( half + flip( half ) );
		pal.push_back( half + '0' + flip( half ) );
		pal.push_back( half + '1' + flip( half ) );
	}

	sort( pal.begin(), pal.end(), compare );

#pragma omp parallel for schedule(dynamic, 100)
	for( i = 0; i < ( int )pal.size(); ++i )
		pal[ i ].swap( sqr( pal[ i ] ) );

	//for( i = 0; i < ( int )pal.size(); ++i )
	//	printf( "%s\n", pal[ i ].c_str() );
}

int T;
char A[ MAXT ][ MAXLEN + 1 ], B[ MAXT ][ MAXLEN + 1 ];

void Read()
{
	int t;
	scanf( "%d", &T );
	for( t = 0; t < T; ++t )
	{
		scanf( "%s%s", A[ t ], B[ t ] );
	}
}

int Result[ MAXT ];

void Work()
{
#pragma omp parallel for schedule(dynamic, 1)
	for( int t = 0; t < T; ++t )
	{
		Result[ t ] = Solve( A[ t ], B[ t ] );
	}
}

void Write()
{
	int i;
	for( i = 0; i < T; ++i )
	{
		printf( "Case #%d: %d\n", i + 1, Result[ i ] );
	}
}

int main()
{
	Init();
	Read();
	Work();
	Write();
	return 0;
}
