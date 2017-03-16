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

ifstream in( "b.in" );
ofstream out( "b.out" );

int main() {
    int ntest;
    in >> ntest;
    for (int test = 1; test <= ntest; ++test) {
        int n, m;
        in >> n >> m;
        vvi v(n, vi(m));        
        vector<pair<int, pii>> height;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                in >> v[i][j];
                height.push_back(make_pair(v[i][j], make_pair(i, j)));
            }
        }
        sort(all(height));
        bool valid = true;
        for (int i = 0; i < height.size(); ++i) {
            int h = height[i].first;
            int x = height[i].second.first;
            int y = height[i].second.second;

            bool xtest = true;
            for (int j = 0; j < m; ++j) if (v[x][j] != -1 && v[x][j] > h) {
                xtest = false; break;
            }

            bool ytest = true;
            for (int j = 0; j < n; ++j) if (v[j][y] != -1 && v[j][y] > h) {
                ytest = false; break;
            }

            if (!xtest && !ytest) {
                valid = false; break;
            }

            v[x][y] = -1;
        }
        out << "Case #" << test << ": " << (valid ? "YES" : "NO") << "\n";
    }
    return 0;
}