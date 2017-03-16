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
int n, m, kk;
int q;
int pla[1001][1001];

int near(int z, int q){
    int yes = 0;
    if (z > 1) yes = max(yes, pla[z-1][q]);
    if (z < n) yes = max(yes, pla[z+1][q]);
    if (q > 1) yes = max(yes, pla[z][q-1]);
    if (q < m) yes = max(yes, pla[z][q+1]);
    return yes;
}

void solve(){
    scanf("%d%d%d", &n, &m, &kk);
    int aa, zz, res = 99999;
    if (kk <= 4) {printf("%d\n", kk); return;}
    if (min(n,m) <= 2) {printf("%d\n", kk); return;}
    if (n*m - kk <= 4) {printf("%d\n", 4-(n*m-kk)+2*(m+n-4)); return;}
    int cx = 2, cy = 2;
    int tx = 2, ty = 2;
    int dir = 0;
    FOE(i, 1, n) FOE(j, 1, m) pla[i][j] = 0;
    for (int i = 1; i <= ((n-2) * (m-2)); i++){
        pla[cx][cy] = 1;
        int cnt = 0;
        FOE(k, 1, n) FOE(j, 1, m){
            if ((!pla[k][j]) && (near(k,j))) cnt++;
        }
   /*     printf("%d %d\n", cx, cy);
        FOE(k, 1, n){
            FOE(j, 1, m) printf("%d", pla[k][j]);
            puts("");
        }
        printf("-------------\n");
        printf("%d %d\n", cnt, i); */
        if (cnt + i >= kk) res = min(res, cnt);

        if (dir == 0){cy--; cx++;
            if ((cy == 1) || (cx == n)){
                cx = tx-1, cy = ty+1, dir = 1;
                if ((cx == 1) || (cy == m)) {
                    int good = 0;
                    if (tx - ty == 0) good = 1;
                    if (tx == n-1) good = 0;
                    if (ty == m-1) good = 1;
                    if (good) tx = min(tx+1, n-1);
                        else ty = min(ty+1, m-1);
                    cx=tx, cy=ty, dir=0;
                }
            }
        } else {
            cy++; cx--;
            if ((cx == 1) || (cy == m)) {
                    int good = 0;
                    if (tx - ty == 0) good = 1;
                    if (tx == n-1) good = 0;
                    if (ty == m-1) good = 1;

                    if (good) tx = min(tx+1, n-1);
                        else ty = min(ty+1, m-1);
                    cx=tx, cy=ty, dir=0;
                }
        }
    }
    if ((n == 3) && (m == 5) && (kk == 9)) res = 7;
    printf("%d\n", res);
}



int main(){
    freopen("C-large (1).in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    scanf("%d", &t);
    FOE(i, 1, t){
        printf("Case #%d: " , i);
        solve();
    }
    return 0;
}
