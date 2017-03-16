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

const int maxN = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int INF = (int)1e9 + 5;
const ll LLINF = (ll)1e18 + 5;


int main() {

    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);

    int t;
    t = nextInt<int>();
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        int k, c, s;
        cin >> k >> c >> s;
        assert(k == s);
        for (int j = 1; j <= k; ++j) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
