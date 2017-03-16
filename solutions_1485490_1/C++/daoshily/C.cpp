#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fi(i,a,b) for(int i=a;i>=b;i--)

typedef long long LL ;

LL NumA[109] , NumB[109], ColA[109] , ColB[109] , F[109][109] ;
int N , M ;

void Init() {
	cin >> N >> M ;
	fo(i,1,N) cin >> NumA[i] >> ColA[i] ;
	fo(i,1,M) cin >> NumB[i] >> ColB[i] ;
}

LL max( LL a , LL b ) {
	if ( a > b ) return a ;
	return b ;
}

void Solve() {
	fo(i,0,N) fo(j,0,M) F[i][j] = 0 ;
	fo(i,1,N) {
		fo(j,1,M) {
			F[i][j] = max( F[i][j] , F[i-1][j] ) ;
			F[i][j] = max( F[i][j] , F[i][j-1] ) ;
			if ( ColA[i] != ColB[j] ) continue ;
			
			LL cnti = 0 ;
			fi(i1,i-1,0) {
				if ( ColA[i1+1] == ColA[i] ) cnti += NumA[i1+1] ;
				LL cntj = 0 ;
				
				fi(j1,j-1,0) {
					if ( ColB[j1+1] == ColA[i] ) cntj += NumB[j1+1] ;
					F[i][j] = max( F[i][j] , F[i1][j1] + min(cnti,cntj) ) ;
				}
			}
			
			// cout << "F[" << i << "][" << j << "]=" << F[i][j] << "\n" ;
		}
	}
	cout << F[N][M] << "\n" ;
}

int main() {
	freopen( "C.in" , "r" , stdin ) ;
	freopen( "C.out", "w" , stdout) ;
	
	int Test ; cin >> Test ;
	fo(i,1,Test) {
		Init() ;
		cout << "Case #" << i << ": " ;
		Solve() ;
	}
}