#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std; using namespace placeholders;

using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using SS = stringstream;
using PII = pair<int,int>;
using VPII = vector< pair<int,int> >;
template < typename T = int > using VT = vector<T>;
template < typename T = int > using VVT = VT< VT<T> >;
template < typename T = int > using LIM = numeric_limits<T>;

template < typename T > inline T fromString( const string &s ){ T res; istringstream iss( s ); iss >> res; return res; };
template < typename T > inline string toString( const T &a ){ ostringstream oss; oss << a; return oss.str(); };

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )
#define FOR( e, c ) for ( auto &e : c )
#define ALL( c ) (c).begin(), (c).end()
#define AALL( a, t ) (t*)a, (t*)a + sizeof( a ) / sizeof( t )
#define DRANGE( c, p ) (c).begin(), (c).begin() + p, (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

void dfs( const VVI &G, VI &used, VT<bool> &visited, const int v, const int p )
{
	visited[v] = true;
	FOR( u, G[v] )
	{
		if ( u == p || used[u] == 2 || visited[u] )
		{
			continue;
		}
		dfs( G, used, visited, u, v );
	}

	return;
}

bool validAddition( const int N, const int M, const VVI &G, const int root, VI used, stack<int> stk, const int v )
{
	while ( !stk.empty() && !binary_search( ALL( G[ stk.top() ] ), v ) )
	{
		used[ stk.top() ] = 2;
		stk.pop();
	}

	if ( stk.empty() )
	{
		return false;
	}

	VT<bool> visited( N );
	dfs( G, used, visited, root, -1 );
	REP( v, 0, N )
	{
		if ( used[v] != 2 && !visited[v] )
		{
			return false;
		}
	}
	return true;
}

string solve( const int N, const int M, const VS &ZIP, const VVI &G )
{
	VI cities( N );
	iota( ALL( cities ), 0 );
	sort( ALL( cities ), [&]( const int a, const int b ){ return ZIP[a] < ZIP[b]; } );
	const int root = cities[0];

	VI used( N );
	used[ root ] = 1;

	string res( ZIP[ root ] );

	stack<int> stk;
	stk.push( root );

	REP( iteration, 1, N )
	{
		bool done = false;
		FOR( i, cities )
		{
			if ( done || used[i] || !validAddition( N, M, G, root, used, stk, i ) )
			{
				continue;
			}

			used[i] = 1;
			res += ZIP[i];
			done = true;

			while ( !binary_search( ALL( G[ stk.top() ] ), i ) )
			{
				used[ stk.top() ] = 2;
				stk.pop();
			}
			stk.push( i );
		}
	}

	return res;
}

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int t;
	cin >> t;

	REP( i, 0, t )
	{
		int n, m;
		cin >> n >> m;

		VS zip( n );
		FOR( z, zip )
		{
			cin >> z;
		}

		VVI G( n );
		REP( iteration, 0, m )
		{
			int a, b;
			cin >> a >> b;
			a--, b--;

			G[a].PB( b );
			G[b].PB( a );
		}
		FOR( V, G )
		{
			sort( ALL( V ) );
		}

		cout << "Case #" << i + 1 << ": " << solve( n, m, zip, G ) << endl;
	}

	return 0;
}
