#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

int main () {
    int i, j, tcc, tc = getint();
    for (tcc = 1; tcc <= tc; tcc++) {
        char in[111];
        int n = getstr(in), res = 0;
        char now = in[0];
        for (i = 1; i < n; ++i) if (now != in[i]) {
            now = in[i], res++;
        }
        if (now == '-') res++;
        printf("Case #%d: ", tcc);
        cout << res << endl;
    }
    return 0;
}
