
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void deduce( int N, const vector< int >& a, const vector< int >& p, int index, vector< int >& r )
{
	r.clear();
	while ( true )
	{
		r.push_back( a[ p[ index ] ] );
		int i2 = index - a[ p[ index ] ];
		if ( index == 0 )//i2 == index || p[ i2 ] == -1 )
			break;
		index = i2;
	}
}

void print( const vector< int >& a )
{
	for ( int i = 0; i < (int)a.size(); ++i )
	{
		if ( i > 0 )
			cout << " ";
		cout << a[ i ];
	}
	cout << endl;
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t )
	{
		int N;
		cin >> N;
		vector< int > a;
		a.resize( N );
		for ( int i = 0; i < N; ++i )
			cin >> a[ i ];
		vector< int > p( 20 * 100000 + 100, -1 );
		sort( a.begin(), a.end() );
		vector< int > x, y;
		p[ 0 ] = 0;
		for ( int i = 0; i < N; ++i )
		{
			for ( int j = p.size() - 1 - a[ i ]; j >= 0; --j )
				if ( p[ j ] >= 0 ) {
					if ( p[ j + a[ i ] ] >= 0 ) {
						deduce( N, a, p, j + a[ i ], x );
						p[ j + a[ i ] ] = i;
						deduce( N, a, p, j + a[ i ], y );
						break;
					}
					p[ j + a[ i ] ] = i;
				}
			if ( ! x.empty() || ! y.empty() )
				break;
		}
		cout << "Case #" << t << ":" << endl;
		if ( ! x.empty() || ! y.empty() )
		{
			sort( x.begin(), x.end() );
			sort( y.begin(), y.end() );
			vector< int > x2, y2;
			set_difference( x.begin(), x.end(), y.begin(), y.end(), back_inserter( x2 ) );
			set_difference( y.begin(), y.end(), x.begin(), x.end(), back_inserter( y2 ) );
			print( x2 );
			print( y2 );
		}
		else
			cout << "Impossible" << endl;
	}
	return 0;
}
