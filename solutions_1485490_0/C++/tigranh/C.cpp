
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

vector< int > A;
vector< ull > a;
vector< int > B;
vector< ull > b;
vector< vector< ull > > x;

ull solve( 
		  int i, int j, 
		  bool id, bool jd )
{
	if ( i == 0 || j == 0 )
		return 0;
	if ( A[ i ] != B[ j ] )
	{
		if ( id ) 
			return max( x[ i - 1 ][ j ], solve( i, j - 1, true, false ) );
		else if ( jd )
			return max( solve( i - 1, j, false, true ), x[ i ][ j - 1 ] );
		else
			return max( x[ i - 1 ][ j ], x[ i ][ j - 1 ] );
	}
	else
	{
		if ( a[ i ] == 0 )
			return solve( i - 1, j, false, jd );
		if ( b[ j ] == 0 )
			return solve( i, j - 1, id, false );
		if ( a[ i ] == b[ j ] )
			return solve( i - 1, j - 1, false, false ) + a[ i ];

		//x[ i ][ j ] = x[ i - 1 ][ j - 1 ] + min( a[ i ], b[ j ] );
		if ( a[ i ] > b[ j ] )
		{
			ull last = b[ j ];
			a[ i ] -= last;
			b[ j ] -= last;
			ull result = solve( i, j - 1, true, false ) + last;
			a[ i ] += last;
			b[ j ] += last;
			return result;
			/*for ( int jj = j - 1; jj > 0; --jj )
			ull r = a[ i ] - b[ j ];
			ull rr = 0;
			{
				if ( B[ jj ] == B[ j ] )
					rr += b[ jj ];
				ull t = x[ i - 1 ][ jj - 1 ] + min( r, rr ) + min( a[ i ], b[ j ] );
				if ( t > x[ i ][ j ] )
					x[ i ][ j ] = t;
			}*/
		}
		else if ( b[ j ] > a[ i ] )
		{
			ull last = a[ i ];
			a[ i ] -= last;
			b[ j ] -= last;
			ull result = solve( i - 1, j, false, true ) + last;
			a[ i ] += last;
			b[ j ] += last;
			return result;
			/*for ( int ii = i - 1; ii > 0; --ii )
			ull r = a[ i ] - b[ j ];
			ull rr = 0;
			{
				if ( A[ ii ] == A[ i ] )
					rr += a[ ii ];
				ull t = x[ ii - 1 ][ j - 1 ] + min( r, rr ) + min( a[ i ], b[ j ] );
				if ( t > x[ i ][ j ] )
					x[ i ][ j ] = t;
			}*/
		}
		throw 0;
	}
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t )
	{
		int N, M;
		cin >> N >> M;
		A.clear();
		B.clear();
		a.clear();
		b.clear();
		A.resize( N + 1 );
		a.resize( N + 1 );
		B.resize( M + 1 );
		b.resize( M + 1 );
		for ( int i = 1; i <= N; ++i )
			cin >> a[ i ] >> A[ i ];
		for ( int i = 1; i <= M; ++i )
			cin >> b[ i ] >> B[ i ];
		x.clear();
		x.resize( N + 1, vector< ull >( M + 1, 0 ) );
		for ( int i = 1; i <= N; ++i )
		{
			for ( int j = 1; j <= M; ++j )
			{
				x[ i ][ j ] = solve( i, j, false, false );
				/*if ( A[ i ] != B[ j ] )
				{
					x[ i ][ j ] = max( x[ i - 1 ][ j ], x[ i ][ j - 1 ] );
				}
				else
				{
					x[ i ][ j ] = x[ i - 1 ][ j - 1 ] + min( a[ i ], b[ j ] );
					if ( a[ i ] > b[ j ] )
					{
						ull r = a[ i ] - b[ j ];
						ull rr = 0;
						for ( int jj = j - 1; jj > 0; --jj )
						{
							if ( B[ jj ] == B[ j ] )
								rr += b[ jj ];
							ull t = x[ i - 1 ][ jj - 1 ] + min( r, rr ) + min( a[ i ], b[ j ] );
							if ( t > x[ i ][ j ] )
								x[ i ][ j ] = t;
						}
					}
					else if ( b[ j ] > a[ i ] )
					{
						ull r = b[ j ] - a[ i ];
						ull rr = 0;
						for ( int ii = i - 1; ii > 0; --ii )
						{
							if ( A[ ii ] == A[ i ] )
								rr += a[ ii ];
							ull t = x[ ii - 1 ][ j - 1 ] + min( r, rr ) + min( a[ i ], b[ j ] );
							if ( t > x[ i ][ j ] )
								x[ i ][ j ] = t;
						}
					}
				}*/
			}
		}
		cout << "Case #" << t << ": " << x[ N ][ M ] << endl;
	}
	return 0;
}
