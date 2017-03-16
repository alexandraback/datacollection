#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl

template<typename T> inline int sz(const T& x) { return (int) x.size(); }
template<typename T> inline void mn(T& x, const T& y) { if (y < x) x = y; }
template<typename T> inline void mx(T& x, const T& y) { if (x < y) x = y; }

typedef long long ll;

const double PI = 2 * acos(0);

// <---------------- actual solution begins here ---------------->

const int N = 7;

pair<int, int> min(const vector<vector<int>>& field, int goal) {
    forn (i, sz(field)) {
        forn (j, sz(field[i])) {
            if (field[i][j] == goal) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(1000, 1000);
}

long long mask(const vector<vector<int>>& field) {
    int min_i = 1000;
    int min_j = 1000;
    forn (i, sz(field)) {
        forn (j, sz(field[i])) {
            if (field[i][j]) {
                mn(min_i, i);
                mn(min_j, j);
            }
        }
    }
    long long mask = 0;
    forn (i, sz(field)) {
        forn (j, sz(field[i])) {
            if (field[i][j]) {
                int index = (i - min_i) * N + (j - min_j);
                mask |= 1LL << index;
            }
        }
    }
    return mask;
}

vector<vector<int>> field(const long long& mask) {
    vector<vector<int>> field(N, vector<int>(N, 0));
    forn (i, N) {
        forn (j, N) {
            int index = i * N + j;
            if ((mask >> index) & 1) {
                field[i][j] = 1;
            }
        }
    }
    return field;
}

vector<vector<int>> rotate(const vector<vector<int>>& field) {
    int n = sz(field);
    int m = sz(field[0]);
    vector<vector<int>> rotate(m, vector<int>(n));
    forn (i, n) {
        forn (j, m) {
            rotate[j][n - 1 - i] = field[i][j];
        }
    }
    return rotate;
}

vector<vector<int>> mirror(const vector<vector<int>>& field) {
    int n = sz(field);
    int m = sz(field[0]);
    vector<vector<int>> mirror(n, vector<int>(m));
    forn (i, n) {
        forn (j, m) {
            mirror[i][m - 1 - j] = field[i][j];
        }
    }
    return mirror;
}

long long min_shift(vector<vector<int>> field) {
    long long x = 1e18;
    forn (i, 2) {
        forn (j, 4) {
            mn(x, mask(field));
            field = rotate(field);
        }
        field = mirror(field);
    }
    return x;
}

set<long long> figures;
set<long long> cache;

void print(const vector<vector<int>>& f) {
    forn (i, sz(f)) {
        forn (j, sz(f[i])) {
            cout << (f[i][j] ? '#' : '_');
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
}

void gen(int d, int left, int prevL, int prevR, int dim, vector<vector<int>>& f) {
    if (left == 0) {
        figures.insert(min_shift(f));
        return;
    }
    if (d == dim) {
        return;
    }
    for (int r = 0; r < dim; ++r) {
        for (int l = 0; l <= r; ++l) {
            if (max(prevL, l) <= min(prevR, r) && left >= (r - l + 1)) {
                fill(f[d].begin() + l, f[d].begin() + r + 1, 1);
                gen(d + 1, left - (r - l + 1), l, r, dim, f);                
                fill(f[d].begin() + l, f[d].begin() + r + 1, 0);
            }            
        }
    }
}

bool can_place(const vector<vector<int>>& field, const vector<vector<int>>& figure, int place_i, int place_j) {
    forn (i, sz(figure)) {
        forn (j, sz(figure[0])) {
            if (figure[i][j]) {
                int field_i = place_i + i;
                int field_j = place_j + j;
                if (field_i >= sz(field) || field_j >= sz(field[0])) {
                    return false;
                }
                if (field_i < 0 || field_j < 0) {
                    return false;
                }
                if (field[field_i][field_j]) {
                    return false;
                }
            }
        }
    }
    return true;    
}

void place(vector<vector<int>>& field, const vector<vector<int>>& figure, int place_i, int place_j, int what) {
    forn (i, sz(figure)) {
        forn (j, sz(figure[0])) {
            if (figure[i][j]) {
                int field_i = place_i + i;
                int field_j = place_j + j;
                field[field_i][field_j] = what;
            }
        }
    }
}

bool can(vector<vector<int>>& f, int r, int c) {
    pair<int, int> field_min = min(f, 0);
    if (field_min == make_pair(1000, 1000)) {
        return true;
    }
    for (long long m : figures) {
        vector<vector<int>> figure = field(m);
        forn (i, 2) {
            forn (j, 4) {
                pair<int, int> figure_min = min(figure, 1);
                if (can_place(f, figure, field_min.first - figure_min.first, field_min.second - figure_min.second)) {
                    place(f, figure, field_min.first - figure_min.first, field_min.second - figure_min.second, 1);
                    if (can(f, r, c)) {
                        cache.insert(m);
                        return true;
                    }
                    place(f, figure, field_min.first - figure_min.first, field_min.second - figure_min.second, 0);
                }
                figure = rotate(figure);
            }
            figure = mirror(figure);
        }
    }
    return false;
}

bool can(long long mask, int r, int c) {
    if (cache.count(mask)) return true;
    vector<vector<int>> f(r, vector<int>(c, 0));
    vector<vector<int>> figure = field(mask);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (can_place(f, figure, i, j)) {
                place(f, figure, i, j, 1);
                if (can(f, r, c)) {
                    return true;
                }
                place(f, figure, i, j, 0);
            }
        }
    }
    return false;
}

bool solve() {
    int x, r, c;
    cin >> x >> r >> c;
    // if (r * c % x != 0) {
        // return true;
    // }
    if (x >= 7) {
        return true;
    }
    figures.clear();
    cache.clear();
    vector<vector<int>> gen_f(N, vector<int>(N, 0));
    gen(0, x, 0, x - 1, x, gen_f);
    for (long long mask : figures) {
        if (!can(mask, r, c) && !can(mask, c, r)) {
            return true;
        }
    }
    // debug(sz(figures));
    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);
    freopen("D-small-attempt2.in.txt", "r", stdin);
    freopen("D.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        // cout << (solve() ? "EXIST" : "NO") << endl;
        cout << (solve() ? "RICHARD" : "GABRIEL") << endl;
    }
    return 0;
}