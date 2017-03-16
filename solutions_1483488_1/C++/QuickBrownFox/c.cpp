#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

void print_case(int tc) { printf("Case #%d: ", tc); }
#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }

const int N = 1e7;
int vis[N], ndigit[N], A, B;

int num_digit(int k) {
    if (k == 0) return 1;
    if (ndigit[k]) return ndigit[k];
    return ndigit[k] = 10 * num_digit(k / 10);
}

ll solve(int k) {
    if (vis[k]) return 0;
    ll res = 0;
    res++, vis[k];
    int t = k, d = ndigit[k];
    for (; ; ) {
        t = t % d * 10 + t / d;
        if (t == k) break;
        if (!vis[t]) {
            if (A <= t and t <= B) {
                res++;
            }
        }
        vis[t] = 1;
    }
    return res;
}

void solve_case() {
    int i, j;
    ll res = 0;
    A = getint(), B = getint();
    memset(vis, 0, sizeof(vis));
    for (i = A; i <= B; i++) {
        ll t = solve(i);
        res += (t - 1) * t / 2;
    }
    printf("%d\n", res);
}

int main () {
    int tcc, tc = getint();
    for (int i = 0; i < N; i++) num_digit(i);
    for (int i = 0; i < N; i++) ndigit[i] /= 10;
    for (tcc = 1; tcc <= tc; tcc++) {
        print_case(tcc);
        solve_case();
    }
    return 0;
}
