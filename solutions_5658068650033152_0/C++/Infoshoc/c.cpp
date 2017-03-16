#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <limits>
#include <algorithm>
#include <utility>
#include <complex>
using namespace std;
typedef long long LL; typedef unsigned long long ULL; typedef long double LD; typedef pair<int,int> pii; typedef pair<long,long> pll; typedef vector<int,int> vii;
const LD PI = 3.1415926535897932384626433832795L; const LD EPS = 1e-9;
LL gcd (LL a, LL b) {while(b){a %= b;swap (a, b);}return a;} LL lcm(const LL a,const LL b){return a/gcd(a,b)*b;}LL sign(const LL x){return (x>0)-(x<0);}
template<class T>const T sqr(const T x){return x*x;}
template <class T> const T binpow(const T a, const ULL n, const T modulo){
    return n == 0 ? 1 : sqr ( binpow ( a, n/2, modulo ) ) % modulo * ( n % 2 ? a : 1 ) % modulo;
}

int main(){

    freopen ( "C-small-attempt4.in", "r", stdin );
    freopen ( "C-small-attempt4.out", "w", stdout );

    int testcases;
    scanf ( "%d ", &testcases );

    for ( int testcase = 1; testcase <= testcases; ++testcase ){

        int n, m, k;
        scanf ( "%d %d %d ", &n, &m, &k );

        if ( n > m ){
            swap ( n, m );
        }
        if ( n <= 2 ){
            printf ( "Case #%d: %d\n", testcase, k );
            continue;
        }
        if ( k == n * m-1 ){
            printf ( "Case #%d: %d\n", testcase, 2*n+2*m-5 );
            continue;
        }
        if ( k == n * m-2 ){
            printf ( "Case #%d: %d\n", testcase, 2*n+2*m-6 );
            continue;
        }
        if ( k == n * m-3 ){
            printf ( "Case #%d: %d\n", testcase, 2*n+2*m-7 );
            continue;
        }
        if ( n * m == k ){
            printf ( "Case #%d: %d\n", testcase, ( n + m ) * 2 - 4 );
            continue;
        }
        if ( k > ( n - 1 ) * ( m - 1 ) ){
            printf ( "Case #%d: %d\n", testcase, 2*n+2*m-8 );
            continue;
        }

        int stones;
        bool found = false;
        for ( stones = 0; stones <= n * m && !found; ++stones ){
            for ( int top_side = 0; top_side <= n && 2*top_side <= stones && !found; ++top_side ){
                int left_side = (stones - 2*top_side) / 2;
                if ( top_side * left_side + stones >= k && left_side <= m ){
                    found = true;
                }
            }
        }

        printf ( "Case #%d: %d\n", testcase, min ( stones-1, 2 * (m+n) - 4 ) );
    }

    return 0;
}
