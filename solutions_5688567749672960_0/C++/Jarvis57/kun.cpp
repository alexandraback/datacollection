//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i ++)
#define DOW(i, a, b) for(int i = a; i >= b; i --)
#define RESET(c, val) memset(c, val, sizeof(c))
#define oo 1e9
#define eps 1e-9
#define base 1000000007
#define maxn 100005
#define maxx 10000000

int f[1000005];
queue<int> q;

int flip(int u) {
    int res = 0;
    while (u != 0) {
        res = res * 10 + u % 10;
        u /= 10;
    }
    return res;
}

long long cc(long long n) {
    long long k = 0;
    while (k * 10 + 9 < n) {
        k = k * 10 + 9;
    }
    return n - k;
}

long long cal(long long n) {
    if (n % 10 == 0) return min(cc(n), cal(n - 1) + 1);

    int ns = 0, a[20];
    long long rr = cc(n);
    long long res = 0;

    while (n != 0) {
        a[++ns] = n % 10;
        n /= 10;
    }

    FOR(i, 1, (ns+1) / 2) {
        if (i == ns + 1 - i) res = res * 10 + a[i];
        else res = res * 10 + a[i] + a[ns + 1 - i];
    }

    return min(rr, res + 1);
}

long long solve(long long n) {
    long long res = 0;
    long long k = 1;
    while (k <= n) {
        if (n != k)
            res += cal(min(k * 10 - 1, n));
        else 
            res ++;
        k = min(k * 10 - 1, n);
        k++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("A_small.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int test;
    cin >> test;

    RESET(f, 0);
    f[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u < 1000000 && f[u + 1] == 0) {
            f[u + 1] = f[u] + 1;
            q.push(u + 1);
        }
        int v = flip(u);
        if (v < 1000000 && f[v] == 0) {
            f[v] = f[u] + 1;
            q.push(v);
        }
    }

    // FOR(i, 1, 10000) if (f[i] != solve(i)) {
    //     cout << i << " " << f[i] << " " << solve(i) << endl;
    // }
    // return 0;

    FOR(t, 1, test) {
        cout << "Case #" << t << ": ";

        long long n;
        cin >> n;

        // cout << solve(n) << endl;
        cout << f[n] << endl;
    }
    return 0;
}