#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s); i>=(e); i--)
#define LL long long
#define eps 1e-9
#define pi acos(-1.0)
#define fail {printf("NO\n"); return;}
LL max(LL a,LL b){if (a>b){return a;} else {return b;}}
LL min(LL a,LL b){if (a<b){return a;} else {return b;}}

struct P{
    double x, y;
    P(){}
    P(int x, int y):x(double(x)), y(double(y)){}
    P(double x, double y):x(x) , y(y){}
    P operator+ (const P &a) const {return P(x+a.x, y+a.y);}
    P operator- (const P &a) const {return P(x-a.x, y-a.y);}
    double operator^ (const P &a) const {return x*a.x+y*a.y;}
    void in(){scanf("%lf%lf", &x, &y);}
    void out(){printf("REQUIRED %.7f %.7f\n", x, y);}
    double dist(P a, P b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
    double sqdist(P a, P b) {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

};

#define M 600000
#define N 200001

LL l;
int n, a[N],
// 1 i j k -1 -i -j -k
table[9][9] = {{0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4}
    };

string x;

char b[9] = {' ', 'i', 'j', 'k'};

int checked[9];

void solve(){
    scanf("%d%lld", &n, &l);
    cin>>x;
    int cur = 0;
    FOR(i, 0, n){
        FOE(j, 1, 3) if (x[i] == b[j]) a[i] = j;
    }
    FOR(i, 0, n){
        cur = table[cur][a[i]];
    }
    if (cur == 0) fail
    if (cur != 4){
        if (l % 4 != 2) fail
    }
    if (cur == 4 && l % 2 != 1) fail

    LL curlen = 1;
    FOE(i, 0, 7) checked[i] = 0;
    int now = 0;
    cur = 0;
    int req = 1;
    while (true){
        if (now == 0 && checked[cur]) fail
        else if (now == 0) checked[cur] = 1;
        cur = table[cur][a[now]];
        if (cur == req){
            FOE(i, 0, 7) checked[i] = 0;
            if (req == 1) {req++; cur = 0;}
            else {
                if (curlen > l) fail
                else {
                    puts("YES");
                    return;
                }
            }
        }
        now = (now + 1) % n;
        if (now == 0) curlen++;
    }
}

int main(){
    FOE(i, 4, 7) FOE(j, 0, 3) table[i][j] = (table[i - 4][j] + 4) % 8;
    FOE(i, 0, 7) FOE(j, 4, 7) table[i][j] = (table[i][j - 4] + 4) % 8;
  /*  FOE(i, 0, 7){
        FOE(j, 0, 7) printf("%d  ", table[i][j]);
        puts("");
    }*/
    freopen("C-large.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int t;
    scanf("%d", &t);
    FOE(i, 1, t){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
