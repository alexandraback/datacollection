#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <stack>
#include <assert.h>
// #include <unordered_set>
#include <iomanip>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define mplus(x, y) ((x) == -1 || (y) == -1) ? -1 : ((x) + (y))
#define mmax(x, y) ((x) == -1 || (y) == -1) ? -1 : max((x), (y))
#define mmin(x, y) ((x) == -1) ? (y) : ((y) == -1) ? (x) : min((x), (y))
#define checkbit(n, k) (((1L << (k)) & (n)) != 0)

#define debug(x) cerr << '>' << #x << ':' << x << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;


void convert(char c, bool& minus, bool& i, bool& j) {
    switch (c) {
        case 'h': minus = false; i = false; j = false; break;
        case 'i': minus = false; i = true; j = false; break;
        case 'j': minus = false; i = false; j = true; break;
        case 'k': minus = false; i = true; j = true; break;
        case 'l': minus = true; i = false; j = false; break;
        case 'm': minus = true; i = true; j = false; break;
        case 'n': minus = true; i = false; j = true; break;
        case 'o': minus = true; i = true; j = true; break;
    }
}

char convert(bool minus, bool i, bool j) {
    char c = 'h';
    if (minus) c += 4;
    if (j) c += 2;
    if (i) c += 1;
    return c;
}

char multiply(char a, char b) {
    bool minus1, minus2, i1, i2, j1, j2;
    convert(a, minus1, i1, j1);
    convert(b, minus2, i2, j2);
    bool i = i1 ^ i2;
    bool j = j1 ^ j2;
    bool minus = minus1 ^ minus2 ^ (i1 && i2) ^ (j1 && j2) ^ (j1 && i2);
    return convert(minus, i, j);
}


bool find(string& s, int64 x, int64& i, char c) {
    char cur = 'h';
    int64 n = s.length();
    int64 limit = 4 * n;
    while (cur != c && i < x * n && limit > 0) {
        cur = multiply(cur, s[i % n]);
        ++i;
        --limit;
    }
    return cur == c;
}

bool find_end(string& s, int64 x, int64 i) {
    char cur = 'h';
    int64 n = s.length();
    while ((n * x - i) % (4 * n) != 0) {
        cur = multiply(cur, s[i % n]);
        ++i;
    }
    return cur == 'h';
}

bool can(string& s, int64 x) {
    int64 i = 0;
    if (!find(s, x, i, 'i')) return false;
    // debug(i);
    if (!find(s, x, i, 'j')) return false;
    // debug(i);
    if (!find(s, x, i, 'k')) return false;
    // debug(i);
    if (!find_end(s, x, i)) return false;
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        // debug(tt);
        int64 l, x;
        cin >> l >> x;
        string s;
        cin >> s;
        bool res = can(s, x);
        cout << "Case #" << tt << ": " << (res ? "YES" : "NO") << endl;
    }
}
