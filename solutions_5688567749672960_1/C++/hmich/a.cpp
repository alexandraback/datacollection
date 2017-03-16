#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#pragma warning( disable : 4244 4267 4018 4996 4800 )
//#pragma comment( linker, "/stack:10000000" )
using namespace std; 
typedef vector< int > vi; typedef vector< vector< int > > vvi; typedef vector< string > vs; typedef vector< double > vd;
typedef vector< vd > vvd; typedef long long ll; typedef vector< ll > vll; typedef vector< vll > vvll; typedef pair< int, int > pii;
#define all( v ) (v).begin( ), (v).end( )

ifstream in( "a.in" );
ofstream out( "a.out" );

template < class T > T pow( T v, int n ) {
    T res = 1;
    for ( ; n; n >>= 1, v = v * v )
        if ( n & 1 ) res = res * v;
    return res;
}

int count_digits(ll x) {
    int res = 0;
    for (; x; ++res, x /= 10) ;
    return res;
}

ll reverse(ll j) {
    ll res = 0;
    for (; j; j = j / 10) {
        res = res * 10 + j % 10;
    }
    return res;
}

int main() {
    int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        ll x;
        in >> x;
        ll result = 0;
        for (;;) {
            int digits = count_digits(x);
            if (digits == 1) {
                result += x;
                break;
            }
            ll t = pow(10LL, digits / 2);
            if (x % t == 0) {
                --x; ++result; continue;
            }
            ll next = x / t * t + 1;            
            ll xx = reverse(next);
            if (xx != next) {                
                result += x - next + 1;
                x = xx;
            } else {
                result += x - next + 1;
                x = next - 1;
            }
        }
        out << "Case #" << test << ": " << result << "\n";
    }
    return 0;
}