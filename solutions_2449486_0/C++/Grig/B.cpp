#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;



string solve()
{
	int n, m;
	cin >> n >> m;
	string yes = "YES", no = "NO";
	vector<vector<int>> v( n );
	vector<int> maxrow( n, -1 );
	vector<int> maxcol( m, -1 );
	for( vector<int>& u : v )
	{
		u.resize( m );
		for( int& x : u )
			cin >> x;
	}
	int i, j;
	for( i = 0; i < n; ++i )
		for( j = 0; j < m; ++j )
			maxrow[ i ] = max( maxrow[ i ], v[ i ][ j ] );
	for( j = 0; j < m; ++j )
		for( i = 0; i < n; ++i )
			maxcol[ j ] = max( maxcol[ j ], v[ i ][ j ] );

	for( i = 0; i < n; ++i )
		for( j = 0; j < m; ++j )
			if( v[ i ][ j ] != min( maxrow[ i ], maxcol[ j ] ))
				return no;
	return yes;
}

int main()
{
	freopen( "B-small.in", "r", stdin );
	freopen( "B-small.out", "w", stdout );
	int t;
	cin >> t;
	for( int i = 1; i <= t; ++i )
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}