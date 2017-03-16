
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
        int n;
        in >> n;
        vd v(n), w(n);
        for (int i = 0; i < n; ++i)
            in >> v[i];
        for (int i = 0; i < n; ++i)
            in >> w[i];
        sort(all(v));
        sort(all(w));
        auto start = v.begin();
        int dwarpoints = 0;
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(start, v.end(), w[i]);
            if (it == v.end())
                break;
            start = ++it;
            ++dwarpoints;
        }

        start = w.begin();
        int warpoints = 0;
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(start, w.end(), v[i]);
            if (it == w.end()) {
                start = w.end();
                ++warpoints;
            }
            else
                start = ++it;
        }

        out << "Case #" << test << ": " << dwarpoints << ' ' << warpoints << '\n';
    }
    return 0;
}