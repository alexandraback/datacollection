/*
 * Author:  xioumu
 * Created Time:  2014/5/4 0:39:33
 * File Name: B.cpp
 * solve: B.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
#define out(x) printf(#x" %d\n", x)
#define sqr(x) ((x) * (x))
typedef long long lint;

const int maxint = -1u>>1;
const double eps = 1e-8;
const int maxLen = 30;

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

lint ans = 0;
int a, b, c;
lint f[35][3][3][3];

lint two(int w) {
    return 1LL << w;
}

int getDit(int x, int w) {
    if (x & two(w)) return 1;
    else return 0;
}

lint fun(int w, int ha, int hb, int hc) {
    //printf("%d %d %d %d===\n", w, ha, hb, hc);
    if (w == -1) {
        return 1;
    }
    if (f[w][ha][hb][hc] != -1) return f[w][ha][hb][hc];
    lint aa, bb, &res = f[w][ha][hb][hc];
    res = 0;
    int da = getDit(a, w), db = getDit(b, w), dc = getDit(c, w);
    if (hc == 0) {
        aa = bb = two(w + 1) - 1;
        if (ha) aa &= a;
        if (hb) bb &= b;
        res = (lint)(aa + 1) * (bb + 1);
        //printf("down : %d %d %d %d %lld\n", w, ha, hb, hc, f[w][ha][hb][hc]);
        return res;
    }
    else {
        int na = 0, nb = 0; 
        if (ha && !da) na = 1;
        if (hb && !db) nb = 1;
        if (getDit(c, w) == 1) {
            res += fun(w - 1, na, nb, 0);
            if (!ha || da) res += fun(w - 1, ha, nb, 0);
            if (!hb || db) res += fun(w - 1, na, hb, 0);
            if ((!ha || da) && (!hb || db))
                res += fun(w - 1, ha, hb, 1);
            //printf("%d %d %d %lld\n", w - 1, ha, nb, f[w - 1][ha][nb][0]);
        }
        else {
            res += fun(w - 1, na, nb, 1);
            if (!ha || da) res += fun(w - 1, ha, nb, 1);
            if (!hb || db) res += fun(w - 1, na, hb, 1);
        }
        //printf("%d %d %d %d %lld\n", w, ha, hb, hc, res);
        return res;
    }
}

int main() {
    int T, ca = 1;
    freopen("B.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);    
        a--, b--, c--;
        clrs(f, -1);
        ans = fun(maxLen, 1, 1, 1);
        printf("Case #%d: %lld\n", ca++, ans);
    }
    return 0;
}
