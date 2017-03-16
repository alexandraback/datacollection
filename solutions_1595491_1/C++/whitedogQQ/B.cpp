#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 1000

using namespace std;
typedef struct NUM
{
	int n;
	float avg1, avg2;
};

NUM num[ MAXN ];
int N, S, P;

bool cmp( NUM a, NUM b )
{
	return a.n > b.n;
};

int main()
{
	freopen( "B-large.in", "r", stdin );
	freopen( "output_B_Large.txt", "w", stdout );
	int T, t = 0;
	scanf( "%d", &T );
	while( T-- )
	{
		int ans = 0;
		scanf( "%d%d%d", &N, &S, &P );
		for( int i = 0; i < N; i++ )
		{
			scanf( "%d", &num[ i ].n );
			num[ i ].avg1 = ( float ) num[ i ].n / 3;
			num[ i ].avg2 = ( float ) ( num[ i ].n - P ) / 2;
		}
		sort( num, num+N, cmp );
		for( int i = 0, j = 0; i < N; i++ )
		{
			if( num[ i ].avg1 >= P )
			{
				ans++;
			}
			else if( num[ i ].avg1 < P && num[ i ].avg2 >= P-1 )
			{
				ans++;
			}
			else
			{
				if( j >= S )
					break;				
				if( num[ i ].avg2 >= 0 && P - num[ i ].avg2 <= 2  )
				{
					ans++;
					j++;
				}
			}
		}
		printf( "Case #%d: %d\n", ++t, ans );
	}
	return 0;
}
