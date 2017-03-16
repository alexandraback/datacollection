#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int m[1<<12];
int a;

int main()
{
	int t, T;
	int i, k;
	scanf( "%d", &T );
	int ans;
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%d %d", &a, &n );
		for ( i = 1; i <= n; i++ )
			scanf( "%d", &m[i] );
		sort( m + 1, m + n + 1 );
		
		ans = n;
		k = 0;
		if ( a != 1 )
		{
			for ( i = 1; i <= n; i++ )
			{
				while ( a <= m[i] )
				{
					a = a + (a-1);
					k++;
				}
				a += m[i];
				if ( k + (n-i) < ans )
					ans = k + (n-i);
			}
		}
		
		printf( "Case #%d: %d\n", t, ans );
	}
	return 0;
}
