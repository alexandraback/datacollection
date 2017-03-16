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

void solve(string s) {
    int x = 0;
    int n = s.length();
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i + 1]) x++;
    }
    if (s[n - 1] == '-') x++;
    cout << x << '\n';
}

int main() {

    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int t;
    t = nextInt<int>();
    for (int i = 1; i <= t; ++i) {
        string s;
        cin >> s;
        printf("Case #%d: ", i);
        solve(s);
    }
    return 0;
}
