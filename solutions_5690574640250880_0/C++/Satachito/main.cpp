#include			<iostream>
#include    		<iomanip>
#include			<string>
using	namespace	std;

#include			<JpMooParaiso/Exceptions.h>
#include			<JpMooParaiso/Arithmetics.h>
using	namespace	JpMooParaiso;

char	map[ 52 ][ 52 ];	//	2 margin

struct
Case
{	size_t	r;
	size_t	c;
	size_t	m;
	
	bool	flipped;

	Case( size_t pR, size_t pC, size_t pM )	//
	:	r( pR )
	,	c( pC )
	,	m( pM )
	{	cout << r << ' ';
		cout << c << ' ';
		cout << m << ' ';
		cout << ( r * c - m ) << endl;
		assert( m < r * c );
	}

	Case( istream& p )	//
	{	p >> r;	//	cout << r << ' ';
		p >> c;	//	cout << c << ' ';
		p >> m;	//	cout << m << endl;

		assert( m < r * c );
	}
	
	void
	Err()
	{	for ( size_t y = 0; y < r + 2; y++ )
		{	for ( size_t x = 0; x < c + 2; x++ ) cout << map[ y ][ x ];
			cerr << endl;
		}
	}

	void
	Out()
	{	if ( flipped )
		{	size_t w = c;
			c = r;
			r = w;
			for ( size_t y = 1; y <= r; y++ )
			{	for ( size_t x = 1; x <= c; x++ ) cout << map[ x ][ y ];
				cout << endl;
			}
		}
		else
		{	for ( size_t y = 1; y <= r; y++ )
			{	for ( size_t x = 1; x <= c; x++ ) cout << map[ y ][ x ];
				cout << endl;
			}
		}
	}

	bool
	Solve()
	{	if ( r > c )
		{	size_t w = c;
			c = r;
			r = w;
			flipped = true;
		}
		else flipped = false;
	
		size_t	numSafe = r * c - m;
	
		for ( size_t y = 1; y <= r; y++ ) for ( size_t x = 1; x <= c; x++ ) map[ y ][ x ] = '*';
		for ( size_t y = 0; y <= r; y++ )
		{	map[ y     ][     0 ] = '-';
			map[ y + 1 ][ c + 1 ] = '-';
		}
		for ( size_t x = 0; x <= c; x++ )
		{	map[     0 ][ x + 1 ] = '-';
			map[ r + 1 ][ x     ] = '-';
		}
	
if ( numSafe == 1 )
{	cerr << "Trap! " << endl;
}
		map[ 1 ][ 1 ] = 'c';
		numSafe--;
		if ( numSafe == 0 ) return true;

		if ( r == 1 )
		{	size_t x = 2;
			while ( numSafe-- ) map[ 1 ][ x++ ] = '.';
			return true;
		}
//		if ( c == 1 )
//		{	size_t y = 2;
//			while ( numSafe-- ) map[ y++ ][ 1 ] = '.';
//			return true;
//		}

		if ( numSafe == 1 ) return false;
		if ( numSafe == 2 ) return false;

		if ( r == 2 )
		{	map[ 2 ][ 1 ] = '.';
			numSafe--;
			if ( numSafe % 2 ) return false;
			size_t x = 2;
			while ( numSafe )
			{	map[ 1 ][ x ] = '.';
				map[ 2 ][ x ] = '.';
				numSafe -= 2;
				x++;
			}
			return true;
		}

		map[ 1 ][ 2 ] = '.';
		map[ 2 ][ 1 ] = '.';
		map[ 2 ][ 2 ] = '.';
		numSafe -= 3;
		if ( numSafe == 0 ) return true;
		if ( numSafe == 1 ) return false;
		if ( numSafe == 3 ) return false;

		map[ 1 ][ 3 ] = '.';
		map[ 2 ][ 3 ] = '.';
		numSafe -= 2;
		if ( numSafe == 0 ) return true;
		if ( numSafe == 1 ) return false;
		map[ 3 ][ 1 ] = '.';
		map[ 3 ][ 2 ] = '.';
		numSafe -= 2;
		if ( numSafe == 0 ) return true;
		if ( numSafe == 1 )
		{	map[ 3 ][ 3 ] = '.';
			return true;
		}
//	OK
//Err();
		{	size_t	x = 3;
			while ( x++ < c )
			{	map[ 1 ][ x ] = '.';
				map[ 2 ][ x ] = '.';
				numSafe -= 2;
				if ( numSafe == 0 ) return true;
				if ( numSafe == 1 )
				{	map[ 3 ][ 3 ] = '.';
					return true;
				}
			}
		}
//Err();
		{	size_t	y = 3;
			while ( y++ < r )
			{	map[ y ][ 1 ] = '.';
				map[ y ][ 2 ] = '.';
				numSafe -= 2;
				if ( numSafe == 0 ) return true;
				if ( numSafe == 1 )
				{	map[ 3 ][ 3 ] = '.';
					return true;
				}
			}
		}
//Err();
		{	size_t	x = 3;
			size_t	y = 3;
			while ( y + 1 <= r )
			{	map[ y     ][ x ] = '.';
				map[ y + 1 ][ x ] = '.';
				numSafe -= 2;
				if ( numSafe == 0 ) return true;
				if ( numSafe == 1 )
				{	if ( x + 1 <= c )	map[ y     ][ x + 1 ] = '.';
					else				map[ y + 2 ][ 3     ] = '.';
					return true;
				}
				if ( ++x > c )
				{	y += 2;
					x = 3;
				}
			}
		}
//Err();
		{	size_t	x = 3;
			while ( numSafe-- )
			{	map[ r ][ x ] = '.';
				assert( x <= c );
				x++;
			}
		}
		return true;
	}
};


void
Main()
{	size_t	wNumCases;	cin >> wNumCases;
	for ( size_t i = 1; i <= wNumCases; i++ )
	{	cout << "Case #" << i << ":" << endl;
		Case wCase( cin );
		if ( wCase.Solve() )	wCase.Out();
		else					cout << "Impossible" << endl;
	}
}

void
Test()
{
#define	R	8
#define	C	8
	for ( size_t i = 0; i < R * C; i++ )
	{	Case wCase( R, C, i );
		if ( wCase.Solve() )	wCase.Out();
		else					cout << "Impossible" << endl;
	}
}

int
main( int argc, const char * argv[] )
{	N( freopen( argv[ 1 ], "r", stdin ) );
	N( freopen( argv[ 2 ], "w", stdout ) );
	Main();
	return 0;
}

