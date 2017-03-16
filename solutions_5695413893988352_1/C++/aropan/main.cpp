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

struct TResult {
    ll delta, fst, snd;
    TResult push(int x, int y) {
        TResult r = *this;
        (r.fst *= 10) += x;
        (r.snd *= 10) += y;
        r.delta = abs(r.fst - r.snd);
        return r;
    }
};

bool operator<(const TResult& a, const TResult& b)
{
    return a.delta < b.delta ||
        (a.delta == b.delta && a.fst < b.fst) ||
        (a.delta == b.delta && a.fst == b.fst && a.snd < b.snd);
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
        cin >> a >> b;
        vector<TResult> answer(3);
        for (int j = 0; j < 3; ++j) {
            answer[j] = {(ll)3e+18, 0, 0};
        }
        answer[1] = {0, 0, 0};

        int n = a.size();
        for (int i = 0; i < n; ++i) {
            vector<TResult> result(3);
            for (int j = 0; j < 3; ++j) {
                result[j] = {(ll)3e+18, 0, 0};
            }
            for (int x = 0; x < 10; ++x) {
                if (a[i] != '?' && a[i] - '0' != x) {
                    continue;
                }
                for (int y = 0; y < 10; ++y) {
                    if (b[i] != '?' && b[i] - '0' != y) {
                        continue;
                    }
                    for (int s = 0; s < 3; ++s) {
                        if (answer[s].delta > (ll)2e+18) {
                            continue;
                        }
                        TResult r = answer[s].push(x, y);
                        int d = s != 1? s : (x == y? 1 : (x < y? 0 : 2));
                        result[d] = min(result[d], r);
                    }
                }
            }
            answer = result;
        }
        TResult ans = min(answer[0], min(answer[1], answer[2]));
        printf("%0*lld %0*lld", n, ans.fst, n, ans.snd);

        cout << endl;
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
