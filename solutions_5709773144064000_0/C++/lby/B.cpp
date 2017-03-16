/**
 * Copyright (c) 2014 Authors. All rights reserved.
 * 
 * FileName: B.cpp
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

int sgn(double x)
{
        return x < -eps? -1: x > eps;
}

int main()
{
        int T, cas = 0;
        cin >> T;

        while (T--) {
                double c, f, x, v = 2, res = 0;
                cin >> c >> f >> x;
                while (sgn(x / v - (c / v + x / (v + f))) > 0) {
                        res += c / v;
                        v += f;
                }
                res += x / v;
                cout << "Case #" << ++cas << ": ";
                cout << fixed << setprecision(7) << res << endl;
        }

        return 0;
}
