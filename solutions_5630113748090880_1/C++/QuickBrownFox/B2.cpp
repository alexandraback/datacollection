#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

void print_case(int test_case) { printf("Case #%d:", test_case); }

int cnt[2600];

void solve_case() {
    int i, j;
    int n = getint();
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < n * 2 - 1; ++i) for (j = 0; j < n; ++j) {
        int t = getint();
        cnt[t]++;
    }
    vector<int> res;
    for (i = 0; i < 2600; ++i) if (cnt[i] && (cnt[i] & 1)) res.push_back(i);
    for (auto t: res) cout << " " << t; puts("");
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
