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
typedef vector< vd > vvd; typedef unsigned long long ll; typedef vector< ll > vll; typedef vector< vll > vvll; typedef pair< int, int > pii;
#define all( v ) (v).begin( ), (v).end( )

ifstream in( "a.in" );
ofstream out( "a.out" );

ll root(ll n)
{
    if (n==0) return 0;
    ll l = 0, r = 2 * sqrt(n);
    while (l + 1 < r) {
        ll x = (l + r) / 2;
        ll val = x * x;
        if (val > n)
            r = x;
        else
            l = x;
    }
    return l;
}

void main() {
    int ntests;
    in >> ntests;    
    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ": ";
        ll r, t;
        in >> r >> t;
        t -= (2 * r + 1);
        ll lo = 0, hi = min(root(t / 2), t / (2 * r + 3)) + 1;
        while (lo + 1 < hi) {
            ll x = (lo + hi) / 2;
            ll val = x * x * 2 + x * (2*r+3);
            if (val > t)
                hi = x;
            else
                lo = x;
        }
        out << lo + 1 << "\n";
    }
}