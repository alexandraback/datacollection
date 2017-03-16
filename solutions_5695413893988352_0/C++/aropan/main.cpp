#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>

using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

bool check(string s, int n)
{
    char c[42];
    sprintf(c, "%0*d", (int)s.size(), n);
    if (strlen(c) != s.size()) {
        return false;
    }
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] != '?' && c[i] != s[i]) {
            return false;
        }
    }
    return true;
}

int main(int /* argc */, char** /* argv */)
{
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        string a, b;
        int answer = -1;
        int n, m;

        cin >> a >> b;


        for (int i = 0; i < 1000; ++i) {
            if (check(a, i)) {
                for (int j = 0; j < 1000; ++j) {
                    if (check(b, j)) {
                        int d = abs(i - j);
                        if (answer == -1 || d < answer || (d == answer && i < n) || (d == answer && i == n && j < m)) {
                            answer = d;
                            n = i;
                            m = j;
                        }
                    }
                }
            }
        }
        printf("%0*d %0*d", (int)a.size(), n, (int)b.size(), m);

        cout << endl;
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
