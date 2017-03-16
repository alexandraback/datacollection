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

int n, m;
int exist[51][51];
int code[51];
int way[51], h;
int v[51];

void DFS(int u, int p){
    v[u] = 1;
    way[++h] = code[u];
    int good = -1;
    FOE(i, 1, n){
        good = -1;
        FOE(j, 1, n){
            if ((exist[u][j]) && (!v[j])){
                if (good == -1) good = j;
                else if (code[good] > code[j]) good = j;
            }
        }
        if (good == -1) return;
        DFS(good, u);
    }
}

void solve(){
    scanf("%d%d", &n, &m);
    h = 0;
    FOE(i, 1, n) v[i] = 0;
    FOE(i, 1, n) FOE(j, 1, n) exist[i][j] = 0;
    FOE(i, 1, n) scanf("%d", &code[i]);
    FOE(i, 1, m){
        int a, b;
        scanf("%d%d", &a, &b);
        exist[a][b] = exist[b][a] = 1;
    }
    int small = 1;
    FOE(i, 2, n) if (code[i] < code[small]) small = i;
    DFS(small, -1);
    FOE(i, 1, h) printf("%d", way[i]);
    printf("\n");
}
int main(){
   freopen("C-small-attempt0 (1).in", "r", stdin);
    freopen("out.out", "w", stdout);
    int x;
    scanf("%d", &x);
    FOE(i, 1, x) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
