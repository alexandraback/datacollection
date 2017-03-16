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
#define mod 1000000007

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

string u[1001];
int n;
int cnt = 0;
LL fac[101];

int center[27], full[27], st[27], en[27], nxt[27], pre[27];
int piece = 0;
LL resp[1001];
int handle[27];


void solve(){
    FOE(i, 1, 26) center[i] = st[i] = en[i] = full[i] = pre[i] = nxt[i] = handle[i] = 0;
    scanf("%d", &n);
    piece = 0;
    FOE(i, 1, n) {
        cin>>u[i];
        int ok = 1;
        string xx = u[i];
        FOE(i, 2, xx.length()){
            if (xx[i-1] != xx[0]) ok = 0;
        }
        if (ok) full[(int)(xx[0]-'a'+1)]++;
        else {
            int v = 0, z = xx.length() - 1;
            while (xx[v] == xx[0]) v++;
            while (xx[z] == xx[xx.length() - 1]) z--;
            st[(int)(xx[0]-'a'+1)]++;
            en[(int)(xx[xx.length() - 1]-'a'+1)]++;
            int w = v;
            char q = ' ';
            FOE(i, v, z){
                if (xx[i] != q){
                    q = xx[i];
                    center[(int)(q - 'a' + 1)]++;
                }
            }
            nxt[(int)(xx[0]-'a'+1)] = (int)(xx[xx.length() - 1]-'a'+1);
            pre[(int)(xx[xx.length()-1]-'a'+1)] = (int)(xx[0]-'a'+1);
        }
    }
    FOE(i, 1, 26) if ((center[i] > 1) || ((center[i] > 0) && (full[i] + st[i] + en[i] != 0))){
        puts("0");
        return;
    }
    FOE(i, 1, 26) if ((st[i] > 1) || (en[i] > 1)){
        puts("0");
        return;
    }
    FOE(i, 1, 26) if ((en[i] == 0) && (st[i] == 1)){
        piece++;
        resp[piece] = 1;
        handle[i] = 1;
        int y = i;
        while (y != 0){
            resp[piece] = (resp[piece] * fac[full[y]]) % mod;
            handle[y] = 1;
            y = nxt[y];
        }
    }
    FOE(i, 1, 26) if ((handle[i] == 0) && (st[i] == 0) && (en[i] == 1)){
        piece++;
        resp[piece] = 1;
        handle[i] = 1;
        int y = i;
        while (y != 0){
            resp[piece] = (resp[piece] * fac[full[y]]) % mod;
            handle[y] = 1;
            y = pre[y];
        }
    }
    FOE(i, 1, 26) if ((st[i] > 0) || (en[i] > 0)){if (!handle[i]){puts("0"); return;}}
    FOE(i, 1, 26) if ((full[i] > 0) && (handle[i] == 0)){resp[++piece] = fac[full[i]];}
    LL res = 1;
    FOE(i, 1, piece) {res = (res * resp[i]) % mod;}
    res = res * (fac[piece]) % mod;
    printf("%I64d\n", res);
}



int main(){
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("output.out", "w", stdout);
    fac[0] = 1;
    FOE(i, 1, 100) fac[i] = (fac[i-1] * i) % mod;
    int t;
    scanf("%d", &t);
    FOE(i, 1, t){
        printf("Case #%d: " , i);
        solve();
    }
    return 0;
}
