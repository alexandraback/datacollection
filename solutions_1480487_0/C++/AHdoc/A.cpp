#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

#define fo(i,a,b) for(int i=a;i<=b;i++)

int N ;
double A[209] ;

void Init() {
	double X = 0.000 ;
	fo(i,1,N) { cin >> A[i] ; X += A[i] ; }
	fo(i,1,N) A[i] = (A[i] / X) * 100.000 ;
}

void Solve() {
	fo(i,1,N) {
		double L = 0.000 , R = 100.000 , T ;
		while ( R - L >= 0.0000001 ) {
			T = (L+R)/2 ;
			double Cnt = 0.000 ; Cnt += T ;
			fo(j,1,N) if ( i != j ) {
				if ( A[j] >= A[i] + T ) continue ;
				Cnt += A[i] + T - A[j] ;
			}
			if ( Cnt < 100.000 ) L = T ;
			else R = T ;
		}
		cout.precision(6) ;
		cout << fixed << " " << R ;
	}
}

int	main() {
	freopen( "A.in" , "r" , stdin ) ;
	freopen( "A.out", "w" , stdout) ;
	int T ; cin >> T ;
	fo(i,1,T) {
		cin >> N ;
		Init() ;
		cout << "Case #" << i << ":" ;
		Solve() ;
		cout << "\n" ;
	}
}