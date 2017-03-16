#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std ;
#define rep( i, j, k ) for( i = j ; i <= k ; ++i )
#define drep( i, j, k ) for( i = j ; i >= k ; --i ) 
#define LL long long 
#define mod 1000000007
#define Maxn 1015
#define MaxL 1015

char ss[Maxn][MaxL], s[Maxn][5] ;
int ll[MaxL], n, T, Case, L, C ;
LL ans, fac[Maxn] ;
bool in[Maxn << 1], vis[Maxn] ;
map<char, int> V ;

inline bool Check()
{
	int i, j, k ;
	
	rep( i, 1, n ) {// 自己跟自己重 
		memset( in, 0, sizeof( in ) ) ;
		for( j = 1 ; j <= ll[i] ; ) {
			if( in[ss[i][j]] ) return false ;
			in[ss[i][j]] = true ;
			for( k = j ; ss[i][j] == ss[i][k] && j <= ll[i] ; ++j ) ;
		}	
	}
	
	memset( in, 0, sizeof( in ) ) ;
	rep( i, 1, n ) {
		for( j = 1 ; j <= ll[i] ; ) {
			if( in[ss[i][j]] ) return false ;
			for( k = j ; ss[i][j] == ss[i][k] && j <= ll[i] ; ++j ) ;		
			if( ( k != 1 ) && ( j <= ll[i] ) ) in[ss[i][k]] = true ;
		} 
	}	
	
	memset( in, 0, sizeof( in ) ) ;
	drep( i, n, 1 ) {
		for( j = 1 ; j <= ll[i] ; ) {
			if( in[ss[i][j]] ) return false ;
			for( k = j ; ss[i][j] == ss[i][k] && j <= ll[i] ; ++j ) ;	
			if( ( k != 1 ) && ( j <= ll[i] ) ) in[ss[i][k]] = true ;
		}	
	}
	
	return true ;
}

inline void Search( int p )
{
	int i ;
	
	in[s[p][1]] = in[s[p][2]] = true ;
	rep( i, 1, L )
		if( ( ! vis[i] ) && ( s[p][2] == s[i][1] ) ) {
			-- C ;
			vis[i] = true ;
			Search( i ) ;
			return ;	
		}
}

inline bool Check( int k ) 
{
	int i, re = 0 ;
	
	memset( in, 0, sizeof( in ) ) ;
	rep( i, 1, L ) {
		if( in[s[i][1]] ) return false ;
		in[s[i][1]] = true ;
	}
	
	memset( in, 0, sizeof( in ) ) ; 
	rep( i, 1, L ) {
		if( in[s[i][2]] ) return false ;
		in[s[i][2]] = true ;
	}
	
	memset( in, 0, sizeof( in ) ) ;
	rep( i, 1, L )
		in[s[i][1]] = true ;
	
	rep( i, 1, L )
		if( in[s[i][2]] ) ++ re ;

	if( re == L && L ) return false ;
	return true; 
}

int main()
{
	int i ;

	fac[0] = 1 ;
	rep( i, 1, 110 )
		fac[i] = ( fac[i-1] * i ) % mod ;
		 
	freopen("B-large.in","r",stdin) ;
	freopen("std.txt","w",stdout) ;
	for( scanf("%d", &T) ; T-- ; ) {
		C = L = ans = 0 ;
		V.clear() ;
		
		scanf("%d\n", &n) ;
		rep( i, 1, n ) {
			scanf("%s", ss[i]+1) ; 	
			ll[i] = strlen( ss[i] + 1 ) ; 
		}
		
	/*	++ Case; 
		if( Case == 89 ) {
			printf("%d\n", n ) ;
			rep( i, 1, n )
				printf("%s\n", ss[i]+1) ;
		}*/
		
		if( Check() ) {
			rep( i, 1, n ) {
				if( ss[i][1] == ss[i][ll[i]] ) {
					if( V[ss[i][1]] ) ++ V[ss[i][1]] ;
					else V[ss[i][1]] = 1 ;// V.insert( make_pair( ss[i][1], 1 ) ) ;
				}
				else {
					++L ;
					s[L][1] = ss[i][1], s[L][2] = ss[i][ll[i]] ;	
				}
			}
			
			if( Check( 0 ) ) { 
			
				C = L ;
				memset( in, 0, sizeof( in ) ) ; 
				memset( vis, 0, sizeof( vis ) ) ;
				rep( i, 1, L ) 
					if( ! vis[i] ) 
						Search( i ) ;
					
				
				ans = 1 ; 
				for( map<char, int>::iterator j = V.begin() ; j != V.end() ; ++j ) {
				//	if( in[j->first] ) 
					ans = ( ans * fac[j->second] ) % mod ;
					if( ! in[j->first] ) 
						++ C ;
				}
				
				ans = ( ans * fac[C] ) % mod ; 
				
				printf("Case #%d: %I64d\n", ++ Case, ans) ;
				
			} else printf("Case #%d: 0\n", ++ Case ) ; 
		} else printf("Case #%d: 0\n", ++ Case ) ;
		
	}
	return 0 ;	
}
