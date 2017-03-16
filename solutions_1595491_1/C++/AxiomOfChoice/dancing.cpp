#include <cstdio>

using namespace std;

int T, N, S, p, s;

int main()
{
	scanf( "%d", &T );
	for( int t = 1; t <= T; t++ )
	{
		scanf( "%d%d%d", &N, &S, &p );
		int ans = 0;
		for( int i = 0; i < N; i++ )
		{
			scanf( "%d", &s );
			int q = s / 3;
			switch( s % 3 )
			{
				case 0:
					if( q >= p ) ans++;
					else if( q > 0 && q + 1 >= p && S ) ans++, S--;
					break;
				case 1:
					if( q + 1 >= p ) ans++;
					break;
				case 2:
					if( q + 1 >= p ) ans++;
					else if( q + 2 >= p && S ) ans++, S--;
					break;
			}
		}
		printf( "Case #%d: %d\n", t, ans );
	}
	return 0;
}
