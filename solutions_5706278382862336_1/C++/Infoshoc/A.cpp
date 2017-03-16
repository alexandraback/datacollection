#include <cstdio>
#include <iostream>
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

    freopen ( "A-large.in", "r", stdin );
    freopen ( "A-large.out", "w", stdout );

    int testcases;
    scanf ( "%d ", &testcases );

    for ( int testcase = 1; testcase <= testcases; ++testcase ){

        long long p, q;
        scanf ( "%I64d/%I64d ", &p, &q );

        long long gcd_pq = gcd ( p, q );
        p /= gcd_pq;
        q /= gcd_pq;

        int answer;
        for ( answer = 1; answer <= 40; ++answer ){
            long long humans = 1LL<<answer;
            if ( humans * p / q >= 1 ){
                break;
            }
        }

        while ( q != 1 && q % 2 == 0 ){
            q /= 2;
        }

        if ( answer > 40 || q != 1 ){
            printf ( "Case #%d: impossible\n", testcase );
        } else {
            printf ( "Case #%d: %d\n", testcase, answer );
        }
    }

    return 0;
}
