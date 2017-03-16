#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <queue>
#include <deque>
#include <memory.h>
#include <complex>
#include <numeric>

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define INF (1000000000)
#define LINF (1000000000000000000ll)
#define EPS (1e-9)

#define MOD 1000000007

#define NAME "test-large"
#ifndef NAME
    #error Write problem name!
#endif

using namespace std;

typedef long long li;
typedef unsigned long long uli;

li gcd(li x, li y){
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

li lcm(li x, li y){
    return x / gcd(x, y) * y;
}

li binpow(li a, li p){
    if (!p)
        return 1;
    li g = binpow(a, p >> 1);
    if (p % 2 == 0)
        return (g * g) % MOD;
    else
        return (((g * g) % MOD) * a) % MOD;
}

li rev(li n){
    return binpow(n, (li)MOD - 2LL);
}

void solve(int test_number);

int main() {
#ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    assert(freopen(NAME ".out", "w", stdout));
#endif
    cout.setf(ios::fixed);
    cout.precision(20);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve(i + 1);
}

li a, b, k;
li dp[100][3][3][3];

li solve(int bit, int sa, int sb, int sk) {
    //cout << bit << ' ' << sa << ' ' << sb << ' ' << sk << endl;
    if (bit == -1)
        return 1;
    if (dp[bit][sa][sb][sk] != -1)
        return dp[bit][sa][sb][sk];


    dp[bit][sa][sb][sk] = 0;

    int ba, bb, bk;
    if ((a & (1LL << bit)) != 0LL)
        ba = 1;
    else
        ba = 0;
    if ((b & (1LL << bit)) != 0LL)
        bb = 1;
    else
        bb = 0;
    if ((k & (1LL << bit)) != 0LL)
        bk = 1;
    else
        bk = 0;

    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++) {
            int l = i & j;
            if ((ba >= i || !sa) && (bb >= j || !sb) && (bk >= l || !sk)) {
                int na, nb, nk;
                if (!sa || ba > i)
                    na = 0;
                else
                    na = 1;
                if (!sb || bb > j)
                    nb = 0;
                else
                    nb = 1;
                if (!sk || bk > l)
                    nk = 0;
                else
                    nk = 1;
                dp[bit][sa][sb][sk] += solve(bit - 1, na, nb, nk);
            }
        }
    return dp[bit][sa][sb][sk];
}

void solve(int test_number) {
    memset(dp, 255, sizeof(dp));
    cin >> a >> b >> k;
    a--, b--, k--;
    cout << "Case #" << test_number << ": " << solve(33, 1, 1, 1) << endl;
}

