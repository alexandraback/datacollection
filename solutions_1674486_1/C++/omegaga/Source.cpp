#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool map[ 1001 ][ 1001 ];
int main()
{
	ifstream fi;
	ofstream fo;
	fi.open( "A.in" );
	fo.open( "A.out" );
	int testCase;
	fi>>testCase;
	for ( int z = 1; z <= testCase; z++ ){
		memset( map, 0, sizeof( map ) );
		int n;
		fi>>n;
		for (int i = 1; i <= n; i++ ){
			int m;
			fi>>m;
			int x;
			for ( int j = 1; j <= m; j++ ){
				fi>>x;
				map[ i ][ x ] = true;
			}
		}
		bool flag = false;
		for ( int k = 1; k <= n; k++ ){
			for ( int i = 1; i <=n; i++ ){
				for ( int j = 1; j <= n; j++ )
					if ( map[ i ][ k ] && map[ k ][ j ] )
						if ( map[ i ][ j ] ){
							flag = true;
							break;
						}
						else map[ i ][ j ] = true;
					if ( flag ) break;
			}
			if ( flag ) break;
		}
		fo<<"Case #"<<z<<": ";
		if ( flag ) fo<<"Yes"<<endl;
		else fo<<"No"<<endl;

	}
	system("pause");
	return 0;
}