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

int main() {
    vi v(1000001);
    iota(all(v), 0);
    for (int i = 2; i < v.size(); ++i) {
        v[i] = min(v[i], v[i-1] + 1);
        int res = 0;
        for (int j = i; j; j = j / 10) {
            res = res * 10 + j % 10;
        }
        if (res < i && v[res] > v[i] + 1)
            _CrtDbgBreak();
        v[res] = min(v[res], v[i] + 1);
    }
    int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        int x;
        in >> x;
        out << "Case #" << test << ": " << v[x] << "\n";
    }
    return 0;
}