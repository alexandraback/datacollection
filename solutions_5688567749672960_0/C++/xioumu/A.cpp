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
const int maxn = 1000000 + 10;

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int a[maxn];

int reverseNum(int w) {
    int res = 0;
    while (w != 0) {
        res = res * 10 + w % 10;
        w /= 10;
    }
    return res;
}

void updata(int &x, int y) {
    if (x == -1) x = y;
    else x = min(x, y);
}

void init() {
    clrs(a, -1);
    a[0] = 0;
    a[1] = 1;
    repf (i, 1, maxn - 5) {
        int j = reverseNum(i);
        updata(a[i + 1], a[i] + 1);
        if (j < maxn)
            updata(a[j], a[i] + 1);
    }
}

int main() {
    freopen("A.out", "w", stdout);
    int T, ca = 1, n;
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", ca++, a[n]);
    }
    return 0;
}
