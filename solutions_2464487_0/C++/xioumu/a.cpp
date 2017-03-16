/*
 * Author:  xioumu
 * Created Time:  2013/4/27 9:13:41
 * File Name: a.cpp
 * solve: a.cpp
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
#define rep(i, n) for (lint i = 0; i < (n); ++i)
#define repf(i, a, b) for (lint i = (a); i <= (b); ++i)
#define repd(i, a, b) for (lint i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
#define out(x) printf(#x" %d\n", x)
#define sqr(x) ((x) * (x))
typedef long long lint;

const lint maxint = 1LL << 61;
const double eps = 1e-8;

lint sgn(const double &x) {  return (x > eps) - (x < -eps); }

lint n, m, r;

lint gao(lint x) {
    if ((double)(r + r + 2 * (x - 1)) - 1 > (double)maxint / x) return maxint;
    return (r + r + 2 * (x - 1)) * x - x;
}



int main() {
    freopen("a.out", "w", stdout);
    lint T, ca = 1;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld", &r, &m);
        r++;
        lint x = 1, y = m, ans = 0;
        while (x <= y) {
            lint mid = (x + y) / 2;
            if (gao(mid) <= m) {
                ans = mid;
                x = mid + 1;
            }
            else y = mid - 1;
        }
        printf("Case #%lld: ", ca++);
        printf("%lld\n", ans);
    }
    return 0;
}
