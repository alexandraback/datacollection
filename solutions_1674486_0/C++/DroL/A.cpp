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

vector< int > adj[ 1010 ];
int pai[ 1010 ];
int path[ 1010 ][ 1010 ];

void bfs( int root ){
	queue< int > q;
	q.push( root );
	path[ root ][ root ] = 1;
	while( not q.empty() ){
		int c = q.front(); q.pop();
		rep( i , adj[ c ].size() ){
			int nxt=adj[ c ][ i ];
			if( path[ root ][ nxt ] ) continue; 
			path[ root ][ nxt ] = 1;
			q.push( nxt );
		}
	}
}

bool solve(){
	int n;
	cin >> n;
	memset( path , 0 , sizeof path ) ;
	rep( i , n ){
		int len; cin >> len;
		adj[ i ].resize( len );
		rep( j , len ) cin >> adj[ i ][ j ];
		rep( j , len ){
			adj[ i ][ j ]--;
		}
	}
	rep( i , n ) bfs( i );
	rep( i , n ) rep( j , n ) if ( i != j and path[ i ][ j ] ){
		int ans = 0;
		rep( k , adj[ i ].size() ){
			int to = adj[ i ][ k ];
			if( path[ to ][ j ] ) ans++;
		}
		if( ans >= 2 ) return true;
	}
	return false;
}

int main(){
	int test;
	cin >> test;
	repn( t , 1 , test + 1 ) {
		printf("Case #%d: %s\n" , t ,solve()? "Yes":"No");
	}
	return 0;
}

