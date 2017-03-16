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

LL gcd(LL n, LL m){
    if (n < m) return gcd(m, n);
    while (m){
        n = n % m;
        LL t = m; m = n; n = t;
    }
    return n;
}

int tr(LL a, LL b){
    if (a >= b) return 0;
    if (a * 2 >= b) return 1;
    return tr(a, b/2) + 1;
}

void solve(){
    LL p, q;
    string x;
    cin>>x;
    p = 0; q = 0;
    int take2 = 0;
    FOR(i, 0, x.length()){
        if (x[i] == '/') take2 = 1;
        else if (take2 == 0) p = (p * (LL)10 + (LL)(x[i] - '0'));
        else q = (q * (LL)10 + (LL)(x[i] - '0'));
    }
    LL temp = gcd(p, q);
    p /= temp; q /= temp;
    LL r = q;
    while (r > 1){
        if (r % 2 == 1){printf("impossible\n"); return;}
        r /= 2;
    }
    printf("%d\n", tr(p, q));
}


int main(){
    freopen("A-large.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    scanf("%d", &t);
    FOE(i, 1, t){
        printf("Case #%d: " , i);
        solve();
    }
    return 0;
}
