
#include <iostream>
#include <vector>

using namespace std;

bool dfs( int n, const vector< vector< int > >& a, int p, vector< bool >& m )
{
	if ( m[ p ] )
		return true;
	m[ p ] = true;
	for ( int i = 0; i < (int)a[ p ].size(); ++i )
	{
		int b = a[ p ][ i ];
		if ( dfs( n, a, b, m ) )
			return true;
	}
	return false;
}

bool dfs( int n, const vector< vector< int > >& a, int p )
{
	vector< bool > m( n + 1, false );
	return dfs( n, a, p, m );
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t )
	{
		int N;
		cin >> N;
		vector< vector< int > > a;
		a.resize( N + 1 );
		for ( int i = 1; i <= N; ++i ) {
			int M;
			cin >> M;
			while ( M-- ) {
				int k;
				cin >> k;
				a[ i ].push_back( k );
			}
		}
		int k;
		for ( k = 1; k <= N; ++k )
			if ( dfs( N, a, k ) )
				break;
		cout << "Case #" << t << ": ";
		if ( k <= N )
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
	return 0;
}
