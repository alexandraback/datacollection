#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std ;

ofstream fout("CTab") ;

int stop ;

int tot ;
int tmp[110] , tmp2[110] , tmp_len , tmp2_len ;

bool Ok( int n ) {
	tmp2_len = n * 2 ;
	for ( int i = 1 ; i <= tmp2_len ; i ++ ) tmp2[i] = 0 ;
	for ( int i = 1 ; i <= n ; i ++ )
		for ( int j = 1 ; j <= n ; j ++ )
			tmp2[i+j-1] += tmp[i] * tmp[j] ;
	for ( int i = 1 ; i < tmp2_len ; i ++ ) {
		tmp2[i+1] += tmp2[i] / 10 ;
		tmp2[i] %= 10 ;
	}
	while ( tmp2[tmp2_len] == 0 ) tmp2_len -- ;
	for ( int i = 1 , j = tmp2_len ; i <= j ; i ++ , j -- )
		if ( tmp2[i] != tmp2[j] ) return false ;
	return true ;
}

void Number_Print( int n ) {
	for ( int i = 1 ; i <= n ; i ++ ) fout << tmp[i] ;
	fout << "\n" ;
}

void Check() {
	for ( int i = 1 ; i <= tmp_len ; i ++ ) tmp[tmp_len*2+1-i] = tmp[i] ;
	if ( Ok(tmp_len*2) ) { tot ++ ; Number_Print(tmp_len*2) ; }
	
	for ( int i = 1 ; i < tmp_len ; i ++ ) tmp[tmp_len*2-i] = tmp[i] ;
	if ( Ok(tmp_len*2-1) ) { tot ++ ; Number_Print(tmp_len*2-1) ; }
}

void Prepare() {
	fout << "1\n2\n3\n11\n22\n" ;
	tot = 5 ;
	for ( int i = 2 ; i <= 25 ; i ++ ) {
		for ( int s = 0 ; s < (1 << (i-2)) ; s ++ ) {
			tmp_len = i ;
			for ( int k = 2 ; k <= i-1 ; k ++ ) tmp[k] = (s >> (k-2))%2 ;
			tmp[1] = 1 ; tmp[i] = 2 ; Check() ;
			tmp[1] = 1 ; tmp[i] = 1 ; Check() ;
			tmp[1] = 1 ; tmp[i] = 0 ; Check() ;
			tmp[1] = 2 ; tmp[i] = 0 ; Check() ;
			tmp[1] = 2 ; tmp[i] = 1 ; Check() ;
		}
		cout << "i = " << i << "   tot=" << tot << "\n" ;
	}
	cout << "tot=" << tot << "\n" ;
}

int main() {
	Prepare() ;
}








