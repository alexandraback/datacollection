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
char s[11000] ;
int main() {
    freopen("A.in","r",stdin) ;
    freopen("A.out","w",stdout) ;
    scanf("%d" , &T ) ;
    repf( t , 1 , T ) {
        scanf("%d" , &n ) ;
        n ++ ;
        scanf("%s" , s ) ;
        int sum = 0 ;
        int ans = 0 ;
        rep( i , n ) {
            int now = s[i] - '0' ;
            if ( sum < i ) {
                ans += i - sum ;
                sum = i ;
            }
            sum += now ;
        }
        printf("Case #%d: %d\n" , t , ans ) ;
    }
    return 0;
}

