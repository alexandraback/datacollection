#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
inline ll getll() { unsigned int c; ll x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getll(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

void print_case(int test_case) { printf("Case #%d: ", test_case); }

int qt[5][5];

int quaternion(int a, int b) {
    const int aa = abs(a), bb = abs(b);
    if (a * b > 0) {
        return qt[aa][bb];
    }
    return -qt[aa][bb];
}

char in_char[100000];
int in[100000];
int n;
ll k;

int solve(int want, int ptr, ll rest) {
    if (want == 5) {
        int now = 1;
        for (; ptr < n; ptr++) now = quaternion(now, in[ptr]);
        rest = rest % 4;
        for (int i = 0; i < rest; i++) {
            for (ptr = 0; ptr < n; ptr++) {
                now = quaternion(now, in[ptr]);
            }
        }
        if (now == 1) return 1;
        return 0;
    }
    int maxIter = 5, now = 1;
    while (maxIter--) {
        for (; ; ) {
            now = quaternion(now, in[ptr]), ptr++;
            if (now == want) {
                if (ptr >= n) {
                    if (rest > 0) {
                        return solve(want + 1, 0, rest - 1);
                    } else {
                        if (want == 4) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                } else {
                    return solve(want + 1, ptr, rest);
                }
            }
            if (ptr == n) break;
        }
        if (rest == 0) { return 0; }
        rest--, ptr = 0;
    }
    return 0;
}

void solve_case() {
    int i, j;
    n = getint(), k = getll();
    getstr(in_char);
    for (i = 0; i < n; i++) {
        if (in_char[i] == 'i') in[i] = 2;
        if (in_char[i] == 'j') in[i] = 3;
        if (in_char[i] == 'k') in[i] = 4;
    }
    int res = solve(2, 0, k - 1);
    if (res) {
        puts("YES");
    } else {
        puts("NO");
    }
    return;
}

int main () {
    qt[1][1] = 1; qt[1][2] =  2; qt[1][3] =  3; qt[1][4] =  4;
    qt[2][1] = 2; qt[2][2] = -1; qt[2][3] =  4; qt[2][4] = -3;
    qt[3][1] = 3; qt[3][2] = -4; qt[3][3] = -1; qt[3][4] =  2;
    qt[4][1] = 4; qt[4][2] =  3; qt[4][3] = -2; qt[4][4] = -1;
    int test_count, test_case = getint();
    for (test_count = 0; test_count < test_case; test_count++) {
        print_case(test_count + 1);
        solve_case();
    }
    return 0;
}
