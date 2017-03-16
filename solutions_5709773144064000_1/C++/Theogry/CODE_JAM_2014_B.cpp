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
#define eps 1e-12
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


void solve(int tc){
    double c, f, x;
    scanf("%lf%lf%lf", &c, &f, &x);
    double start = 0.00, rate = 2.00;
    while (true){
        double nxt = x / rate;
        double nxtaddfarm = (c) / rate + x / (rate + f);
        if (nxt < nxtaddfarm){
            printf("Case #%d: ", tc);
            double y = start + nxt + eps;
            printf("%.9f\n", y);
            return;
        }
        start += c / rate;
        rate += f;
    }
}

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("sol_B.out", "w", stdout);
    int t; scanf("%d", &t);
    FOE(i, 1, t) solve(i);
    return 0;
}
