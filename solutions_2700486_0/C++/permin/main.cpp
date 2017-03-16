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
#define debug(x) //cerr << #x << ": " << x << endl;

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

void solve1() {
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

double solve2() {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    if ((x+y)&1) {
        return 0.0;
    }
    int a = 0;
    int add = 1;
    int s = 0;
    while (a + add <= n) {
        a += add;
        add += 4;
        ++s;
    }
    debug(s);
    debug(add);
    int l = (abs(x)+y)/2;
    debug(l);
    if (l < s) {
        return 1.0;
    }
    if (l > s) {
        return 0.0;
    }
    int rem = n - a;
    int pos = (-abs(x)+2*l);
    assert(4*l+1==add);
    debug(rem);
    debug(pos);
    assert(rem <= add);
    if (rem == add) {
        return 1.0;
    }
    if (pos == add/2) {
        return rem == add;
    }
    vector<double> prob(add/2 + 1, 0.0);
    prob[0] = 1.0;
    for (int i = 0; i < rem; ++i) {
        vector<double> np(prob.size());
        for (int left = 0; left <= add/2 && left <= rem; ++left) {
            int right = i - left;
            if (right > add/2)
                continue;
            if (left < add/2 && right < add/2) {
                np[left] += 0.5 * prob[left];
                np[left+1] += 0.5 * prob[left];
            } else if (left == add/2) {
                np[left] += prob[left];
            } else  if (right == add/2) {
                np[left + 1] += prob[left];
            }
        }
        swap(prob, np);
    }
    debug(prob);
    {
        double sum = accumulate(all(prob), 0.0);
        assert(fabs(sum-1.0)<1e-8);
    }
    double res = 0.0;
    for (int i = pos+1; i <= add/2 && i <= rem; ++i) {
        res += prob[i];
    }
    return res;
    //debug("solve");
    /*double p = 0.0;
    double cur = 1.0;
    for (int i = 0; i < rem; ++i) {
        cur *= 0.5;
    }
    for (int left = 0; left <= add / 2 && left <= rem; ++left) {
        if (rem - left <= rem && rem - left <= add / 2 && left > pos) {
            debug(left);
            p += cur;
        }
        debug(cur);
        cur /= left + 1;
        cur *= (rem - left);
    }
    
    return p;*/
}

int main(int argc, const char * argv[])
{

    //freopen("/Users/permin/Documents/Olymp/GCJ-2/GCJ-2/input.txt", "r", stdin);
    freopen("/Users/permin/Downloads/B-small-attempt1.in.txt", "r", stdin);
    freopen("/Users/permin/Documents/Olymp/GCJ-2/GCJ-2/out.txt", "w", stdout);
    // insert code here...
    int tests = 0;
    cin >> tests;
    debug(tests);
    for (int test = 0; test < tests; ++test) {
        //debug(test);
        cout << "Case #" << test + 1 << ": ";
        printf("%0.18lf\n",solve2());
    }
    return 0;
}

