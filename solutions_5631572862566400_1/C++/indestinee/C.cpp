/*
 *	Author:
 *		Indestinee
 *	Date:
 *		2016/04/16
 */
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1011;
int cas, n, vis[M], v[M], ans;
vector<int> g[M];
void dfs( int root ){
	int x = root, tmp = 0;
	do{
		x = v[x];
		tmp ++;
		if( vis[x] )
			return;
		vis[x] = 1;
	}while( x != root );
	ans = max( ans , tmp );
}
int dfs( int root , int X , int dep ){
	int ret = dep;
	for( int i = 0 , sz = g[root].size() ; i < sz ; i ++ ){
		int u = g[root][i];
		if( u != X ){
			ret = max( ret , dfs( u , X , dep + 1 ) );
		}
	}
	return ret;
}
int main(){
	freopen( "C-large.in"  , "r" , stdin  );
	freopen( "C-large.txt" , "w" , stdout );
	scanf( "%d" , &cas );
	for( int T = 1 ; T <= cas ; T ++ ){
		memset( vis , 0 , sizeof vis );
		scanf( "%d" , &n );
		for( int i = 1 ; i <= n ; i ++ ){
			scanf( "%d" , &v[i] );
			g[v[i]].push_back( i );
		}
		ans = 0;
		for( int i = 1 ; i <= n ; i ++ ){
			memset( vis , 0 , sizeof vis );
			dfs( i );
		}
		int ans2 = 0, id2 = 0, ans11 = 0, ans12 = 0, id11 = 0, id12 = 0, t = 0;
		for( int i = 1 ; i <= n ; i ++ ){
			for( int j = i + 1 ; j <= n ; j ++ ){
				if( v[i] == j && v[j] == i ){
					int x = dfs( i , j , 0 ), y = dfs( j , i , 0 );
					t ++;
					if( ans12 < max( x , y ) + 2 ){
						ans12 = max( x , y ) + 2;
						id12 = i << 10 | j;
					}
					if( ans12 > ans11 ){
						swap( ans12 , ans11 );
						swap( id12 , id11 );
					}
					if( ans2 < x + y + 2 ){
						ans2 = x + y + 2;
						id2 = i << 10 | j;
					}else if( ans2 == x + y + 2 )
						id2 = -1;
				}
			}
		}
		if( t >= 2 ){
			if( id2 != id11 )
				ans = max( ans , ans2 + ans11 + ( t - 2 ) * 2 );
			else
				ans = max( ans , ans2 + ans12 + ( t - 2 ) * 2 );
		}else{
			ans = max( ans , ans2 );
		}
		
		for( int i = 1 ; i <= n ; i ++ )
			g[i].clear();
		printf( "Case #%d: %d\n" , T , ans );
	}
	return 0;
}
