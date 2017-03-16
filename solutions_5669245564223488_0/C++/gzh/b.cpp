#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std ;
#define rep( i, j, k ) for( i = j ; i <= k ; ++i )
#define Maxn 115
#define MaxL 115

char s[Maxn][MaxL], S[Maxn * MaxL] ;
int l[Maxn], L, ans, T, Case, n, ar[Maxn] ;
bool in[115] ;

inline bool Check()
{
	int i, j ;
	
	L = 0 ;
	memset( S, 0, sizeof( S ) ) ;
	memset( in, 0, sizeof( in ) ) ;
	
	rep( i, 1, n ) 
		rep( j, 1, l[ar[i]] )
			S[++L] = s[ar[i]][j] ;	

	for( i = 1 ; i <= L ; ) {
		if( in[S[i]] ) return false ;
		in[S[i]] = true ;
		for( j = i ; S[j] == S[i] && i <= L ; ++i ) ;
	}
	return true ;
}

int main()
{
	int i ;
	
	freopen("B-small-attempt0.in","r",stdin) ;
	freopen("output.txt","w",stdout) ;
	
	for( scanf("%d", &T) ; T-- ; ) {
		ans = 0 ;
		
		scanf("%d\n", &n) ;
		rep( i, 1, n ) { 
			scanf("%s", s[i]+1 ) ;	
			l[i] = strlen( s[i] + 1 ) ; 
		}
		
		rep( i, 1, n ) ar[i] = i ; 
		if( Check() ) ++ ans ;
		while( next_permutation( ar+1, ar+1+n ) ) 		
			if( Check() ) ++ ans ;
			
		printf("Case #%d: %d\n", ++ Case, ans ) ; 	
	}	
//	system("pause") ;
	return 0 ; 	
}
