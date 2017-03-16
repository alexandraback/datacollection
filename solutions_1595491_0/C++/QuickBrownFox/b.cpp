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

const int N = 111;
int can[40][2];
int n, in[N], cache[N][N], want;

int solve(int pos, int rem) {
    int & res = cache[pos][rem];
    if (~res) return res;
    if (pos == n) return 0;
    res = solve(pos + 1, rem) + (can[in[pos]][0] >= want);
    if (rem) res = max(res, solve(pos + 1, rem - 1) + (can[in[pos]][1] >= want));
    return res;
}

void solve_case() {
    int i, j, p;
    n = getint(), p = getint(), want = getint();
    for (i = 0; i < n; i++) in[i] = getint();
    memset(cache, ~0, sizeof(cache));
    int res = solve(0, p);
    printf("%d\n", res);
}

int main () {
    int tcc, tc = getint();
    int i, j, k, sum, diff;
    memset(can, ~0, sizeof(can));
    for (i = 0; i <= 10; i++) for (j = i; j <= 10; j++) for (k = j; k <= 10; k++) {
        sum = i + j + k;
        diff = k - i;
        if (diff <= 1) can[sum][0] = max(can[sum][0], k);
        if (diff <= 2) can[sum][1] = max(can[sum][1], k);
    }

    for (tcc = 1; tcc <= tc; tcc++) {
        print_case(tcc);
        solve_case();
    }
    return 0;
}
