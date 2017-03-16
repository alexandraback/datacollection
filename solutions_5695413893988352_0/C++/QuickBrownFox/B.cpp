#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }



void print_case(int test_case) { printf("Case #%d: ", test_case); }

int cn, jm;
char cs[20];
char js[20];

vector<int> cs_possible;
vector<int> js_possible;


void gen(int pos, int end, char in[20], vector<int>& res) {
    if (pos == end) {
        int d;
        sscanf(in, "%d", &d);
        res.push_back(d);
        return;
    }
    if (in[pos] != '?') {
        gen(pos + 1, end, in, res);
    } else {
        for (int d = 0; d < 10; ++d) {
            in[pos] = d + '0';
            gen(pos + 1, end, in, res);
        }
        in[pos] = '?';
    }
}


void solve_case() {
    int i, j;
    cn = getstr(cs);
    jm = getstr(js);

    cs_possible.clear();
    js_possible.clear();

    gen(0, cn, cs, cs_possible);
    gen(0, jm, js, js_possible);

    // for (auto v: cs_possible) cout << v << " "; puts("");
    // for (auto v: js_possible) cout << v << " "; puts("");

    int mn_diff = 1 << 28;
    int mn_sum = 1 << 28;
    int mn_j = 1 << 28;
    int resa, resb;

    for (int cp: cs_possible) for (int jp: js_possible) {
        int d = abs(cp - jp);
        if (chmin(mn_diff, d)) {
            resa = cp, resb = jp, mn_sum = cp + jp, mn_j = jp;
        }
        if (mn_diff == d) {
            if (chmin(mn_sum, cp + jp)) {
                resa = cp, resb = jp, mn_j = jp;
            }
            if (chmin(mn_j, jp)) {
                resa = cp, resb = jp;
            }
        }
    }

    cout << setw(cn) << setfill('0') << resa << " " << setw(jm) << setfill('0') << resb << endl;

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
