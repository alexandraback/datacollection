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
typedef vector< vd > vvd; typedef long long ll; typedef vector< ll > vll; typedef vector< vll > vvll; typedef pair< int, int > pii;
#define all( v ) (v).begin( ), (v).end( )

ifstream in( "b.in" );
ofstream out( "b.out" );

template <class T>
void make_max(T& x, T val) {
    if (x < val)
        x = val;
}

void main() {
    int ntests;
    in >> ntests;
    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ": ";
        int e, r, n;
        in >> e >> r >> n;
        vi v(n);
        vi gain(e + 1), newgain(e+1);
        for (int i = 0; i < n; ++i) {
            in >> v[i];
            newgain.assign(e+1, 0);
            for (int j = 0; j <= e; ++j) {
                for (int k = 0; k <= j; ++k) {
                    make_max(newgain[min(e, j-k+r)], gain[j] + k * v[i]);
                }
            }
            newgain.swap(gain);
        }
        out << *max_element(all(gain)) << "\n";
    }
}