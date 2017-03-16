#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

bool try_fill_hor(vector<string> & v, int r, int c, int m) {
    if (r >= 2 && m <= (r-2)*c) {
        if (c == 1 || m % c != c-1) {
            for (int i = 1; i <= m/c; ++i) for (int j = 0; j < c; ++j)
                v[r-i][j] = '*';
            for (int j = 0; j < m%c; ++j) v[r-m/c-1][j] = '*';
            return true;
        }
        if (m / c < r-3 && c != 2) {
            for (int i = 1; i <= m/c; ++i) for (int j = 0; j < c; ++j)
                v[r-i][j] = '*';
            for (int j = 0; j < m%c-1; ++j) v[r-m/c-1][j] = '*';
            v[r-m/c-2][0] = '*';
            return true;
        }
    }
    return false;
}

void transpose(vector<string> & v) {
    vector<string> vt(v[0].size(), string(v.size(), '.'));
    for (int i = 0; i < v.size(); ++i) for (int j = 0; j < v[i].size(); ++j)
        vt[j][i] = v[i][j];
    v.swap(vt);
}

bool fill(vector<string> & v, int r, int c, int m) {
    if (m == 0) {
        return true;
    }
    if (m == r*c-1) {
        for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
            v[i][j] = '*';
        v[0][0] = 'c';
        return true;
    }
    if (try_fill_hor(v,r,c,m)) {
        return true;
    }
    transpose(v);
    if (try_fill_hor(v,c,r,m)) {
        transpose(v);
        return true;
    }
    transpose(v);
    if (m < r + c - 1) {
        return false;
    }
    if (r == 1 || c == 1) {
        cerr << r << ' ' << c << ' ' << m << endl;
        assert(0);
    }
    if (r == 2 || c == 2) {
        return false;
    }
    for (int i = 0; i < c; ++i) v[r-1][i] = '*';
    for (int i = 0; i < r; ++i) v[i][c-1] = '*';
    return fill(v, r-1, c-1, m-r-c+1);
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d:\n", test);
        int r,c,m;
        cin >> r >> c >> m;
        vector<string> v(r, string(c, '.'));
        v[0][0] = 'c';
        if (fill(v, r, c, m)) {
            assert(v.size() == r && v[0].size() == c);
            int cnt = 0;
            for (int i = 0; i < v.size(); ++i) {
                for (int j = 0; j < v[0].size(); ++j)
                    if (v[i][j] == '*')
                        ++cnt;
                cout << v[i] << endl;
            }
            if (cnt != m) {
                cout << r << ' ' << c << ' ' << m << endl;
                assert(0);
            }
        } else {
            if (!(r*c-m != 6 && r*c-m != 4 && (min(r,c) < 3 || r*c-m != 9 && r*c-m != 12 && r*c-m != 16 && r*c-m != 20))) {
                cerr << r << ' ' << c << ' ' << m << endl;
                assert(0);
            }
            cout << "Impossible\n";
        }
    }
    return 0;
}
