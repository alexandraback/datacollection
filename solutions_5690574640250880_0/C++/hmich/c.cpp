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
ifstream in( "c.in" );
#else
istream & in = cin;
#endif
//ostream & out = cout;
ofstream out( "c.out" );

int main() {
    int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        int r, c, m;
        in >> r >> c >> m;
        vvi v(r, vi(c)), seen = v;
        for (int left = m; left > 0; ) {
            int i;
            if (r > c) {                
                for (i = c - 1; i >= 0 && left > 0; --left, --i) {
                    v[r-1][i] = 1;
                }
                if (i == 0 && r > 1) {
                    v[r-1][1] = 0;
                    v[r-2][c-1] = 1;
                }
                --r;
            } else {
                for (i = r - 1; i >= 0 && left > 0; --left, --i) {
                    v[i][c-1] = 1;
                }
                if (i == 0 && c > 1) {
                    v[1][c-1] = 0;
                    v[r-1][c-2] = 1;
                }
                --c;
            }
        }
        queue<pii> q;
        q.push(make_pair(0, 0)); seen[0][0] = 1;
        int cnt = 1;
        while (!q.empty()) {
            pii cur = q.front(); q.pop();
            int bombs = 0;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int x = cur.first + i;
                    int y = cur.second + j;
                    if (x >= 0 && y >= 0 && x < v.size() && y < v[0].size() && v[x][y])
                        ++bombs;
                }
            }
            if (bombs == 0) {
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        int x = cur.first + i;
                        int y = cur.second + j;
                        if (x >= 0 && y >= 0 && x < v.size() && y < v[0].size() && !seen[x][y]) {
                            seen[x][y] = 1;
                            ++cnt;
                            q.push(make_pair(x, y));
                        }                            
                    }
                }
            }
        }
        out << "Case #" << test << ":\n";
        if (cnt + m != v.size() * v[0].size())
            out << "Impossible\n";
        else {
            for (int i = 0; i < v.size(); ++i) {
                for (int j = 0; j < v[0].size(); ++j) {
                    if (i == 0 && j == 0)
                        out << 'c';
                    else if (v[i][j])
                        out << '*';
                    else
                        out << '.';
                }
                out << "\n";
            }
        }
    }
    return 0;
}