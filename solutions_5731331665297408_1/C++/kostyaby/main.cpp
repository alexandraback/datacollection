#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, p[ 55 ];
int graph[ 55 ][ 55 ];
string zip[ 55 ];
bool used[ 55 ], need[ 55 ], in_s[ 55 ];
string answer;
vector< int > order;

int prev( int v )
{
	if ( v == p[v] ) return v;
	p[v] = prev( p[v] );
	return p[v];
} 

void unite( int a, int b )
{
	a = prev( a );
	b = prev( b );
	if ( a != b ) 
	{
		p[a] = b;
	}
}

bool check()
{
	vector< int > s;
	s.push_back( order[ 0 ] );
	for ( int i = 1; i < order.size(); i++ )
	{
		int pos = order[i];
		while ( true )
		{
			if ( graph[ s.back() ][ pos ] == 1 )
			{
				s.push_back( pos );
				break;
			}
			if ( s.size() == 1 ) return false;
			s.pop_back();
		}
	}
	memset( in_s, 0, sizeof( in_s ) );
	for ( int i = 0; i < s.size(); i++ ) in_s[ s[i] ] = true;
	for ( int i = 0; i < n; i++ ) need[i] = ( used[i] ? false : true );
	for ( int i = 0; i < n; i++ ) p[i] = i;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
		{
			if ( !need[i] && !in_s[i] ) continue;
			if ( !need[j] && !in_s[j] ) continue;
			if ( !graph[i][j] ) continue;
			unite( i, j );
		}
	int num = prev( s[0] );
	for ( int i = 0; i < n; i++ )
	{
		if ( need[i] || in_s[i] )
			if ( num != prev( i ) ) return false;
	}
	return true;
}

void solve()
{
	memset( graph, 0, sizeof( graph ) );
	memset( used, 0, sizeof( used ) );
	order.clear();
	cin >> n >> m;
	answer = "";
	for ( int i = 0; i < n; i++ ) cin >> zip[i];
	for ( int i = 1; i <= m; i++ )
	{
		int a, b; cin >> a >> b;
		a--; b--;
		graph[a][b] = graph[b][a] = 1;
	}

	for ( int it = 0; it < n; it++ )
	{
		string add = "99999";
		int pos = -1;
		for ( int i = 0; i < n; i++ )
		{
			if ( used[i] ) continue;
			if ( zip[i] > add ) continue;
			order.push_back( i );
			used[i] = true;
			bool fl = check();
			used[i] = false;
			order.pop_back();
			if ( !fl ) continue;
			add = zip[i];
			pos = i;
		}
		used[ pos ] = true;
		answer += add;
		order.push_back( pos );
	}
	
	cout << answer << "\n";
}

int main (int argc, const char * argv[])
{
	int testcases; cin >> testcases;
	for ( int i = 1; i <= testcases; i++ )
	{
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;
}