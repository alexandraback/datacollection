
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
ifstream in( "d.in" );
#else
istream & in = cin;
#endif
//ostream & out = cout;
ofstream out( "d.out" );

int main() {
    int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        int x, r, c;
        in >> x >> r >> c;
        bool win;
        if (x == 1)
            win = false;
        else if (x == 2)
            win = r * c % 2 == 1;
        else if (x == 3) {
            win = !(r >= 2 && c >= 2 && r * c % 3 == 0);
        }
        else if (x == 4) {
            win = !(r * c == 16 || r * c == 12);
        }
        out << "Case #" << test << ": " << (win ? "RICHARD" : "GABRIEL") << '\n';
    }
    return 0;
}