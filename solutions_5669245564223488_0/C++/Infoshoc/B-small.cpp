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
const int MODULO = 1000000007;
const int MAXN = 123;
LL gcd (LL a, LL b) {while(b){a %= b;swap (a, b);}return a;} LL lcm(const LL a,const LL b){return a/gcd(a,b)*b;}LL sign(const LL x){return (x>0)-(x<0);}
template<class T>const T sqr(const T x){return x*x;}
template <class T> const T binpow(const T a, const ULL n, const T modulo){
    return n == 0 ? 1 : sqr ( binpow ( a, n/2, modulo ) ) % modulo * ( n % 2 ? a : 1 ) % modulo;
}

int n;
string cars[MAXN];
int cars_idx[MAXN];

bool check() {
    string implode = "";
    for ( int i = 0; i < n; ++i ){
        implode += cars[cars_idx[i]];
    }

    static bool used['z'+1];
    memset ( used, false, sizeof ( used ) );
    for ( int i = 0; i < (int)implode.size(); ++i ){
        if ( used[(int)implode[i]] && implode[i-1] != implode[i] ){
            return false;
        } else {
            used[(int)implode[i]] = true;
        }
    }

    return true;
}

int main(){

    freopen ( "B-small-attempt2.in", "r", stdin );
    freopen ( "B-small-attempt2.out", "w", stdout );

    int t;
    scanf ( "%d ", &t );

    for ( int testcase = 1; testcase <= t; ++testcase ){

        scanf ( "%d ", &n );

        for ( int i = 0; i < n; ++i ){
            string car;
            cin >> car;
            cars[i].clear();
            cars[i].push_back(car[0]);
            for ( int j = 1; j < (int)car.size(); ++j ){
                if ( cars[i][(cars[i].size()-1)] != car[j] ){
                    cars[i].push_back(car[j]);
                }
            }
            cars_idx[i] = i;
        }

        int cnt = 0;
        do{
            cnt += check();
            cnt %= MODULO;
        }while( next_permutation(cars_idx, cars_idx + n) );

        printf ( "Case #%d: %d\n", testcase, cnt );
    }

    return 0;
}
