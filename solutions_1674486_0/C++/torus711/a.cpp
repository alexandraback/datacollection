#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP( i, m, n ) for ( int i = (int)m; i < (int)n; i++ )
#define UREP( i, m, n ) for ( unsigned int i = (unsigned int)m; i < (unsigned int)n; i++ )
#define ITER( c ) __typeof( (c).begin() )
#define IREP( c, it ) for ( ITER(c) it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()
#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( a, b )
#define fst first
#define snd second

int main()
{
	int t;
	cin >> t;

	REP( ti, 0, t )
	{
		int n;
		cin >> n;

		vector< vector<int> > path;

		REP( i, 0, n )
		{
			int m;
			cin >> m;

			path.PB( vector<int>() );

			REP( j, 0, m )
			{
				int in;
				cin >> in;
				path[i].PB( in - 1 );
			}
		}

		bool flag = false;

		REP( i, 0, n )
		{
			map<int,int> res;
			queue<int> qu;
			set<int> done;

			qu.push( i );

			while( !qu.empty() )
			{
				int curr = qu.front();
				qu.pop();
				
				if ( done.find( curr ) != done.end() )
				{
					continue;
				}

				REP( j, 0, path[ curr ].size() )
				{
					qu.push( path[curr][j] );
					res[ path[curr][j] ]++;
					done.insert( curr );
				}
			}

			IREP( res, it )
			{
				if ( 2 <= (*it).snd )
				{
					flag = true;
				}
			}
		}

		printf("Case #%d: %s\n", ti + 1, ( flag ? "Yes" : "No" ) );
	}

	return 0;
}