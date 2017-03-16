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
#include <ctime>
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
void print( T& container )
{
	for( const typename T::value_type& x : container )
		cout << x;
}

void openFiles( const char* in, const char* out )
{
	freopen( in, "r", stdin );
	freopen( out, "w", stdout );
}

void recFill( map<vector<int>, int>& mp, vector<int> v, int k )
{
	if( v.size() == 3 )
	{
		sort( v.begin(), v.end());
		if( mp[ v ] == k - 1 )
			mp[ v ]++;
	}
	else
	{
		for( int i = 2; i <= 5; ++i )
		{
			v.push_back( i );
			recFill( mp, v, k );
			v.pop_back();
		}
	}
}

void recGet( map<vector<int>, int>& mp, vector<int> v, int x, int k )
{
	if( v.size() > 3 )
		return;
	if( x == 1 )
	{
		recFill( mp, v, k );
		return;
	}
	for( int i = 2; i <= 5; ++i )
		if( x % i == 0 )
		{
			v.push_back( i );
			recGet( mp, v, x / i, k );
			v.pop_back();
		}
}

void solve()
{
	int r, n, m, k;
	cin >> r >> n >> m >> k;
	int i, x;
	while( r-- )
	{
		map<vector<int>, int> mp;
		for( i = 0; i < k; ++i )
		{
			cin >> x;
			recGet( mp, vector<int>(), x, i + 1 );
		}
		vector<vector<int>> v;
		for( map<vector<int>,int>::iterator it = mp.begin(); it != mp.end(); ++it )
			if( it->second == k )
				v.push_back( it->first );
		
		print( v[ rand() % v.size() ] );
		cout << endl;
	}
}

void run()
{
	openFiles( "C-small.in", "C-small.out" );
//	openFiles( "C-large.in", "C-large.out" );
	srand( time( 0 ));
	int t;
	cin >> t;
	for( int i = 1; i <= t; ++i )
	{
		cout << "Case #" << i << ":\n";
		solve();
	}
}

int main() { run(); return 0; }