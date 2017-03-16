#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int n, m;
int na[ 101 ];
int a[ 101 ];
int nb[ 101 ];
int b[ 101 ];
int tot = 0, ans = 0;
int min( int x, int y ){
	return ( x > y ) ? y : x;
}
void search( int p , int qq )
{
	if ( p == n ){
		if ( tot > ans ) ans = tot;
	}
	else{
		for ( int q = qq; q < m; q++ )
		if ( a[ p ] == b[ q ] ){
			int tmp = min( na[ p ], nb[ q ] );
			bool ch = false;
			if ( na[ p ] > nb[ q ] ){
				ch = true;
				na[ p ] -= nb[ q ];
			}
			tot += tmp;
			if ( !ch ) search( p + 1, q );
			else search( p, q + 1 );
			tot-= tmp;
			if ( ch ) na[ p ] += nb[ q ];
		}
		search( p + 1, qq );
		
	}
}

int main()
{
	ifstream fi;
	ofstream fo;
	fi.open( "C.in" );
	fo.open( "C.out" );
	int testCase;
	fi>>testCase;
	for ( int z = 1; z <= testCase; z++ ){
		
		fi>>n>>m;
		
		for ( int i = 0; i < n; i++ )
			fi>>na[ i ]>>a[ i ];
		ans = 0;
		tot = 0;
		for ( int i = 0; i < m; i++ )
			fi>>nb[ i ]>>b[ i ];
		search( 0, 0 );
		fo<<"Case #"<<z<<": ";
		fo<<ans<<endl;
	}
	system("pause");
	return 0;
}
