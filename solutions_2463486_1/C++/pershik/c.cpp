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

#define NAME "c"
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

li a[100] = { 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 
    1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 
    123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 
    12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 
    1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 
    1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 
    4004009004004 };

void solve(int test_number) {
    cout << "Case #" << test_number << ": ";
    li l, r;
    int n = 39;
    cin >> l >> r;
    int res = 0;
    for (int i = 0; i < n; i++){
        if (a[i] >= l && a[i] <= r)
            res++;
    }
    cout << res << endl;
}

