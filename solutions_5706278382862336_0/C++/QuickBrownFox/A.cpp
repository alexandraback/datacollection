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
#include <unistd.h>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

void print_case(int tc) { printf("Case #%d: ", tc); }
#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
ll getll() { unsigned int c; ll x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getll(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
template<class T> T gcd(T x, T y) { T t; while (y) t = y, y = x % y, x = t; return x; }

void solve_case() {
    ll p, q, g;
    int fail = 0, res = 0;
    p = getll(), q = getll();
    g = gcd(p, q);
    p = p / g, q = q / g;
    ll a = q;
    while (q > 1) {
        if (q % 2 == 1) { fail = 1; break; }
        q = q / 2;
        res++;
        if (p >= q) break;
    }
    while (a > 1) {
        if (a % 2) { fail = 1; break; }
        a = a / 2;
    }
    if (fail) {
        puts("impossible");
        return;
    }
    printf("%d\n", res);
}

int main () {
    int tcc, tc = getint();
    for (tcc = 1; tcc <= tc; tcc++) {
        print_case(tcc);
        solve_case();
    }
    return 0;
}
