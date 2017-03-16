#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long LL ;

long long Solve(long long A , long long B , long long K) {
    long long ret = 0 ;
    for ( LL i = 0 ; i < A ; i ++ )
        for ( LL j = 0 ; j < B ; j ++ )
            if ( (i & j) < K ) ret ++ ;
    return ret ;
}

int main() {
    freopen("B.in" ,"r",stdin) ;
    freopen("B.out","w",stdout) ;
    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        long long A , B , K ;
        cin >> A >> B >> K ;
        cout << "Case #" << i << ": " << Solve(A,B,K) << "\n" ;
    }
}
