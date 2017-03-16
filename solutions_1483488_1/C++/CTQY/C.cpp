#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

inline void to_array( int x, int dignum, int dig[] )
{
	int i;

	for( i = dignum - 1; i >= 0; --i )
		{
		dig[i] = x % 10;
		x /= 10;
		}//end for
}//end to_array

inline int cmp( int dignum, const int dig_a[], const int dig_b[] )
{
	int i;

	for( i = 0; i < dignum; ++i )
		{
		if( dig_a[i] != dig_b[i] )
			{
			return dig_a[i] - dig_b[i];
			}//end if
		}//end for

	return 0;
}//end cmp

inline int calc_num( int dignum, const int dig[], int imin )
{
	int x = 0;
	int i;

	for( i = imin; i < dignum; ++i )
		{
		x *= 10;
		x += dig[i];
		}//end for

	for( i = 0; i < imin; ++i )
		{
		x *= 10;
		x += dig[i];
		}//end for

	return x;
}//end calc_num

inline int minimal( int dignum, const int dig[] )
{
	int min = 1000000000;
	int x;
	int i;

	for( i = 0; i < dignum; ++i )
		{
		x = calc_num( dignum, dig, i );
		if( x < min )
			{
			min = x;
			}//end if
		}//end for

	return min;
}//end minimal

inline bool inc( int dignum, int dig[] )
{
	int i = dignum - 1;
	++dig[i];

	while( dig[i] == 10 )
		{
		if( i == 0 ) return false;
		dig[i] = 0;
		--i;
		++dig[i];
		}//end while

	return true;
}//end inc

int main()
{
	freopen( "C.in", "r", stdin );
	freopen( "C.out", "w", stdout );

	static int num[2000004];
	static int dig_a[10];
	static int dig_b[10];
	static int dig[10];
	int t;
	int a, b;
	int dignum;
	int n;
	int i, j;

	scanf( "%d", &t );
	for( i = 1; i <= t; ++i )
		{
		scanf( "%d%d", &a, &b );
		dignum = static_cast<int>(ceil( log10( static_cast<double>(b) ) ) + 0.5 );
		to_array( a, dignum, dig_a );
		to_array( b, dignum, dig_b );
		memset( num, 0, sizeof( num[0] ) * (b+1) );

		memcpy( dig, dig_a, dignum * sizeof(dig[0]) );
		while( cmp( dignum, dig, dig_b ) <= 0 )
			{
			++num[minimal( dignum, dig )];
			if( !inc( dignum, dig ) ) break;
			}//end while

		// accumulate n
		n = 0;
		for( j = 1; j <= b; ++j )
			{
			if( num[j] >= 2 )
				{
				n += num[j] * (num[j] - 1) / 2;
				}//end if
			}//end for
		printf( "Case #%d: %d\n", i, n );
		}//end for
	return 0;
}
