#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

void print_case(int test_case) { printf("Case #%d: ", test_case); }

int solve_case() {
    int i, j;
    int n = getint();
    int r = getint();
    int c = getint();
    if (c > r) swap(r, c);

    if (r * c % n != 0) return 0; // impossible

    if (n == 1) return 1;

    if (n == 2) return 1;

    if (n == 3) {
        if (c == 1) {
            return 0;
        }
        if (c == 2) {
            if (r <= 2) return 0;
            return 1;
        }
    }

    if (n == 4) {
        if (c == 1) return 0;
        if (c == 2) return 0;
        if (c == 3 && r == 3) return 0;
        if (c == 3 && r == 4) return 1;
        return 1;
    }

    return -1;
}

int main () {
    int test_count, test_case = getint();
    for (test_count = 0; test_count < test_case; test_count++) {
        print_case(test_count + 1);
        int res = solve_case();
        if (res) {
            puts("GABRIEL");
        } else {
            puts("RICHARD");
        }
    }
    return 0;
}
