#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

#define MAXN 2000000

#define fo(i,a,b) for ( int i = a ; i <= b ; i ++ )

#define LL long long

LL DFA[20] , CeTesu[20] ;

LL minLL( LL u1 , LL u2 ) {
    return u1 < u2 ? u1 : u2 ;
}

LL V(LL x) {
    LL y ;
    for ( y = 0 ; x > 0 ; y = y * 10 + x % 10 , x /= 10 ) ;
    return y ;
}

void Prepare() {
    CeTesu[0] = DFA[0] = 1 ; CeTesu[1] = DFA[1] = 10 ;
    fo(i,2,19) {
        DFA[i] = DFA[i-1] * 10 ;
        CeTesu[i] = CeTesu[i-1] + DFA[(i+1)/2] + DFA[i-(i+1)/2]-1 ;
    }
}

LL Solve(LL x) {
    LL w = -1 , y = x;
    for ( ; y > 0 ; y /= 10 , w ++ ) ;
    if ( x == DFA[w] ) return CeTesu[w] ;
    LL ans = CeTesu[w] + x - DFA[w] , ba = CeTesu[w] ;
    ans = minLL( ans , ba +  (x-1) % DFA[(w+1) / 2] + V(x-1) % DFA[w+1-(w+1)/2] + 1 ) ;
    ans = minLL( ans , ba + V(x-1) % DFA[(w+1) / 2] +  (x-1) % DFA[w+1-(w+1)/2] + 1 ) ;
    return ans;
}

int main() {
    freopen( "A.in" , "r" , stdin ) ;
    freopen( "A.out" , "w" , stdout ) ;
    Prepare() ;
    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        LL x ; cin >> x ;
        cout << "Case #" << i << ": " << Solve(x) << "\n" ;
    }
}
