#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

#define repn( i , a , b ) for( int i = ( int ) a ; i < ( int ) b ; i ++ )
#define rep( i , n ) repn( i , 0 , n ) 
#define all( x )  x.begin() , x.end()
#define rall( x ) x.rbegin() , x.rend()
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long int64;
typedef long double ldouble;
typedef pair< int , int > pii;

int n , m;
int64 a[200] , A[200] , b[ 200 ] , B[200];
int64 c[200] , C[200];

int64 find( int64 id , int64 cap , int ini , int fin ){
	int64 sum = 0;
	repn( i , ini , fin + 1 ) if( id == B[ i ] ) sum += b[ i ];
	return min( cap , sum );
}

int64 solve(){
	memset( c , 0 , sizeof c );
	memset( C , 0 , sizeof C );
	cin >> n >> m;
	rep( i , n ) cin >> a[ i ] >> A[ i ];
	rep( i , m ) cin >> b[ i ] >> B[ i ];
	int k = 0;
	rep( i , n ){
		int j = i;
		while( j < n and A[ i ] == A[ j ] ){
			c[ k ] += a[ j ]; j++;
		}
		C[ k++ ] = A[ i ];
		i = j - 1;
	}

	//comprime
	int64 ans=0;
	if( k == 1 ){
		int64 sum = 0;
		rep( i , m ) if( C[ 0 ] == B[ i ] ){
			sum += b[ i ];
		}
		return min( sum , c[ 0 ] );
	}
	else if( k == 2 ){
		ans = max( find( C[ 0 ] , c[ 0 ] , 0 , m -1 ) 
			, find( C[ 1 ], c[ 1 ] , 0 , m - 1 ) );
		rep( i , m + 1 ){
			int64 tmp = find( C[ 0 ] , c[ 0 ] , 0 , i - 1 ) 
			+ find( C[ 1 ] , c[ 1 ], i , m - 1 );
			ans = max( ans , tmp );
		}
		return ans;
	}
	else{
		rep( i , k ) ans = max( ans , find( C[ i ] , c[ i ], 0 , m - 1 ) );
		if( C[ 0 ] == C[ 2 ] ){ 
		ans = max( ans , find( C[ 0 ] , c[ 2 ] + c[ 0 ] , 0 , m - 1 ) );
		}
		rep( i , m + 1 ){
			repn( j , i , m + 1){
				ans = max ( ans , 
					find( C[ 0 ] , c[ 0 ] , 0 , i - 1 ) + 
					find( C[ 1 ] , c[ 1 ] , i , j - 1) +
					find( C[ 2 ] , c[ 2 ] , j , m - 1 ) );
			}
		}
		
		return ans;
	}
	return ans;
}

int main(){
	int test;
	cin >> test;
	rep( t , test ){
		printf("Case #%d: ", t + 1 );
		cout << solve() << endl;
	}
	return 0;
}


