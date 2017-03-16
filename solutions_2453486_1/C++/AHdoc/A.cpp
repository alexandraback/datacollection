#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

char c[10][10] ;

bool Ck_X(char c) { return (c == 'X' || c == 'T') ; }
bool Ck_O(char c) { return (c == 'O' || c == 'T') ; }

void Init() {
	for ( int i = 1 ; i <= 4 ; i ++ )
		for ( int j = 1 ; j <= 4 ; j ++ )
			cin >> c[i][j] ;
}

void Solve() {
	bool X = false , O = false , Empty = false ;
	for ( int i = 1 ; i <= 4 ; i ++ ) {
		if ( Ck_X(c[i][1]) && Ck_X(c[i][2]) && Ck_X(c[i][3]) && Ck_X(c[i][4]) ) X = true ;
		if ( Ck_O(c[i][1]) && Ck_O(c[i][2]) && Ck_O(c[i][3]) && Ck_O(c[i][4]) ) O = true ;
	}
	for ( int i = 1 ; i <= 4 ; i ++ ) {
		if ( Ck_X(c[1][i]) && Ck_X(c[2][i]) && Ck_X(c[3][i]) && Ck_X(c[4][i]) ) X = true ;
		if ( Ck_O(c[1][i]) && Ck_O(c[2][i]) && Ck_O(c[3][i]) && Ck_O(c[4][i]) ) O = true ;
	}
	if ( Ck_X(c[1][1]) && Ck_X(c[2][2]) && Ck_X(c[3][3]) && Ck_X(c[4][4]) ) X = true ;
	if ( Ck_O(c[1][1]) && Ck_O(c[2][2]) && Ck_O(c[3][3]) && Ck_O(c[4][4]) ) O = true ;
	if ( Ck_X(c[1][4]) && Ck_X(c[2][3]) && Ck_X(c[3][2]) && Ck_X(c[4][1]) ) X = true ;
	if ( Ck_O(c[1][4]) && Ck_O(c[2][3]) && Ck_O(c[3][2]) && Ck_O(c[4][1]) ) O = true ;
	for ( int i = 1 ; i <= 4 ; i ++ )
		for ( int j = 1 ; j <= 4 ; j ++ )
			if ( '.' == c[i][j] ) Empty = true ;
	if ( X ) cout << "X won\n" ;
	else if ( O ) cout << "O won\n" ;
	else if ( !Empty ) cout << "Draw\n" ;
	else cout << "Game has not completed\n" ;
}

int main() {
	freopen( "A.in" , "r" , stdin ) ;
	freopen( "A.out", "w" , stdout) ;
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		Init() ;
		cout << "Case #" << i << ": " ;
		Solve() ;
	}
}
