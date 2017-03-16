#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
const int maxint = -1u>>1;
int n , T ;
int a[1100] ;
int cal( int j ) {
    int ret = j ;
    repf( i , 1 , n ) {
        if ( a[i] % j == 0 ) ret += a[i] / j - 1 ;
        else ret += a[i] / j ;
    }
    return ret ;
}
int main() {
    freopen("B.out","w",stdout) ;
    scanf("%d" , &T ) ;
    repf( t , 1 , T ) {
        scanf("%d" , &n ) ;
        repf( i , 1 , n ) 
            scanf("%d" , &a[i] ) ;
        int ans = 100000000 ;
        repf( i , 1 , 1000 ) {
            ans = min( ans , cal(i) ) ;
        }
        printf("Case #%d: %d\n" , t , ans ) ;
    }
    return 0;
}

