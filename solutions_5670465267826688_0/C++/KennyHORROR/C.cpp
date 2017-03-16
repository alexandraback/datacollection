#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;

int vvalue[4][4]= {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0},
};

int vsign[4][4] = {
    {1, 1, 1, 1},
    {1, -1, 1, -1},
    {1, -1, -1, 1},
    {1, 1, -1, -1},
};

struct Vector {
    int v;
    int sign;
    Vector(): v(0), sign(1) {}
    Vector operator*(const Vector& second) const {
        Vector result;
        result.v = vvalue[v][second.v];
        result.sign = vsign[v][second.v] * sign * second.sign;
        return result;
    }
};

template<typename T>
T BinPow(T value, long long deg) {
    T result;
    while (deg) {
        if (deg & 1) {
            result = result * value;
        }
        value = value * value;
        deg >>= 1;
    }
    return result;
}

void Solve() {
    long long l, x;
    cin >> l >> x;
    string str;
    cin >> str;
    string prefix;
    for (int i = 0; i < 9 && x; ++i, --x) {
        prefix += str;
    }
    Vector cur;
    int pos = 1;
    for (int i = 0; i < prefix.size(); ++i) {
        Vector t;
        if (prefix[i] == 'i') {
            t.v = 1;
        } else if (prefix[i] == 'j') {
            t.v = 2;
        } else {
            t.v = 3;
        }
        cur = cur * t;
        if (cur.v == pos) {
            cur.v = 0;
            ++pos;
        }
    }
    Vector strv;
    for (int i = 0; i < str.size(); ++i) {
        Vector t;
        if (prefix[i] == 'i') {
            t.v = 1;
        } else if (prefix[i] == 'j') {
            t.v = 2;
        } else {
            t.v = 3;
        }
        strv = strv * t;
    }
    strv = BinPow(strv, x);
    cur = cur * strv;
    if (cur.v == 0 && cur.sign == 1 && pos == 4) {
        puts("YES");
    } else {
        puts("NO");
    }
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
