/**
 * Copyright (c) 2014 Authors. All rights reserved.
 * 
 * FileName: D.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2014-04-12
 */
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOR(i,s,t) for (LL i = (s); i <= (t); ++i)
#define FOREACH(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;
typedef complex<double> Point;
typedef complex<double> Vector;
#define X real()
#define Y imag()

const double pi = acos(-1);
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 1000 + 5;

int n;
double a[maxn], b[maxn];

int f()
{
        int res = 0, p = 0;
        REP(i,n) {
                if (p < n && b[p] < a[i]) {
                        ++res;
                        ++p;
                }
        }
        return res;
}

int g()
{
        int res = n, p = 0;
        REP(i,n) {
                while (p < n && b[p] < a[i]) ++p;
                if (p != n) {
                        --res;
                        ++p;
                }
        }
        return res;
}

int main()
{
        int T, cas = 0;
        cin >> T;

        while (T--) {
                cin >> n;
                REP(i,n) cin >> a[i];
                REP(i,n) cin >> b[i];
                sort(a, a + n);
                sort(b, b + n);
                cout << "Case #" << ++cas << ": ";
                cout << f() << " " << g() << endl;
        }

        return 0;
}
