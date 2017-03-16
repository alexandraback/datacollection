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

int N, M;

vvi lawn;

void output(const vi &row, const vi &col) {
    cout << "lawn:" << endl;
    fev(r, lawn) {
        cout << "\t";
        fev(c, lawn[r]) {
            cout << lawn[r][c] << " ";
        }
        cout << endl;
    }

    cout << "\t";
    fev(i, row) {
        cout << row[i] << " ";
    }
    cout << endl;

    cout << "\t";
    fev(i, col) {
        cout << col[i] << " ";
    }
    cout << endl;
}

string solve() {
    vi row(N, -1), col(M, -1);
    fev(r, lawn) {
        fev(c, lawn[r]) {
            row[r] = max(row[r], lawn[r][c]);
            col[c] = max(col[c], lawn[r][c]);
        }
    }
    // output(row, col);
    fev(r, lawn) {
        fev(c, lawn[r]) {
            if (lawn[r][c] != min(row[r], col[c])) {
                return "NO";
            }
        }
    }
    return "YES";

}

void main2() {
    /*ifstream in("sample.txt");
    ofstream out("sample.output");*/
    ifstream in("B-small-attempt0.in");
    ofstream out("B-small-attempt0.output");
    /*ifstream in("B-large.in");
    ofstream out("B-large.output");*/
    int num_cases;
    in >> num_cases;
    cout << num_cases << endl;
    for (int i = 1; i <= num_cases; ++i) {
        in >> N >> M;
        // cout << N << " " << M << endl;
        lawn.clear();
        lawn.resize(N);
        rep(r, N) {
            lawn[r].resize(M);
            rep(c, M) {
                in >> lawn[r][c];
            }
        }
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
