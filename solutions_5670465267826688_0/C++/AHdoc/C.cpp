#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

#define ll 0
#define ii 1
#define jj 2
#define kk 3
#define MP make_pair

const int R[4][4] = {
    // ll , ii , jj , kk
     { ll , ii , jj , kk } ,
     { ii , ll , kk , jj } ,
     { jj , kk , ll , ii } ,
     { kk , jj , ii , ll }
} ;

const int Ro[4][4] = {
    { 1 , 1 , 1 , 1 } ,
    { 1 ,-1 , 1 ,-1 } ,
    { 1 ,-1 ,-1 , 1 } ,
    { 1 , 1 ,-1 ,-1 }
} ;

pair<int,int> MUL(int x , int xo , char c) {
    if ( c == 'i' ) return MP( R[x][ii] , xo * Ro[x][ii] ) ;
    if ( c == 'j' ) return MP( R[x][jj] , xo * Ro[x][jj] ) ;
    if ( c == 'k' ) return MP( R[x][kk] , xo * Ro[x][kk] ) ;
}

const int MAXN = 200000 ;

int N , L ;
int A[MAXN] , O[MAXN] ;
string singleS , S ;

bool Solve() {
    // 1 -1 i -1 j -j k -k
    // 0  1 2  3 4  5 6  7
    A[0] = ll ;
    O[0] = 1 ;
    for ( int i = 1 ; i <= N ; i ++ ) {
        pair<int,int> tmp = MUL(A[i-1] , O[i-1] , S[i-1]) ;
        A[i] = tmp.first ;
        O[i] = tmp.second ;
    }
    
    if ( A[N] != ll || O[N] != -1 ) return false ;
    
    for ( int i = 1 , u = 0 ; i < N ; i ++ ) {
        if ( A[i] == kk && O[i] == 1 && u == 1 ) return true ;
        if ( A[i] == ii && O[i] == 1 ) u = 1 ;
    }
    return false ;
}

int main() {
    freopen("C.in" , "r" , stdin) ;
    freopen("C.out", "w" ,stdout) ;
    
    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        cin >> N >> L ;
        cin >> singleS ;
        S = "" ;
        for ( int j = 1 ; j <= L ; j ++ ) S = S + singleS ;
        
        N = N * L ;
        
        if ( Solve() ) cout << "Case #" << i << ": YES\n" ;
        else           cout << "Case #" << i << ": NO\n" ;
    }
}
