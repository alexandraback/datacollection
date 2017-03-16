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

double a[2001], b[2001];
int aa[2001], bb[2001];

void solve(int tc){
    int n;
    scanf("%d", &n);
    FOE(i, 1, n) scanf("%lf", &a[i]);
    FOE(i, 1, n) scanf("%lf", &b[i]);
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    int ta = 1, tb = 1;
    FOE(i, 1, 2*n){
        if ((ta > n) || ((tb <= n) && (a[ta] > b[tb]))){
            bb[tb] = i;
            tb++;
        } else {
            aa[ta] = i;
            ta++;
        }
    }
    int oo = 0;
    tb = 1;
    FOE(i, 1, n){
        while ((bb[tb] < aa[i]) && (tb <= n)) tb++;
        if (tb > n) oo++;
        tb++;
    }
    int rr = 0;
    ta = 1;
    FOE(i, 1, n){
        while ((bb[i] > aa[ta]) && (ta <= n)) ta++;
        if (ta <= n) rr++;
        ta++;
    }
    printf("Case #%d: %d %d\n", tc, rr, oo);

}


int main(){
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("sol.out", "w", stdout);
    int t; scanf("%d", &t);
    FOE(i, 1, t) solve(i);
    return 0;
}
