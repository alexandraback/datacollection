#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

char m[ 1000 ] = { 0 };

void BuildMap( char I[], char M[] )
{
	for( int i = 0; i < strlen( I ); i++ )
	{
		m[ I[ i ] ] = M[ i ];
	}
}

int main()
{
	freopen( "A-small-attempt1.in", "r", stdin );
	freopen( "Output_A.txt", "w", stdout );
	char I1[ 100 ] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	char I2[ 100 ] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	char I3[ 100 ] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	
	char M1[ 100 ] = "our language is impossible to understand";
	char M2[ 100 ] = "there are twenty six factorial possibilities";
	char M3[ 100 ] = "so it is okay if you want to just give up";	
	
	BuildMap( I1, M1 );
	BuildMap( I2, M2 );
	BuildMap( I3, M3 );	
	m[ 'z' ] = 'q';
	m[ 'q' ] = 'z';
	int n, t = 0;
	char s[ 10000 ] = { 0 };
	scanf( "%d\n", &n );
	for( int i = 0; i < n; i++ )
	{
		char New[ 10000 ] = { 0 };		
		gets( s );
		printf( "Case #%d: ", ++t );
		for( int i = 0; i < strlen( s ); i++ )
		{
			//New[ i ] = m[ s[ i ] ];
			printf( "%c", m[ s[ i ] ] );
		}
		//New[ strlen( s ) ] = '\n';
		//printf( "%s", New );
		printf( "\n" );
	}
	
	
	return 0;
}
