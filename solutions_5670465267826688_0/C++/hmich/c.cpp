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

#ifdef LOCAL
ifstream in( "c.in" );
#else
istream & in = cin;
#endif
//ostream & out = cout;
ofstream out( "c.out" );

int const I = 2;
int const J = 3;
int const K = 4;

const int mul_table[][5] = { { 0, 0, 0, 0, 0 }, { 0, 1, I, J, K }, { 0, I, -1, K, -J }, { 0, J, -K, -1, I }, { 0, K, J, -I, -1 } };

int mul(int a, int b) {
    int res = 1;
    if (a < 0) res = -res, a = -a;
    if (b < 0) res = -res, b = -b;    
    return res * mul_table[a][b];
}

ll l, x, length;
vi v, rightmul;


bool solve(int idx) {
    int midacc = 1;
    for (int i = idx + 1; i < idx + 5 * v.size() && i < length; ++i) {
        midacc = mul(midacc, v[i % v.size()]);
        if (midacc == J) {
            int rightacc = rightmul[i % v.size() + 1];
            ll left = x - (i / v.size() + 1);
            for (int j = 0; j < left % 4; ++j)
                rightacc = mul(rightacc, rightmul[0]);
            if (rightacc == K)
                return true;
        }
    }
    return false;
}

int main() {
    int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        string s;
        in >> l >> x >> s;
        length = l * x;
        v.resize(s.size());
        rightmul.resize(s.size() + 1);
        rightmul[s.size()] = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            v[i] = s[i] - 'i' + 2;
            rightmul[i] = mul(v[i], rightmul[i + 1]);
        }
        int acc = 1;
        std::vector<future<bool>> futures;
        for (int i = 0; i < 5 * v.size() && i < length; ++i) {
            acc = mul(acc, v[i % v.size()]);
            if (acc == I)
                futures.push_back(std::async(solve, i));
        }
        bool res = false;
        for (int i = 0; i < futures.size(); ++i)
            res = res || futures[i].get();
        out << "Case #" << test << ": " << (res ? "YES" : "NO") << "\n";
    }
    return 0;
}