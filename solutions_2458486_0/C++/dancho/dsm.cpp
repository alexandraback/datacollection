#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> sol;

int k, n;
vector<int> skey;
int tp[256];
vector<int> key[256];

int canSolve[1<<21];

int getDP( int ma, bool par )
{
	if ( ma == 0 )
		return true;
	if ( canSolve[ma] != -1 )
		return canSolve[ma];
	int fkey[256];
	memset( fkey, 0, sizeof( fkey ) );
	for ( int i = 0; i < n; i++ )
	{
		if ( !(ma&(1<<i)) )
		{
			fkey[ tp[i] ]--;
			for ( int j = 0; j < (int) key[i].size(); j++ )
				fkey[ key[i][j] ]++;
		}
	}
	
	for ( int i = 0; i < (int) skey.size(); i++ )
		fkey[ skey[i] ]++;
		
	for ( int i = 0; i < 210; i++ )
	{
		if ( fkey[i] < 0 )
		{
			if ( par )
				fprintf( stderr, "ASDKMASLMKd\n" );
			canSolve[ma] = 0;
			return canSolve[ma];
		}
	}
	
	for ( int i = 0; i < n; i++ )
	{
		if ( ( (ma&(1<<i)) ) && ( fkey[ tp[i] ] > 0 ) )
		{
			if ( getDP( ma-(1<<i), 1 ) )
			{
				canSolve[ma] = 1;
				return canSolve[ma];
			}
		}
	}
	canSolve[ma] = 0;
	return canSolve[ma];
}

int main()
{
	int i, j;
	int t, T;
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%d %d", &k, &n );
		memset( canSolve, -1, sizeof( canSolve ) );
		
		skey.clear();
		for ( i = 1; i <= k; i++ )
		{
			scanf( "%d", &j );
			skey.push_back( j );
		}
		
		for ( i = 0; i < n; i++ )
		{
			int cnt = 0;
			scanf( "%d %d", &tp[i], &cnt );
			key[i].clear();
			while ( cnt-- )
			{
				scanf( "%d", &j );
				key[i].push_back( j );
			}
		}
		
		printf( "Case #%d:", t );
		int ma = (1<<n)-1;
		if ( !getDP( ma, 0 ) )
		{
			printf( " IMPOSSIBLE" );
		}
		else
		{
			for ( i = 0; i < n; i++ )
			{
				int fkey[256];
				memset( fkey, 0, sizeof( fkey ) );
				for ( int ii = 0; ii < n; ii++ )
				{
					if ( !(ma&(1<<ii)) )
					{
						fkey[ tp[ii] ]--;
						for ( int j = 0; j < (int) key[ii].size(); j++ )
							fkey[ key[ii][j] ]++;
					}
				}
				
				for ( int ii = 0; ii < (int) skey.size(); ii++ )
					fkey[ skey[ii] ]++;
				
				
				for ( j = 0; j < n; j++ )
				{
					if ( ( ma&(1<<j) ) && ( getDP( ma-(1<<j), 0 ) ) && ( fkey[ tp[j] ] > 0 ) )
					{
						printf( " %d", j+1 );
						ma -= (1<<j);
						break;
					}
				}
			}
		}
		printf( "\n" );
	}
	return 0;
}
