#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int N , M ;
bool V[11] ;
bool VV[30] ;
char A[111][111] ;
char S[1111] ;
int ans ;

void dfs( int x , int prev ) {
	if( x == N ) {
		ans++ ;
		return ;
	}
	bool VVV[30] ;
	for( int i = 0 ; i < N ; i++ )
	if( !V[i] ) {
		V[i] = 1 ;
		bool flag = true ;
		int temp_prev = prev;
		memcpy( VVV , VV , sizeof( VV ) ) ;
		for( int j = 0 ; j < strlen( A[i] ) ; j++ ) {
			int now = A[i][j] - 'a' ;
			if( now != temp_prev && VV[now] ) {
				flag = false ;
				break ;
			}
			temp_prev = now;
			VV[now] = 1 ;
		}
		if( !flag ) {
			memcpy( VV , VVV , sizeof( VVV ) ) ;
			V[i] = 0 ;
			continue ;
		}	
		dfs( x + 1 , temp_prev ) ;
		V[i] = 0 ;
		memcpy( VV , VVV , sizeof( VVV ) ) ;
	}
	return ;
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int TestCase ;
	scanf( "%d" , &TestCase ) ;
	for( int TC = 1 ; TC <= TestCase ; TC++ ) {
		scanf( "%d" , &N ) ;
		for( int i = 0 ; i < N ; i++ ) {
			scanf( "%s" , A[i] ) ;
		}
		memset( V , 0 , sizeof( V ) ) ;
		memset( VV , 0 , sizeof( VV ) ) ;
		ans = 0 ;
		dfs( 0 , -1 ) ;
		printf( "Case #%d: %d\n" , TC , ans ) ;
	}
	return 0;
}
