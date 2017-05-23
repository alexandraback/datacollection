#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MAXSIZE 1200
using namespace std ;
bool testF( int a )
{
	char Now[ 20 ] ;
	int Len ;
	bool Fair = 1 ;
	sprintf( Now , "%d" , a ) ;
	Len = strlen( Now ) ;
	for( int i = 0 ; i < Len/2 ; i++ )
		if( Now[ i ] != Now[ Len-1-i ] )
			Fair = 0 ;
	return Fair ;
}
int main( )
{
	int t , T = 1 ;
	int a , b = 0 , Ans ;
	vector <int> C ;
	for( int i = 1 ; i < MAXSIZE ; i++ )
	{
		if( testF( i ) && testF( i*i ) ) 
		{
			if( i*i <= MAXSIZE )
			{
				C.push_back( i*i ) ;
				//printf( "%d\n" , i*i ) ;
			}
		}
	}
	scanf( "%d" , &t ) ;
	while( t-- )
	{
		scanf( "%d%d" , &a , &b ) ;
		Ans = 0 ;
		for( int i = 0 ; i < C.size() ; i++ )
		{
			if( C[ i ] > b )
				break ;
			if( C[ i ] < a )
				Ans-- ;
			Ans++ ;
		}
		printf( "Case #%d: %d\n" , T++ , Ans ) ;
	}
	return 0 ;
}
