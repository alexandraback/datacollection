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

#define NAME "a_large"
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

int a[1000100];
char s[1001000];
li n;

inline bool is_vowel(char c){
    return (c == 'a' || c == 'u' || c == 'i' || c == 'o' || c == 'e');
}

void solve(int test_number) {
    scanf("%s %lld", s, &n);
    //puts(s);
    int len = strlen(s);
    li i;
    a[0] = 0;
    for (i = 0; i < len; i++)
        if (is_vowel(s[i]))
            a[i + 1] = a[i];
        else 
            a[i + 1] = a[i] + 1;
    li res = 0;
    li last = 0;
    //print_array(a + 1, len);
    for (i = 1; i <= len; i++)
        if (i >= n && a[i] == a[i - n] + n){
            li a, b;
            a = len - i + 1LL;
            b = ((i - n + 1LL) - (last + 1LL)) + 1LL;
            //cerr << i << ' ' << a << ' ' << b << endl;
            res += a * b;
            last = i - n + 1LL;
        }
    cout << "Case #" << test_number << ": " << res << endl;
}

