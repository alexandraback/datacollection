#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std ;

const int MAXN = 1009 ;

int N , Ans ;

string oriL[MAXN] , oriR[MAXN] ;
bool vis[MAXN] ;

set<string> L , R ;

bool OK() {
	L.clear() ; R.clear() ;
	for ( int i = 1 ; i <= N ; i ++ ) if ( vis[i] ) {
		string L0 = oriL[i] , R0 = oriR[i] ;
		L.insert(L0) ;
		R.insert(R0) ;
	}
	for ( int i = 1 ; i <= N ; i ++ ) if ( !vis[i] ) {
		string L0 = oriL[i] , R0 = oriR[i] ;
		if ( L.find(L0) != L.end() && R.find(R0) != R.end() ) ;
		else return false ;
	}
	return true ;
}

void Solve() {
	Ans = 0 ;
	for ( int s = 0 ; s < (1<<N) ; s ++ ) {
		int Ret = 0 ;
		for ( int j = 0 ; j < N ; j ++ )
			if ( ((s >> j) & 1) == 1 ) {
				Ret ++ ;
				vis[j+1] = false ;
			} else
				vis[j+1] = true ;
		if ( OK() && Ret > Ans ) Ans = Ret ;
	}
}

int main() {
	freopen("C-small-attempt1.in" , "r" , stdin) ;
	freopen("C-small-attempt1.out" , "w" , stdout) ;
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		cin >> N ;
		for ( int j = 1 ; j <= N ; j ++ ) cin >> oriL[j] >> oriR[j] ;
		Solve() ;
		cout << "Case #" << i << ": " << Ans << "\n" ;
		fprintf(stderr,"%d:%d\n" , i,Ans) ;
	}
}