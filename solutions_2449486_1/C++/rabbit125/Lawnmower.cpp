#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MAXSIZE 120
using namespace std ;
int n , m ;
int sq[ MAXSIZE ][ MAXSIZE ] ;
int H[ MAXSIZE ] ;
vector <int> vH ;
int ok[ MAXSIZE ][ MAXSIZE ] ;
int main( )
{
	int t , T = 1 ;
	scanf( "%d" , &t ) ;
	int cut ;
	while( t-- )
	{
		memset( H , 0 , sizeof( H ) ) ;
		memset( ok, 0 , sizeof( ok ) ) ;
		cut = 0 ;
		scanf( "%d%d" , &n , &m ) ;
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ )
			{
				scanf( "%d" , &sq[ i ][ j ] ) ;
				H[ sq[i][j] ] = 1 ;
			}
		vH.clear( ) ;
		for( int i = 1 ; i < MAXSIZE ; i++ )
			if( H[ i ] == 1 )
				vH.push_back( i ) ;
		for( int i = 0 ; i < vH.size( ) ; i++ )
		{
			bool State = 1 ;
			for( int j = 0 ; j < n ; j++ )
			{
				State = 1 ;
				for( int k = 0 ; k < m ; k++ )
					if( sq[ j ][ k ] > vH[ i ] )
						State = 0 ;
				if( State )
					for( int k = 0 ; k < m ; k++ )
						if( sq[j][k] == vH[i] )
							ok[ j ][ k ] = 1 ;				
			}
			for( int j = 0 ; j < m ; j++ )
			{
				State = 1 ;
				for( int k = 0 ; k < n ; k++ )
					if( sq[ k ][ j ] > vH[ i ] )
						State = 0 ;
				if( State )
					for( int k = 0 ; k < n ; k++ )
						if( sq[k][j] == vH[i] )
							ok[ k ][ j ] = 1 ;				
			}
		}
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ )
			{
				//printf( "%d%c" , ok[i][j] , j != m-1 ? ' ' : '\n' ) ;
				if( ok[i][j] == 1 )
					cut++ ;
			}
		//printf( "%d\n" , cut ) ;
		if( cut == n*m )
			printf( "Case #%d: YES\n" , T++ ) ;
		else
			printf( "Case #%d: NO\n" , T++ ) ;
	}
	return 0 ;
}
