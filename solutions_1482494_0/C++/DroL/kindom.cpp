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
#define MAXN 1010
using namespace std;

typedef long long int64;
typedef long double ldouble;
typedef pair< int , int > pii;

int top[ MAXN ][ 2 ]; 
int lvl[ MAXN ];
int N;
int find_id( int type , int coins ){
	int ans = -1;
	rep( i , N )	if( lvl[ i ] != 2 and top[ i ][ type ] <= coins  ){
		if( type == 1 ){
			if( ans == -1 ) ans = i;
			else{
				if( lvl[ ans ] == 1 and lvl[ i ] == 0 ) ans = i;
				else if( lvl[ ans ] == 0 ){
					if( top[ i ][ 1 ] > top[ ans ][ 1 ] )
						ans = i;
				}
			}
		}
		else{
			if( ans == -1 ) ans = i;
			else{
				if( top[ i ][ 1 ] > top[ ans ][ 1 ] ) ans = i;
			}
		}
	}
	return ans;
}

int solve(){
	int ans = 0;
	int cur_coins = 0;
	int all = 0;
	memset( lvl , 0 , sizeof lvl );
	cin >> N;
	rep( i , N ) cin >> top[ i ][ 0 ] >> top[ i ][ 1 ]; 
	while( all < N ){
		int id_up = find_id( 1 , cur_coins );
		if( id_up == -1 ){
			int id_down = find_id( 0 , cur_coins );
			if( id_down == -1 ) return -1;
			cur_coins++;
			ans++;  
			lvl[ id_down ]++;
		}
		else{
			cur_coins += 2 - lvl[ id_up ]; 
			ans++;
			lvl[ id_up ] = 2;
			all++;
		}
	}		
	return ans;
}

int ord( pii a , pii b ){
	if( a.fst != b.fst ) return a.fst < b.fst;
	return a.snd > b.snd;
}

pii star[ MAXN ];
int solve1(){
	int N;
	cin >> N; 
	rep( i , N ) cin >> star[ i ].snd >> star[ i ].fst; 
	sort( star , star + N );
	memset( lvl , 0 , sizeof lvl ); 
	int ans = 0;
	int coins = 0;
	rep( i , N ){
		if( star[ i ].fst <= coins ){
			coins += 2 - lvl[ i ];
			ans++;
		}
		else{
			int j;
			for( j = N - 1 ; j >= i ; j -- ) if( star[ j ].snd <= coins and lvl[ j ] == 0 ) {
				break;
			}
			if( j == i - 1 ) return -1; 
			lvl[ j ] = 1;
			coins += 1;
			i--;
			ans++;
		}
	}
	return ans;
}

int main(){
	int test;
	cin >> test;
	repn( tcase , 1 , test + 1 ){
		int ans = solve1();
		if( ans == -1 ) 
			printf("Case #%d: Too Bad\n" , tcase );
		else
			printf("Case #%d: %d\n" , tcase , ans );
	}
	return 0;
}

