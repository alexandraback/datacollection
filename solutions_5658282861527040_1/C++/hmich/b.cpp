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

#ifdef LOCAL
ifstream in( "b.in" );
#else
istream & in = cin;
#endif
//ostream & out = cout;
ofstream out( "b.out" );

int main() {
   int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        ll a, b, k;
        in >> a >> b >> k;
        ll res = 0;
        for (int zerobit = 0; zerobit < 32; ++zerobit) if (k & (1 << zerobit)) {
            ll cnt[33][2][2] = {};
            int max = 32;
            cnt[max][0][0] = 1;
            for (int pos = max-1; pos >= 0; --pos) {
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        for (int b1 = 0; b1 < 2; ++b1) {
                            for (int b2 = 0; b2 < 2; ++ b2) {
                                if (i == 0 && bool(a & (1 << pos)) != b1)
                                    continue;
                                if (j == 0 && bool(b & (1 << pos)) != b2)
                                    continue;
                                if (pos == zerobit && b1 & b2)
                                    continue;
                                if (pos > zerobit) {
                                    if (k & (1 << pos)) {
                                        if (!b1 || !b2) continue;
                                    } else {
                                        if (b1 && b2) continue;
                                    }
                                }
                                for (int ii = 0; ii <= i; ++ii) {
                                    if (ii == 0 && i == (b1 == bool(a & (1 << pos))))
                                        continue;
                                    if (ii == 0 && b1 > bool(a & (1 << pos)))
                                        continue;
                                    for (int jj = 0; jj <= j; ++jj) {
                                        if (jj == 0 && j == (b2 == bool(b & (1 << pos))))
                                            continue;
                                        if (jj == 0 && b2 > bool(b & (1 << pos)))
                                            continue;
                                        if (cnt[pos+1][ii][jj] == 0)
                                            continue;
                                        cnt[pos][i][j] += cnt[pos+1][ii][jj];
                                    }
                                }
                            }
                        }
                    }
                }
            }            
            res += cnt[0][1][1];
        }
        out << "Case #" << test << ": " << res;
        out << "\n";
    }
    return 0;
}