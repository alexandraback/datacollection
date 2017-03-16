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

#define MOD 1000000007

#define NAME "a"
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
    freopen(NAME ".in", "r", stdin);
    freopen(NAME ".out", "w", stdout);
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

li a[1000100];
li n;
li cur;

void solve(int test_number) {
    li i;
    cin >> cur >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    if (cur == 1){
        cout << "Case #" << test_number << ": " << n << endl;
        return;
    }
    sort(a, a + n);
    li res = INF;
    li cur_res = 0;
    for (i = 0; i < n; i++){
        //cerr << cur << ' ' << cur_res << endl;
        //cerr << res << endl;
        res = min(res, cur_res + n - i);
        while (cur <= a[i]){
            cur_res++;
            cur += cur - 1LL;
        }
        cur += a[i];
    }
    //print(cur_res, "cur_res");
    res = min(res, cur_res);
    cout << "Case #" << test_number << ": " << res << endl;
}

