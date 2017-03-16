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
#include <future>
//#pragma comment( linker, "/stack:10000000" )
using namespace std; 
typedef vector< int > vi; typedef vector< vector< int > > vvi; typedef vector< string > vs; typedef vector< double > vd;
typedef vector< vd > vvd; typedef long long ll; typedef vector< ll > vll; typedef vector< vll > vvll; typedef pair< int, int > pii;
#define all( v ) (v).begin( ), (v).end( )

ifstream in( "c.in" );
ofstream out( "c.out" );

int main() {
    int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        int ngroups;
        in >> ngroups;
        ll mintime = 2e+9, minstart;
        vll pos, time;
        for (int group = 0; group < ngroups; ++group) {
            ll p, c, t;
            in >> p >> c >> t;
            for (int i = 0; i < c; ++i, ++t) {
                pos.push_back(p);
                time.push_back(t);                
            }
        }
        for (int i = 0; i < pos.size(); ++i) {
            if (time[i] < mintime) {
                mintime = time[i];
                minstart = pos[i];
            }
        }
        int result = 0;
        for (int i = 0; i < pos.size(); ++i) {
            if (mintime != time[i]) {
                ll maxdist = 360 - pos[i];
                ll mindist = 360 - minstart + 360;
                if (mindist * mintime <= maxdist * time[i])
                    ++result;
            }
        }        
        out << "Case #" << test << ": " << result << "\n";
    }
    return 0;
}