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

#define NAME "b_small3"
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

double solve(int test_number);

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
        cout << "Case #" << i + 1 << ": " << solve(i + 1) << endl;
}

int good, full;
int x, y;
int n;
set<pair<int, int> > q;

void rec(int p){
    //cerr << p << endl;
    if (p == n){
        full++;
        if (q.find(mp(x, y)) != q.end())
            good++;
        return;
    }
    int x, y;
    x = 0, y = 100;
    while (q.find(mp(x, y)) == q.end()){
        //cerr << y << endl;
        y -= 2;
        if (y == -2)
            break;
    }
    y += 2;
    //cerr << x << ' ' << y << endl;

    if (q.find(mp(x - 1, y - 1)) == q.end()){
        int x1 = x, y1 = y;
        while (q.find(mp(x1, y1)) == q.end()){
            x1--, y1--;
            if (y1 == -1)
                break;
        }
        x1++, y1++;
        //cerr << x1 << ' ' << y1 << endl;
        q.insert(mp(x1, y1));
        rec(p + 1);
        q.erase(mp(x1, y1));
    }
    if (q.find(mp(x + 1, y - 1)) == q.end()){
        int x1 = x, y1 = y;
        while (q.find(mp(x1, y1)) == q.end()){
            x1++, y1--;
            if (y1 == -1)
                break;
        }
        x1--, y1++;
        q.insert(mp(x1, y1));
        //cerr << x1 << ' ' << y1 << endl;
        rec(p + 1);
        q.erase(mp(x1, y1));
    }
    if (q.find(mp(x + 1, y - 1)) != q.end() &&
            q.find(mp(x - 1, y - 1)) != q.end()){
        q.insert(mp(x, y));
        rec(p + 1);
        q.erase(mp(x, y));
    }

}

double solve(int test_number) {
    cin >> n;
    cin >> x >> y;
    good = full = 0;
    q.clear();
    rec(0);
    cerr << good << ' ' << full << endl;
    return (double)good / (double)full;
}

