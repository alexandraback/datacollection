#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fcntl.h>
#include <fstream>
// #include <hash_map>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unistd.h>
#include <utility>
#include <vector>

using namespace std;
// using namespace __gnu_cxx;  // Essential if you want to use hash_map.

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef pair<ll, ll> pll;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <double> vd;
typedef vector <string> vs;
typedef vector <pii> vpii;

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fe(it, X) for (typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)  // -std=gnu++98, 0x, 11.
#define fev(i, v) for (int i = 0; i < sz(v); ++i)
#define pb push_back
#define pf pop_front
#define mp(a, b) make_pair(a, b)
#define sz(x) (static_cast<int> ((x).size()))
#define sqr(x) ((x) * (x))

char grid[4][4];

string solve() {
    string ans = "";
    bool X = false;
    pii p(-1, -1);
    bool draw = true;
    rep(i, 4) {
        rep(j, 4) {
            if (grid[i][j] != 'T' && grid[i][j] != '.') {
                X = !X;
            } else if (grid[i][j] == 'T') {
                p.first = i;
                p.second = j;
            } else if (grid[i][j] == '.') {
                draw = false;
            } else {
                assert(false);
            }
        }
    }
    char tgt = X ? 'X' : 'O';
    if (p.first >= 0 && p.second >= 0) {
        grid[p.first][p.second] = tgt;
    }
    vector<bool> row(4, true), col(4, true), pl(7, true), mi(7, true);
    rep(i, 4) {
        rep(j, 4) {
            if (grid[i][j] != tgt) {
                row[i] = false;
                col[j] = false;
                pl[i + j] = false;
                mi[i - j + 3] = false;
            }
        }
    }
    fev(i, row) {
        if (row[i]) {
            ans = tgt;
            ans += " won";
            return ans;
        }
    }
    fev(i, col) {
        if (col[i]) {
            ans = tgt;
            ans += " won";
            return ans;
        }
    }
    if (pl[3]) {
        ans = tgt;
        ans += " won";
        return ans;
    }
    if (mi[3]) {
        ans = tgt;
        ans += " won";
        return ans;
    }
    if (draw) {
        ans = "Draw";
        return ans;
    } else {
        ans = "Game has not completed";
        return ans;
    }
}

void output() {
    cout << "Grid: " << endl;
    rep(r, 4) {
        cout << "\t";
        rep(c, 4) {
            cout << grid[r][c];
        }
        cout << endl;
    }
    cout << endl;
}

void main2() {
    /*ifstream in("sample.txt");
    ofstream out("sample.output");*/
    ifstream in("A-small-attempt0.in");
    ofstream out("A-small-attempt0.output");
    /*ifstream in("A-large-practice.in");
    ofstream out("A-large-practice.output");*/
    int num_cases;
    in >> num_cases;
    cout << num_cases << endl;
    for (int i = 1; i <= num_cases; ++i) {
        rep(r, 4) {
            rep(c, 4) {
                in >> grid[r][c];
            }
        }
        // output();
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
        out << "Case #" << i << ": " << ans << endl;
    }
    in.close();
    out.close();
}

int main() {
    main2();

    return 0;
}
