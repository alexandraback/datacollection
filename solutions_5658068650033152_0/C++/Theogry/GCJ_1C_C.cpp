#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s); i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LL long long
#define eps 1e-6
#define pi acos(-1.0)

LL max(LL a,LL b){if (a>b){return a;} else {return b;}}
LL min(LL a,LL b){if (a<b){return a;} else {return b;}}

struct P{
    double x, y;
    P(){}
    P(double x, double y):x(x) , y(y){}
    P operator+ (const P &a) const {return P(x+a.x, y+a.y);}
    P operator- (const P &a) const {return P(x-a.x, y-a.y);}
    double operator^ (const P &a) const {return x*a.x+y*a.y;}
    void in(){scanf("%lf%lf", &x, &y);}
    void out(){printf("REQUIRED %.7f %.7f\n", x, y);}
    double dist(P a, P b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
    double sqdist(P a, P b) {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

};

int d;
int pla[21][21];
int v[21][21];
int dp[21][21];
int n, m, kk;
int q;

void visit(int cx, int cy){
    if (dp[cx][cy] == -1){
    dp[cx][cy] = 0;
    if (pla[cx][cy]){dp[cx][cy] = 1; return;}
    if ((cx < 1) || (cx > n) || (cy < 1) || (cy > m)){return;}
        visit(cx+1, cy);
        visit(cx, cy+1);
        visit(cx-1, cy);
        visit(cx, cy-1);
    }
}

void solve(){
    scanf("%d%d%d", &n, &m, &kk);
    d = 1;
    FOE(i, 1, n*m+1) d = d * 2;
    int res = 999999;
    FOE(i, 0, d-1){
        q = i;
        FOE(j, 1, n) FOE(k, 1, m) {dp[j][k] = -1;pla[j][k] = 0;}
        int z = i;
        int cx = 1, cy = 1;
        int cnt = 0;
        while (z){
            cnt += z%2;
            pla[cx][cy] = z % 2;
            z /= 2;
            cy++; if (cy == m+1){cy = 1; cx++;}
        }
        int enc = 0;
        FOE(j, 1, n) FOE(k, 1, m){
            if ((dp[j][k] == -1) && (!pla[j][k]) && ((j == 1) || (j == n) || (k == 1) || (k == m)))
                visit(j, k);
        }
        FOE(j, 1, n) FOE(k, 1, m) if (dp[j][k] != 0) enc ++;
        if ((enc >= kk) && (res > cnt)) {
                 res = min(res, cnt);
                 }
    }
    printf("%d\n", res);
}



int main(){
    freopen("C-small-attempt0 (1).in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    scanf("%d", &t);
    FOE(i, 1, t){
        printf("Case #%d: " , i);
        solve();
    }
    return 0;
}
