#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
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

template<class T>
void read( T& container )
{
	for( typename T::value_type& x : container )
		cin >> x;
}

template<class T>
void print( T& container, const char separator = ' ' )
{
	for( typename T::value_type& x : container )
		cout << x << separator;
}

void openFiles( const char* in, const char* out )
{
	freopen( in, "r", stdin );
	freopen( out, "w", stdout );
}

const int maxn = 20;
int dp[ maxn ][ maxn ];
int a[ maxn ];

void solve()
{
	int e, r, n;
	int i, j, k;
	cin >> e >> r >> n;
	for( i = 0; i < n; ++i )
		cin >> a[ i ];
	for( j = 0; j <= e; ++j )
		dp[ n - 1 ][ j ] = a[ n - 1 ] * j;

	for( i = n - 2; i >= 0; --i )
		for( j = 0; j <= e; ++j )
		{
			dp[ i ][ j ] = 0;
			for( k = 0; k <= j; ++k )
				dp[ i ][ j ] = max( dp[ i ][ j ],  dp[ i + 1 ][ min( e, j - k + r ) ]  + k * a[ i ]);
		}
	cout << dp[ 0 ][ e ] << endl;
}

void run()
{
	openFiles( "B-small.in", "B-small.out" );
//	openFiles( "B-large.in", "B-large.out" );
	int t;
	cin >> t;
	for( int i = 1; i <= t; ++i )
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}

int main() { run(); return 0; }