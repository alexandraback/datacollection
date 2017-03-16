#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> st;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 10010;

int pref[MAXN];

int to_int(char c) {
    switch (c) {
        case 'i': return 2;
        case 'j': return 3;
        case 'k': return 4;
        default: assert(false);
    }
}

inline int sign(int a) {
    return a >= 0 ? 1 : -1;
}

inline int ind(bool a) {
    return a ? 1 : -1;
}

int mult(int a, int b) {
    assert(a != 0 && b != 0);
    if (abs(a) == 1 || abs(b) == 1) {
        return a * b;
    }
    int p = abs(a * b);
    if (p == 4 || p == 9 || p == 16) {
        return -1 * sign(a * b);
    }
    if (p == 6) {
        return 4 * sign(a * b) * ind(abs(a) == 2);
    }
    if (p == 8) {
        return 3 * sign(a * b) * ind(abs(a) == 4);
    }
    if (p == 12) {
        return 2 * sign(a * b) * ind(abs(a) == 3);
    }
    return 0;
}

int divide(int a, int b) {
    if (abs(b) == 1) {
        return a * b;
    }
    if (abs(a) == 1) {
        return -1 * b * sign(a);
    }
    return -mult(b, a);
}

int get_mult(int l, int r) {
    return divide(pref[r + 1], pref[l]);
}

string solve() {
    int l, x;
    scanf("%d%d", &l, &x);
    string s, t;
    cin >> t;
    for (int i = 0; i < x; ++i) {
        s += t;
    }
    int len = l * x;
    int cur = 1;
    pref[0] = 1;
    for (int i = 0; i < len; ++i) {
        cur = mult(cur, to_int(s[i]));
        pref[i + 1] = cur;
    }
    if (cur != -1) {
        return "NO";
    }
    for (int i = 0; i < len; ++i) {
        if (get_mult(0, i) == 2) {
            for (int j = i + 1; j < len; ++j) {
                if (get_mult(i + 1, j) == 3 && get_mult(j + 1, len - 1) == 4) {
                    return "YES";
                } 
            }
        }
    }
    return "NO";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    // for (int i = 1; i <= 4; ++i) {
    //     for (int j = 1; j <= 4; ++j) {
    //         for (int sa = -1; sa <= 1; sa += 2) {
    //             for (int sb = -1; sb <= 1; sb += 2) {
    //                 int a = i * sa, b = j * sb;
    //                 int m = mult(a, b);
    //                 assert(divide(m, a) == b);
    //             }
    //         }
    //     }
    // }
    // cerr << "OK\n";
    FOR(i, t) {
        printf("Case #%d: %s\n", i + 1, solve().c_str());
    }
	return 0;
}

