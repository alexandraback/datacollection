#include <cstdio>
#include <cstring>
#include <set>
#include <utility>
using namespace std;

int n, m;
int he[256][256];

int mxhr[256], mxhc[256];

set<pair<int,int> > S[256];

int main()
{
	int t, T;
	int i, j, k;
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%d %d", &n, &m );
		memset( mxhc, -1, sizeof( mxhc ) );
		memset( mxhr, -1, sizeof( mxhr ) );
		for ( i = 1; i <= 200; i++ )
			S[i].clear();
		for ( i = 1; i <= n; i++ )
		{
			for ( j = 1; j <= m; j++ )
			{
				scanf( "%d", &he[i][j] );
				if ( he[i][j] > mxhr[i] )
					mxhr[i] = he[i][j];
				if ( he[i][j] > mxhc[j] )
					mxhc[j] = he[i][j];
				
				S[ he[i][j] ].insert( make_pair( i, j ) );
			}
		}
		
		for ( k = 1; k <= 200; k++ )
		{
			for ( i = 1; i <= n; i++ )
			{
				if ( mxhr[i] == k )
				{
					for ( j = 1; j <= m; j++ )
					{
						S[k].erase( make_pair( i, j ) );
					}
				}
			}

			for ( i = 1; i <= m; i++ )
			{
				if ( mxhc[i] == k )
				{
					for ( j = 1; j <= n; j++ )
					{
						S[k].erase( make_pair( j, i ) );
					}
				}
			}
			
			if ( (int) S[k].size() > 0 )
				break;
		}
		
		printf( "Case #%d: %s\n", t, k <= 200 ? "NO" : "YES" );
	}
	return 0;
}
