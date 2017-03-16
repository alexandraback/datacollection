#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MAXSIZE 10000000
using namespace std ;
bool testF( long long a )
{
	char Now[ 60 ] ;
	int Len ;
	bool Fair = 1 ;
	sprintf( Now , "%lld" , a ) ;
	Len = strlen( Now ) ;
	for( int i = 0 ; i < Len/2 ; i++ )
		if( Now[ i ] != Now[ Len-1-i ] )
			Fair = 0 ;
	return Fair ;
}
int main( )
{
	int t , T = 1 ;
	long long int a , b = 0 ;
	int Ans ;
	vector <long long int> C ;
	for( long long i = 1 ; i*i <= (long long)MAXSIZE*(long long)MAXSIZE ; i++ )
	{
		if( testF( i ) && testF( i*i ) ) 
		{
			C.push_back( i*i ) ;
			//printf( "%lld\n" , i*i ) ;
		}
	}
	scanf( "%d" , &t ) ;
	while( t-- )
	{
		scanf( "%lld%lld" , &a , &b ) ;
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
