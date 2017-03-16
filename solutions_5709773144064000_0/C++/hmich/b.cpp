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
        double c, f, x;
        in >> c >> f >> x;
        double rate = 2, time = 0;
        double best = x / rate;        
        for (;;) {
            time += c / rate;
            rate += f;
            double res = time + x / rate;
            if (res < best) {
                best = res;
            } else
                break;
        }
        out.precision(10);
        out.setf(ios::fixed);
        out << "Case #" << test << ": " << best << "\n";
    }
    return 0;
}