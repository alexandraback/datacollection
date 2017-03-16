#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }


ll power(ll x, ll e) {
    if (e == 0) return 1;
    ll y = power(x, e >> 1);
    y *= y;
    if (e & 1) y *= x;
    return y;
}

int main () {
    int i, j, tcc, tc = getint();
    for (tcc = 1; tcc <= tc; tcc++) {
        int k = getint(), c = getint(), s = getint();
        ll checkedNumer = 0;
        vector<ll> res;
        for (i = 0; i < s; ++i) {
            ll want = 0;
            for (j = 0; j < c; j++) {
                want += checkedNumer * power(k, j);
                checkedNumer++;
                if (checkedNumer == k) break;
            }
            res.push_back(want);
            if (checkedNumer == k) break;
        }
        printf("Case #%d:", tcc);
        if (checkedNumer < k) {
            puts(" IMPOSSIBLE");
        } else {
            for (auto v: res) cout << " " << v + 1; puts("");
        }
    }
    return 0;
}
