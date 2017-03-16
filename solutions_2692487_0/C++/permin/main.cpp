//
//  main.cpp
//  GCJ-2
//
//  Created by Rodion Permin on 5/4/13.
//  Copyright (c) 2013 Rodion Permin. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
#include <numeric>
#include <iterator>
#include <sstream>
#include <string>
#include <numeric>
#include <functional>
#include <limits>

using namespace std;

#define all(v)  (v).begin(), (v).end()
#define debug(x) cerr << #x << ": " << x << endl;

template <class T>
ostream& operator << (ostream& o, const vector<T>& v) {
    o << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i)
            o << ", ";
        o << v[i];
    }
    o << "]";
    return o;
}

template <class F, class S>
ostream& operator << (ostream& o, const pair<F, S> & p) {
    o << "(" << p.first << ", " << p.second << ")";
    return o;
}

void solve() {
    int a, n;
    cin >> a >> n;
    vector<int> x(n);
    for (int& y: x) {
        cin >> y;
    }
    sort(all(x));
    int inf = x.back() + 1;
    a = min(a, inf);
    vector<vector<int> > dp(inf + 1, vector<int> (n + 1, x.size() + 1));
    for (int i = 0; i <= inf; ++i)
        dp[i][n] = 0;
    for (int pos = n - 1; pos >= 0; --pos) {
        for (int c = 0; c <= inf; ++c) {
            dp[c][pos] = dp[c][pos + 1] + 1;
            if (c <= 1)
                continue;
            int add = 0;
            int nc = c;
            while(nc <= x[pos]) {
                nc += nc - 1;
                ++add;
            }
            nc += x[pos];
            nc = min(nc, inf);
            dp[c][pos] = min(dp[c][pos], add + dp[nc][pos + 1]);
        }
    }
    //debug(dp);
    cout << dp[a][0];
}

int main(int argc, const char * argv[])
{

    //freopen("/Users/permin/Documents/Olymp/GCJ-2/GCJ-2/input.txt", "r", stdin);
    freopen("/Users/permin/Downloads/A-small-attempt0-2.in.txt", "r", stdin);
    freopen("/Users/permin/Documents/Olymp/GCJ-2/GCJ-2/out.txt", "w", stdout);
    // insert code here...
    int tests = 0;
    cin >> tests;
    debug(tests);
    for (int test = 0; test < tests; ++test) {
        cout << "Case #" << test + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}

