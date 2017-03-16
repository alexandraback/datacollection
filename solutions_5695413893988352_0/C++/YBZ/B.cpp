#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long LL ;

int N ;

string A , B , AA , BB , oriA , oriB ;
LL ansA , ansB ;
string STRansA , STRansB ;
LL MinDist ;

bool Better( int _ , int Anum , int Bnum ) {
	if ( _ == -1 ) swap(Anum , Bnum) ;
	if ( Anum < ansA || (Anum == ansA && Bnum < ansB) ) return true ;
	return false ;
}

void DO( int _ ) {
	for ( int i = 0 ; i < N ; i ++ ) { // A > B
		AA = A ;
		BB = B ;
		if ( AA[i] == '?' && BB[i] == '?' ) {
			AA[i] = '1' ;
			BB[i] = '0' ;
		} else if ( AA[i] == '?' && BB[i] != '?' && BB[i] != '9' )
			AA[i] = BB[i] + 1 ;
		else if ( AA[i] != '?' && BB[i] == '?' && AA[i] != '0' )
			BB[i] = AA[i] - 1 ;
		else if ( AA[i] != '?' && BB[i] != '?' && AA[i] > BB[i] ) ;
		else {
			if ( AA[i] != '?' && BB[i] != '?' && AA[i] != BB[i] ) break ;
			else {
				if ( A[i] == '?' && B[i] == '?' ) {
					A[i] = '0' ;
					B[i] = '0' ;
				} else if ( A[i] == '?' ) A[i] = B[i] ;
				else B[i] = A[i] ;
				continue ;
			}
		}
		LL Anum = 0LL ;
		LL Bnum = 0LL ;
		for ( int j = i+1 ; j < N ; j ++ ) {
			if ( AA[j] == '?' ) AA[j] = '0' ;
			if ( BB[j] == '?' ) BB[j] = '9' ;
		}
		for ( int j = 0 ; j < N ; j ++ ) {
			Anum = Anum * 10LL + (AA[j] - '0') ;
			Bnum = Bnum * 10LL + (BB[j] - '0') ;
		}
		//cout << "[" << i << " " << Anum << " " << Bnum << " " << AA << " " << BB << " " << Anum - Bnum << "]\n" ;
		if ( MinDist == -1 || (Anum - Bnum < MinDist ||
			(Anum - Bnum == MinDist && Better(_ , Anum , Bnum))) ) {
			MinDist = Anum - Bnum ;
			if ( _ == +1 ) { ansA = Anum ; ansB = Bnum ; STRansA = AA ; STRansB = BB ; }
			else           { ansA = Bnum ; ansB = Anum ; STRansA = BB ; STRansB = AA ; }
		}
		
		if ( A[i] != '?' && B[i] != '?' && A[i] != B[i] ) break ;
		
		if ( A[i] == '?' && B[i] == '?' ) {
			A[i] = '0' ;
			B[i] = '0' ;
		} else if ( A[i] == '?' ) A[i] = B[i] ;
		else B[i] = A[i] ;
	}
}

void Solve() {
	bool allsame = true ;
	N = A.size() ;
	for ( int i = 0 ; i < N ; i ++ )
		if ( A[i] != '?' && B[i] != '?' && A[i] != B[i] )
			allsame = false ;
	if ( allsame ) {
		for ( int i = 0 ; i < N ; i ++ ) {
			if ( A[i] == '?' && B[i] == '?' ) {
				A[i] = '0' ;
				B[i] = '0' ;
			} else if ( A[i] == '?' ) A[i] = B[i] ;
			else B[i] = A[i] ;
		}
		cout << A << " " << B << "\n" ;
	} else {
		MinDist = -1 ;
		oriA = A ; oriB = B ;
		DO(1) ;
		B = oriA ; A = oriB ;
		DO(-1) ;
		cout << STRansA << " " << STRansB << "\n" ;
	}
}

int main() {
	freopen("B-small-attempt5.in" , "r" , stdin) ;
	freopen("B-small-attempt5.out" , "w" , stdout) ;
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		cin >> A >> B ;
		cout << "Case #" << i << ": " ;
		Solve() ;
	}
}