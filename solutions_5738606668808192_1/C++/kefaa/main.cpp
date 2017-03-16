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

vector <ll> cur(9);

ll re = 0;

ll get(ll x, ll n, ll b) {
    for (ll div = 2; div <= 10000; ++div) {
        ll cur = 0;
        ll now = 1;
        for (int i = 0; i < n; ++i) {
            int bit = (x >> i) & 1;
            cur += now * bit;
            cur %= div;
            now = (now * b) % div;
        }
        if (cur == 0) {
            return div;
        }
    }
    return -1;
}

bool ok(ll x, ll n) {
    for (int base = 2; base <= 10; ++base) {
        ll val = get(x, n, base);
        if (val == -1) return false;
        cur[base - 2] = val;
    }
    return true;
}

ll getRandomMask(int n) {
    ll x = 0LL;
    for (int i = 0; i < n; ++i) {
        ll now = rand() % 2;
        if (i == 0 || i == n - 1) now = 1;
        x |= now << i;
    }
    return x;
}

map <ll, ll> was;

void solve(int n, int j) {
    vector < pair <ll, vector <ll> > > answer;
    while(answer.size() < j) {
        ll x = getRandomMask(n);
        if (was.count(x)) continue;
        was[x] = true;
        if(ok(x, n)) answer.push_back(make_pair(x, cur));
    }
    for (auto x: answer) {
        ll mask = x.first;
        auto v = x.second;
        for (int i = 0; i < n; ++i) {
            cout << ((mask >> (n - 1 - i)) & 1);
        }
        for(auto x: v) cout << ' ' << x;
        cout << '\n';
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    srand(time(NULL));
    int t;
    t = nextInt<int>();
    for (int i = 1; i <= t; ++i) {
        int n, j;
        cin >> n >> j;
        printf("Case #%d:\n", i);
        solve(n, j);
    }
    return 0;
}
