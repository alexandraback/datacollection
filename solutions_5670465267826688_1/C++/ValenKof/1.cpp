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

const string IJK = "1ijk";

inline int of(const char& c) {
    return IJK.find(c);
}

struct Number {
    int index;
    int sign;

    Number() : index(0), sign(+1) { }

    Number(int index_, int sign_) : index(index_), sign(sign_) { }

    Number(const char& c) : index(of(c)), sign(+1) { }
};

int mul_index[4][4] = {
    {of('1'), of('i'), of('j'), of('k')},
    {of('i'), of('1'), of('k'), of('j')},
    {of('j'), of('k'), of('1'), of('i')},
    {of('k'), of('j'), of('i'), of('1')},
};

int mul_sign[4][4] = {
    {+1, +1, +1, +1},
    {+1, -1, +1, -1},
    {+1, -1, -1, +1},
    {+1, +1, -1, -1},
};

Number operator*(const Number& a, const Number& b) {
    int index = mul_index[a.index][b.index];
    int sign = mul_sign[a.index][b.index] * a.sign * b.sign;
    return Number(index, sign);
}

bool operator==(const Number& a, const Number& b) {
    return a.index == b.index && a.sign == b.sign;
}

Number bin_pow(Number a, long long n) {
    Number x;
    while (n) {
        if (n & 1) {
            x = a * x;
        }
        a = a * a;
        n >>= 1;
    }
    return x;
}

ostream& operator<<(ostream& ostr, const Number& number) {
    if (number.sign == -1) ostr << '-';
    ostr << IJK[number.index];
    return ostr;
}

bool operator<(const Number& a, const Number& b) {
    if (a.index != b.index) {
        return a.index < b.index;
    }
    return a.sign < b.sign;
}


const Number I = Number('i');
const Number J = Number('j');
const Number K = Number('k');
const Number need = I * J * K;

void solve() {
    int l;
    long long x;
    cin >> l >> x;
    string s;
    cin >> s;
    vector<Number> a(l);
    Number block;
    forn (i, l) {
        a[i] = Number(s[i]);
        block = block * a[i];
    }
    Number full = bin_pow(block, x);
    if (!(full == need)) {
        cout << "NO" << endl;
        return;
    }

    vector<map<Number, int>> prefix(5);
    Number current_prefix;
    for (int i = 0; i < l; ++i) {
        current_prefix = current_prefix * a[i];
        Number number = current_prefix;
        for (int p = 0; p < 5; ++p) {
            if (!prefix[p].count(number)) {
                prefix[p][number] = i;
            }
            number = block * number;
        }
    }


    vector<map<Number, int>> suffix(5);
    Number current_suffix;
    for (int i = l - 1; i >= 0; --i) {
        current_suffix = a[i] * current_suffix;
        Number number = current_suffix;
        for (int p = 0; p < 5; ++p) {
            if (!suffix[p].count(number)) {
                suffix[p][number] = i;
            }
            number = number * block;
        }
    }

    for (int i = 0; i < 5; ++i) {
        if (!prefix[i].count(I)) continue;
        for (int j = 0; j < 5; ++j) {
            if (!suffix[j].count(K)) continue;
            if ((i + 1) + (j + 1) <= x) {
                cout << "YES" << endl;
                return;
            }
            if (i + j + 1 == x && prefix[i][I] + 1 < suffix[j][K]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    freopen("C-large.in.txt", "r", stdin);
    // freopen("B-large.in.txt", "r", stdin);
    freopen("C.txt", "w", stdout);
    // cout << J * I * J << endl;
    // cout << J * I * J * I * J * I << endl;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}