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


map<string, int> st1, st2;
vii a;
int n;

void solve() {
    st1.clear(); st2.clear();
    cin >> n;
    string u, v;
    a.clear();
    rep(i, 0, n) {
        cin >> u >> v;
        if (!st1.count(u)) st1[u] = st1.size();
        if (!st2.count(v)) st2[v] = st2.size();
        a.push_back(mk(st1[u], st2[v]));
    }
    int ans = 0;
    int c0 = (1 << st1.size()) - 1, c1 = (1 << st2.size()) - 1;
    rep(mask, 0, 1 << n) {
        int has0 = 0, has1 = 0;
        int cnt = n - __builtin_popcount(mask);
        rep(i, 0, n) {
            if (mask & (1 << i)) {
                has0 |= 1 << a[i].first;
                has1 |= 1 << a[i].second;
            }
        }
        //cout << mask << " " << has0 << " " << has1 << "\n";
        if (has0 == c0 && has1 == c1) {
            ans = max(ans, cnt);
        }
    }
    cout << ans << "\n";
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