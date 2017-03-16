/*
 * Author:  xioumu
 * Created Time:  2013/5/12 17:44:21
 * File Name: b.cpp
 * solve: b.cpp
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

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int ex, ey;

void move(char inc, char dec, int dis) {
    if (dis == 0) return;
    else if (dis > 0) {
        rep (i, dis) {
            printf("%c%c", dec, inc);
        }
    }
    else {
        rep (i, -dis)
            printf("%c%c", inc, dec);
    }
}

int main() {
    int T, ca = 1;
    freopen("b.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &ex, &ey);
        //out(ex);
        //out(ey);
        printf("Case #%d: ", ca++);
        move('E', 'W', ex);
        move('N', 'S', ey);
        printf("\n");
    }
    return 0;
}
