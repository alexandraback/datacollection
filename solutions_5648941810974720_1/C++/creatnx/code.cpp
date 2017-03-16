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

string s;
int sl[26];
int kq[10];

string x[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void rm(int c) {
    
    rep(i, 0, x[c].size()) sl[x[c][i] - 'A']--;
}

bool has(int c) {
    rep(i, 0, x[c].size()) if (sl[x[c][i] - 'A'] <= 0) return false;
    return true;
}

void solve() {
    cin >> s;
    rep(i, 0, 26) sl[i] = 0;
    //cout << s << "\n";
    rep(i, 0, s.size()) {
        sl[s[i] - 'A']++;
    }
    rep(i, 0, 10) kq[i] = 0;
    while (has(0)) {
        kq[0]++;
        rm(0);
    }
    while (has(2)) {
        kq[2]++;
        rm(2);
    }
    
    while (has(6)) {
        kq[6]++;
        rm(6);
    }
    
    while (has(7)) {
        kq[7]++;
        rm(7);
    }
    
    while (has(5)) {
        kq[5]++;
        rm(5);
    }
    
    while (has(4)) {
        kq[4]++;
        rm(4);
    }
    
    while (has(8)) {
        kq[8]++;
        rm(8);
    }
    
    while (has(3)) {
        kq[3]++;
        rm(3);
    }
    
    while (has(1)) {
        kq[1]++;
        rm(1);
    }
    
    while (has(9)) {
        kq[9]++;
        rm(9);
    }
    
    rep(i, 0, 10) {
        while (kq[i]-- > 0) {
            printf("%d", i);
        }
    }
    puts("");
    
}




int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
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