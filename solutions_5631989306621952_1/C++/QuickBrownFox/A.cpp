#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

void print_case(int test_case) { printf("Case #%d: ", test_case); }

char in[1 << 10];

void solve_case() {
    int i, j;
    int n = getstr(in);
    deque<char> res(1);
    res[0] = in[0];
    for (i = 1; i < n; ++i) {
        char c = in[i];
        if (c >= res.front()) {
            res.push_front(c);
        } else {
            res.push_back(c);
        }
    }
    for (auto c: res) cout << c; puts("");
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
