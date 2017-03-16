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

void solve()
{
	ull r, t;
	cin >> r >> t;
	ull l, u;
	l = 0;
	u = min( t / ( 2 * r - 1 ), (ull)(sqrt(t/2) )) + 1;
	ull res = -1, m;
	while( l <= u )
	{
	//	cout << l << ' ' << u << endl;
	    m = ( l + u ) / 2;
		if( m * ( 2 * r + 2 * m - 1 ) <= t )
		{
			l = m + 1;
			res = m;
		}
		else
			u = m - 1;
	}
	cout << res << endl;
}

void run()
{
//	openFiles( "A-small.in", "A-small.out" );
	openFiles( "A-large.in", "A-large.out" );
	int t;
	cin >> t;
	for( int i = 1; i <= t; ++i )
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}

int main() { run(); return 0; }