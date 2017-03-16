#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std ;

ifstream fin("CTab") ;

int T[50000] , tot ;
string L , R , S[50000] ;

string SQR( string s1 ) {
	int tmp[110] ;
	for ( int i = 1 ; i <= 100 ; i ++ ) tmp[i] = 0 ;
	for ( int i = 1 ; i <= s1.size() ; i ++ )
		for ( int j = 1 ; j <= s1.size() ; j ++ )
			tmp[i+j-1] += (s1[i-1]-'0') * (s1[j-1]-'0') ;
	for ( int i = 1 ; i < 100 ; i ++ ) {
		tmp[i+1] += tmp[i] / 10 ;
		tmp[i] %= 10 ;
	}
	int c = 100 ;
	while ( tmp[c] == 0 ) c -- ;
	string ret ; ret.clear() ;
	for ( int i = c ; i >= 1 ; i -- ) ret.push_back( char('0'+tmp[i]) ) ;
	return ret ;
}

void Init() {
	tot = 0 ;
	string s0 ;
	while ( fin >> s0 ) S[++tot] = SQR(s0) ;
}

int Solve( string s0 ) {
	int ret = 0 ;
	for ( int i = 1 ; i <= tot ; i ++ )
		if ( S[i].size() < s0.size() || ( S[i].size() == s0.size() && S[i] <= s0 ) )
			ret ++ ;
	return ret ;
}

int In( string s0 ) {
	for ( int i = 1 ; i <= tot ; i ++ ) if ( S[i] == s0 ) return 1 ;
	return 0 ;
}

int main() {
	freopen( "C.in" , "r" , stdin ) ;
	freopen( "C.out", "w" , stdout) ;
	
	Init() ;
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		cin >> L >> R ;
		cout << "Case #" << i << ": " << Solve(R) - Solve(L) + In(L) << "\n" ;
	}
}
