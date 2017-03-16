#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std ;

#define N 2000 + 10

stack < int > S ;

bool bz[N] ;
int Node[N] , Next[N] , Head[N] , tot ;
int DFN[N] , LOW[N] , Fa[N] ;
int Test , n , ans , sum , Time ;

void link( int u , int v ) {
	Node[++tot] = v ;
	Next[tot] = Head[u] ;
	Head[u] = tot ;
}

void tarjan( int x ) {
	int Son = Fa[x] ;
	DFN[x] = LOW[x] = ++ Time ;
	S.push( x ) ;
	bz[x] = 1 ;
	if ( !DFN[Son] ) {
		tarjan( Son ) ;
		LOW[x] = min( LOW[x] , LOW[Son] ) ;
	} else if( bz[Son] ) LOW[x] = min( LOW[x] , DFN[Son] ) ;
	if ( DFN[x] == LOW[x] ) {
		int len = 0 ;
		while ( S.top() != x ) {
			bz[S.top()] = 0 ;
			len ++ ;
			S.pop() ;
		}
		bz[S.top()] = 0 ;
		len ++ ;
		S.pop() ;
		ans = max( ans , len ) ;
	}
}

int DFS( int x , int deep ) {
	int ret = deep ;
	for (int p = Head[x] ; p ; p = Next[p] ) {
		if ( Node[p] == Fa[x] ) continue ;
		ret = max( ret , DFS( Node[p] , deep + 1 ) ) ;
	}
	return ret ;
}

int main() {
	freopen( "C.in" , "r" , stdin ) ;
	freopen( "C.out" , "w" , stdout ) ;
	scanf( "%d" , &Test ) ;
	for (int k = 1 ; k <= Test ; k ++ ) {
		tot = ans = sum = Time = 0 ;
		memset( Fa , 0 , sizeof(Fa) ) ;
		memset( DFN , 0 , sizeof(DFN) ) ;
		memset( LOW , 0 , sizeof(LOW) ) ;
		memset( Head , 0 , sizeof(Head) ) ;
		memset( Node , 0 , sizeof(Node) ) ;
		memset( Next , 0 , sizeof(Next) ) ;
		printf( "Case #%d: " , k ) ;
		scanf( "%d" , &n ) ;
		for (int i = 1 ; i <= n ; i ++ ) {
			scanf( "%d" , &Fa[i] ) ;
			link( Fa[i] , i ) ;
		}
		for (int i = 1 ; i <= n ; i ++ ) {
			if ( Fa[Fa[i]] == i ) sum += DFS( i , 1 ) ;
		}
		while ( !S.empty() ) S.pop() ;
		for (int i = 1 ; i <= n ; i ++ ) {
			if ( !DFN[i] ) tarjan( i ) ;
		}
		printf( "%d\n" , max( ans , sum ) ) ;
	}
	return 0 ;
}
