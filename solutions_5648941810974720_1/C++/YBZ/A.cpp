/*
Z -> ZERO
G -> EIGHT
W -> TWO
X -> SIX
S -> SEVEN
H -> THREE
R -> FOUR
F -> FIVE
I -> NINE
O -> ONE
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

string S ;
int cnt[26] , num[26] ;

const string LETTER[10] = {
	"ZERO" ,
	"ONE" ,
	"TWO" ,
	"THREE" ,
	"FOUR" , 
	"FIVE" ,
	"SIX" ,
	"SEVEN" ,
	"EIGHT" ,
	"NINE"
} ;

int ORDER[10] = {
	0 , 8 , 2 , 6 , 7 , 3 , 4 , 5 , 9 , 1
} ;

char CHARA[10] = {
	'Z' , 'G' , 'W' , 'X' , 'S' ,
	'H' , 'R' , 'F' , 'I' , 'O'
} ;

void Solve() {
	for ( int i = 0 ; i < 10 ; i ++ ) {
		int tmp = cnt[CHARA[i]-'A'] ;
		num[ORDER[i]] = tmp ;
		for ( int j = 0 ; j < LETTER[ORDER[i]].size() ; j ++ )
			cnt[LETTER[ORDER[i]][j]-'A'] -= tmp ;
	}
	for ( int i = 0 ; i <= 9 ; i ++ )
		for ( int j = 1 ; j <= num[i] ; j ++ )
			cout << i ;
	cout << "\n" ;
}

int main() {
	freopen("A-large.in" , "r" , stdin) ;
	freopen("A-large.out", "w" ,stdout) ;
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		cin >> S ;
		for ( int j = 0 ; j < 26 ; j ++ ) cnt[j] = 0 ;
		for ( int j = 0 ; j < S.size() ; j ++ ) cnt[S[j]-'A'] ++ ;
		cout << "Case #" << i << ": " ;
		Solve() ;
	}
}