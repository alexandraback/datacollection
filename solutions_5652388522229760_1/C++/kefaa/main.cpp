#include <functional>
#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <cassert>
#include <bitset>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

template <typename T>
T nextInt() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if (ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * p;
}

const int maxN = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int INF = (int)1e9 + 5;
const ll LLINF = (ll)1e18 + 5;

void solve(int x) {
    if (x == 0) {
        printf("INSOMNIA");
        return;
    }
    vector <int> c(10);
    int y = x;
    while(true) {
        int p = x;
        while(p > 0) {
            c[p % 10] = 1;
            p /= 10;
        }
        bool ok = true;
        for (int i = 0; i < 10; ++i) {
            if (c[i] == 0) ok = false;
        }
        if (ok) {
            printf("%d", x);
            return;
        }
        x += y;
        assert(x <= INF);
    }
}

int main() {

    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int t;
    t = nextInt<int>();
    for (int i = 1; i <= t; ++i) {
        int x;
        x = nextInt<int>();
        printf("Case #%d: ", i);
        solve(x);
        printf("\n");

    }
    return 0;
}
