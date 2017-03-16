//
//  code.cpp
//  :))
//
//  Created by user on 3/8/16.
//  Copyright © 2016 user. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <complex>
#include <cstring>
#include <stack>
#include <deque>
#include <unordered_map>

using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define sz(a) (a).size()
#define all(a) (a).begin(), (a).end()
#define Rep(i,n) for(int i = 0; i < (n); ++i)

typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef unsigned int uint;

const int N = 2e5 + 7;
const int M = 600;
const ll base = 1e18;
const int mod = 999983;
const int inf = 1e9 + 7;
const double pi = acos(-1);
const int maxn = N * 2;
const double PI = acos(-1);
const double ep = 1e-9;


string u, v;

int a[2][1001];

string cur;

int toInt(string s) {
    int now = 0;
    rep(i, 0, s.size()) {
        now = now * 10 + (s[i] - '0');
    }
    return now;
}

void go(int pos, int type) {
    if (pos == cur.size()) {
        //cout << cur << " " << type << "\n";
        a[type][toInt(cur)] = 1;
        return;
    }
    if (cur[pos] != '?') go(pos + 1, type);
    else {
        rep(j, 0, 10) {
            cur[pos] = char(j + '0');
            go(pos + 1, type);
            cur[pos] = '?';
        }
    }
}

void solve() {
    int diff = inf;
    cin >> u >> v;
    rep(i, 0, 1001) {
        a[0][i] = a[1][i] = 0;
    }
    cur = u;
    go(0, 0);
    cur = v;
    go(0, 1);
    int ax = 0, ay = 0;
    rep(u, 0, 1001) {
        rep(v, 0, 1001) {
            if (a[0][u] && a[1][v]) {
                //cout << u << " " << v << " " << abs(u - v) << "\n";
                if (abs(u - v) < diff) {
                    diff = abs(u - v);
                    ax = u;
                    ay = v;
                } else {
                    if (abs(u - v) == diff) {
                        if (u < ax || (u == ax && v < ay)) {
                            ax = u;
                            ay = v;
                        }
                    }
                }
            }
        }
    }
    int n = u.length();
    u = ""; v = "";
    //cout << ax << " " << ay << "\n";
    rep(i, 0, n) {
        u = char((ax % 10) + '0') + u;
        ax /= 10;
    }
    rep(i, 0, n) {
        v = char((ay % 10) + '0') + v;
        ay /= 10;
    }
    //cout << diff << "\n";
    cout << u << " " << v << "\n";
    
}




int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    rep(i, 1, T + 1) {
        printf("Case #%d: ", i);
        solve();
        //puts("");
        //KMP();
    }
}