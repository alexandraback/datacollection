#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

#define fo(i,a,b) for ( int i = a ; i <= b ; i ++ )

int N , V[30] , cnt[2000009] , KS1[2000009] , KS2[2000009];

void Init() {
	cin >> N ;
	fo(i,1,N) cin >> V[i] ;
}

bool Solve() {
	fo(i,1,2000000) cnt[i] = 0 ;
	fo(i,0,(1<<N)-1) {
		int c = 0 ;
		fo(j,0,N-1) if ( (i>>j)&1 ) c += V[j+1] ;
		if ( cnt[c] == 0 ) { cnt[c] ++ ; KS1[c] = i ; }
		else if ( cnt[c] == 1 ) { cnt[c] ++ ; KS2[c] = i ; }
	}
	fo(i,1,2000000) if ( cnt[i] == 2 ) {
		bool pan = false ;
		fo(j,0,N-1) if ( (KS1[i]>>j)&1 ) {
			if ( pan ) cout << " " ; else pan = true ;
			cout << V[j+1] ;
		}
		cout << "\n" ;
		pan = false ;
		fo(j,0,N-1) if ( (KS2[i]>>j)&1 ) {
			if ( pan ) cout << " " ; else pan = true ;
			cout << V[j+1] ;
		}
		cout << "\n" ;
		return true ;
	}
	return false ;
}

int	main() {
	freopen( "C.in" , "r" , stdin ) ;
	freopen( "C.out", "w" , stdout) ;
	int T ; cin >> T ;
	fo(i,1,T) {
		Init() ;
		cout << "Case #" << i << ":\n" ;
		if ( ! Solve() ) cout << "Impossible\n" ;
	}
}