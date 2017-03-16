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

vector < vector <int> > e;
vector <int> upd;
vector <int> nxt;
vector <int> prv;
int cnt;

bool rec(int x)
{
    if (upd[x] == cnt) {
        return false;
    }
    upd[x] = cnt;
    for (auto& y : e[x]) {
        if (prv[y] == -1 || rec(prv[y])) {
            nxt[x] = y;
            prv[y] = x;
            return true;
        }
    }
    return false;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n;
        cin >> n;
        vector < pair <int, int> > a(n);
        map <string, int> m[2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                string s;
                cin >> s;
                if (!m[j].count(s)) {
                    m[j][s] = m[j].size() - 1;
                }
                (j == 0? a[i].first : a[i].second) = m[j][s];
            }
        }
        int k = m[0].size();
        int l = m[1].size();
        e.clear();
        e.resize(k);
        for (int i = 0; i < n; ++i) {
            e[a[i].first].push_back(a[i].second);
        }
        nxt.clear();
        nxt.resize(k, -1);
        prv.clear();
        prv.resize(l, -1);
        upd.clear();

        upd.resize(k, -1);
        cnt = 0;

        int flow = 0;
        for (int i = 0; i < k; ++i) {
            cnt++;
            if (rec(i)) {
                flow += 1;
            }
        }
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            if (prv[a[i].second] != -1 && nxt[a[i].first] != -1) {
                answer += 1;
            }
        }
        cout << answer - flow;


        cout << endl;
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
