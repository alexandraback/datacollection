#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAXN 3000000
using namespace std;

int n, A, B;
int used[ MAXN ] = { 0 };

int Check( int num )
{
	char s[ 100 ] = { 0 }, tmp[ 100 ] = { 0 }, cnt = 1, save = num;
	for( int i = 0; num ; num /= 10, i++ )
		tmp[ i ] = num % 10 + '0' ;
	int len = strlen( tmp );
	for( int i = 0; tmp[ i ]; i++ )
		s[ len-i-1 ] = tmp[ i ];
	for( int i = 0; i < len; i++ )
	{
		int now = atoi( s+i );
		if( now >= A && now <= B && !used[ now ] )
		{
			used[ now ] = 1;
			cnt++;
		}
		s[ i+len ] = s[ i ];
	}
	return cnt * ( cnt-1 ) / 2;
}

int main()
{
	freopen( "C-small-attempt1.in", "r", stdin );
	freopen( "Output_C.txt", "w", stdout );
	int t = 0;
	scanf( "%d", &n );
	while ( n-- )
	{
		int ans = 0;
		memset( used, 0, sizeof( used ) );
		scanf( "%d%d", &A, &B );
		for( int i = A; i <= B; i++ )
		{
			if( !used[ i ] )
			{
				used[ i ] = 1;
				ans += Check( i );
			}
		}	
		printf( "Case #%d: %d\n", ++t, ans );
	}
	return 0;	
}
