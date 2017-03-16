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


LL a, b, k;
LL powww[33];
LL ser[31][3];
LL a1, b1, k1;
LL big;

LL test(LL num, LL cura, LL curb, bool cut1, bool cut2){
    LL cur = cura & curb;
    if (cur > k1) return 0;
    if (num == 0) return 1;
    if (powww[num+1] + cur <= k1){
        LL cnt1, cnt2;
        if (cut1) cnt1 = powww[num+1] - 1;
        else {
            cnt1 = 0;
            FOD(i, num, 1) cnt1 = (cnt1 * 2) + ser[i][0];
        }
        if (cut2) cnt2 = powww[num+1] - 1;
        else {
            cnt2 = 0;
            FOD(i, num, 1) cnt2 = (cnt2 * 2) + ser[i][1];
        }
        return (cnt1+1) * (1+cnt2);
    }
    LL res = 0;
    if ((cut1) || (ser[num][0] == 1)) res += test(num-1, cura+powww[num], curb, cut1, (cut2 || ser[num][1]));
    if ((cut2) || (ser[num][1] == 1)) res += test(num-1, cura, curb+powww[num], (cut1 || ser[num][0]), cut2);
    if (((cut1) || (ser[num][0] == 1)) &&
            ((cut2) || (ser[num][1] == 1))) res += test(num-1, cura+powww[num], curb+powww[num], cut1, cut2);
    res += test(num-1, cura, curb, (cut1 || ser[num][0]), (cut2 || ser[num][1]));
    return res;
}

void solve(){
    scanf("%I64d%I64d%I64d", &a, &b, &k);
    a--; b--; k--;
    a1 = a; b1 = b; k1 = k;
    LL res = 0;
    powww[1] = 1;
    FOE(i, 2, 30) powww[i] = powww[i-1] * 2;
    FOE(i, 1, 30) ser[i][1] = ser[i][0] = ser[i][2] = 0;
    int h;
    h = 1;
    while (a){
        ser[h][0] = a % 2;
        a /= 2;
        h++;
    }
    h = 1;
    while (b){
        ser[h][1] = b % 2;
        b /= 2;
        h++;
    }
    h = 1;
    while (k){
        ser[h][2] = k % 2;
        k /= 2;
        h++;
    }
    res = test(29, 0, 0, false, false);
    printf("%I64d\n", res);
}

int main(){
    freopen("B-small-attempt0 (1).in", "r", stdin);
    freopen("out.out", "w", stdout);
    int x;
    scanf("%d", &x);
    FOE(i, 1, x) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
