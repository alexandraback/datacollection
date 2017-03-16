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

const int N = 100010;

int A, B, C;
long double p[N], acc[N];

void solve_case() {
    int i, j, k;
    A = getint(), B = getint(), C = B - A;
    long double res = 2 + B;

    for (i = 0; i < A; i++) cin >> p[i];

    acc[0] = p[0];
    for (i = 1; i < A; i++) acc[i] = acc[i - 1] * p[i];

    long double res2 = (C + 1) * acc[A - 1] + (C + 1 + B + 1) * (1 - acc[A - 1]);
    long double res3 = min(res, res2);

    for (k = 1; k < A; k++) {
        long double prob = acc[A - 1 - k];
        int a = (k + k + C + 1);
        int b = (k + k + C + 1 + B + 1);
        long double tmp = a * prob + b * (1 - prob);
        res3 = min(res3, tmp);
    }
    printf("%.6lf\n", (double)res3);
}

int main () {
    int tcc, tc = getint();
    for (tcc = 1; tcc <= tc; tcc++) {
        print_case(tcc);
        solve_case();
    }
    return 0;
}
