/*
 * Author:  xioumu
 * Created Time:  2015/5/3 0:18:03
 * File Name: A.cpp
 * solve: A.cpp
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
const lint maxn = 100000000000000LL + 10;

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

map<lint, lint> mp;

lint reverseNum(lint w) {
    lint res = 0;
    while (w != 0) {
        res = res * 10 + w % 10;
        w /= 10;
    }
    return res;
}

lint mypow(int x, int y) {
    lint res = 1;
    rep (i, y)
        res *= x;
    return res;
}

lint getAns(lint val) {
    map<lint, lint>::iterator it = mp.upper_bound(val); 
    it--;
    lint res = it->second + (val - it->first);
    //printf("it: %lld %lld\n", it->first, it->second);
    return res;
}

void init() {
    mp[1] = 1;
    repf (i, 2, 14) {
        lint m = i / 2; 
        lint lim = mypow(10, m) - 1;
        lint base = mypow(10, i - 1);
        repf (j, 2, lim) {
            lint val = base + j; 
            map<lint, lint>::iterator it = mp.upper_bound(val); 
            it--;
            lint res = it->second + (val - it->first) + 1;
            lint rval = reverseNum(val);
            lint hres = getAns(rval);
            mp[rval] = min(res, hres);
            //if (val < 100000) {
                //printf("it: %lld %lld\n", it->first, it->second);
                //printf("%lld %lld %lld\n", val, rval, res);
            //}
        }
    } 
}


int main() {
    int T, ca = 1;
    lint n;
    freopen("A.in", "r", stdin);
    freopen("AA.out", "w", stdout);
    init();
    scanf("%d", &T);
    //repf (i, 1, 10000) {
        //if (a[i] != a[i - 1] + 1)
        //printf("%2d:%2d:%2d\n", reverseNum(i), i, a[i]);
    //}
    //return 0;
    while (T--) {
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", ca++, getAns(n));
    }
    return 0;
}
