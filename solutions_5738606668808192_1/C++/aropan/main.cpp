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

bool check(const vector <int>& a, const int& b, const int& d) {
    int res = 0;
    for (auto& i : a) {
        res *= b;
        res += i;
        res %= d;
    }
    return res == 0;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    srand(time(NULL));

    vector <int> p;
    {
        const int MAXF = 100000;
        vector <bool> f(MAXF, true);
        for (int i = 2; i < MAXF; ++i) {
            if (f[i]) {
                p.push_back(i);
                if (MAXF / i >= i) {
                    for (int j = i * i; j < MAXF; j += i) {
                        f[j] = false;
                    }
                }
            }
        }
    }

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ":" << endl;
        int n;
        size_t k;
        cin >> n >> k;
        vector <int> a(n, 1);
        map < vector <int>, vector <int> > m;
        int l = 42;
        while (m.size() < k) {
            for (int i = 1; i + 1 < n; ++i) {
                a[i] = rand() % 2;
            }
            cerr << a << endl;
            vector <int> r;
            for (int i = 2; i <= 10; ++i) {
                int x = 0;
                for (int j = 0; j < l; ++j) {
                    if (check(a, i, p[j])) {
                        x = p[j];
                        break;
                    }
                }
                cerr << "#" << i << " = " << x << endl;
                if (!x) {
                    r.clear();
                    break;
                }
                r.push_back(x);
            }
            if (r.size() == 0 || m.count(a)) {
                continue;
            }
            m[a] = r;
        }
        for (auto& k : m) {
            for (auto& i : k.first) {
                cout << i;
            }
            for (auto& i : k.second) {
                cout << " " << i;
            }
            cout << endl;
        }
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
