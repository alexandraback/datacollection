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

#ifdef _GEANY
    #include "/home/pershik/debug_lib/debug.h"
#endif

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define INF (1000000000)
#define LINF (1000000000000000000ll)
#define EPS (1e-9)
#define MOD 1000000007LL

#define NAME "b"
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
    return binpow(n, MOD - 2);
}

void solve(int test_number);

int main() {
    freopen(NAME ".in", "r", stdin);
//#ifndef _GEANY
    freopen(NAME ".out", "w", stdout);
//#endif
    cout.setf(ios::fixed);
    cout.precision(20);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve(i + 1);
}

int a[110][110];
int n, m;

void solve(int test_number) {
    cout << "Case #" << test_number << ": ";
    cin >> n >> m;
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++){
            bool flag1 = true;
            for (k = 0; k < n; k++)
                if (a[k][j] > a[i][j])
                    flag1 = false;
            bool flag2 = true;
            for (k = 0; k < m; k++)
                if (a[i][k] > a[i][j])
                    flag2 = false;
            if (!flag1 && !flag2){
                cout << "NO" << endl;
                return;
            }
        }
    cout << "YES" << endl;
}

