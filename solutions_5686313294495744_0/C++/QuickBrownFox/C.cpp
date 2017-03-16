#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

void print_case(int test_case) { printf("Case #%d: ", test_case); }

template<class T> struct IndexGetter {
    map<T, int> fmp;
    vector<T> rmp;
    int n;
    IndexGetter() { n = 0; }
    int get(T a) {
        if (!fmp.count(a)) { fmp[a] = n, rmp.push_back(a); return n++; }
        return fmp[a];
    }
    T rget(int idx) { return rmp[idx]; }
    int size() { return n; }
    void clear() { n = 0, fmp.clear(), rmp.clear(); }
};

IndexGetter<string> ig;

int n;
char in[100];

int words[20][2];

void solve_case() {
    int i, j;
    n = getint();
    ig.clear();
    for (i = 0; i < n; ++i) {
        getstr(in), words[i][0] = ig.get(string(in));
        getstr(in), words[i][1] = ig.get(string(in));
    }
    int res = 0;
    for (int h = 0; h < 1 << n; ++h) {
        int t = __builtin_popcount(h);
        if (t <= res) continue;
        int ok = 1;
        for (i = 0; i < n; ++i) if (h >> i & 1) {
            int fst = words[i][0];
            int snd = words[i][1];
            int okFst = 0, okSnd = 0;
            for (j = 0; j < n; j++) if (~h >> j & 1) {
                if (fst == words[j][0]) okFst = 1;
                if (snd == words[j][1]) okSnd = 1;
            }
            if (okFst == 0 || okSnd == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            chmax(res, t);
        }
    }
    cout << res << endl;
    return;
}

int main () {
    int test_count, test_case = getint();
    for (test_count = 0; test_count < test_case; test_count++) {
        print_case(test_count + 1);
        solve_case();
    }
    return 0;
}
