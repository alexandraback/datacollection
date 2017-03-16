/*
 * Author:  xioumu
 * Created Time:  2015/5/3 2:08:32
 * File Name: C.cpp
 * solve: C.cpp
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
const int maxn = 10 + 10;

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int d[maxn], h[maxn], m[maxn];
double v[maxn];
int n;

int getAns() {
    if (n == 1) return 0; 
    if (m[1] < m[2]) {
        swap(d[1], d[2]);
        swap(m[1], m[2]);
    }
    if (m[1] == m[2]) return 0;
    v[1] = 360.0 / m[1];
    v[2] = 360.0 / m[2];
    int len = d[1] - d[2];
    if (len < 0) len += 360;
    double t = len / (v[2] - v[1]);
    if (sgn(m[2] - t) >= 0) return 1;
    return 0;
}

int main() {
    int T, ca = 1;
    freopen("C.out", "w", stdout);
    scanf("%d", &T); 
    while (T--) {
        scanf("%d", &n);
        repf (i, 1, n)
            scanf("%d%d%d", &d[i], &h[i], &m[i]);
        int ans = getAns();
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}
