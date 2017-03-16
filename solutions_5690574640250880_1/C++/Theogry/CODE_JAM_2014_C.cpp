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

    int ma[91][91];
void solve(int tc){
    int r, c, m;
    scanf("%d%d%d", &r, &c, &m);
    printf("Case #%d:\n", tc);
    if (r == 1){
        printf("c");
        FOE(i, 2, c-m) printf(".");
        FOE(i, c-m+1, c) printf("*");
        printf("\n");
        return;
    }
    if (c == 1){
        printf("c\n");
        FOE(i, 2, r-m) printf(".\n");
        FOE(i, r-m+1, r) printf("*\n");
        return;
    }
    if (m == r*c-1){
        printf("c");
        FOE(i, 1, r) {
            FOE(j, 1, c) {
                if ((i != 1) || (j != 1)) printf("*");
                }
            printf("\n");
        }
        return;
    }
    if (c == 2){
        if ((m % 2 == 0) && (r*c-m > 2)){
            FOE(i, 1, r){
                FOE(j, 1, c){
                    if ((i == r) && (j == c)) printf("c");
                    else if (i <= m/2) printf("*");
                    else printf(".");
                }
                printf("\n");
            }
        } else printf("Impossible\n");
        return;
    }
    if (r == 2){
        if ((m % 2 == 0) && (r*c-m > 2)){
            FOE(i, 1, r){
                FOE(j, 1, c){
                    if ((i == r) && (j == c)) printf("c");
                    else if (j <= m/2) printf("*");
                    else printf(".");
                }
                printf("\n");
            }
        } else printf("Impossible\n");
        return;
    }
    int u, v;
    FOE(i, 1, r) FOE(j, 1, c) ma[i][j] = 1;
    if (m == r*c-2){
        printf("Impossible\n");
        return;
    }
    if ((r*c-m) % 2 == 0){
        m = r*c-m;
        FOE(j, 1, c) FOE(i, 1, 2){
            if (m > 0){
                m--;
                ma[i][j] = 0;
            }
        }
        FOE(i, 3, r){
            FOE(j, 1, (c/2)*2){
                if (m > 0){
                    m--;
                    ma[i][j]  =0;
                }
            }
        }
        FOE(i, 3, r){
            FOE(j, c+(c+1)%2, c){
                if (m > 0){
                    m--;
                    ma[i][j] = 0;
                }
            }
        }
    } else {
        m = r*c-m;
        if (m <= 8){
            printf("Impossible\n");
            return;
        }
        FOE(j, 1, c) FOE(i, 1, 2){
            if (m > 3){
                m--;
                ma[i][j] = 0;
            }
        }
        FOE(i, 3, r){
            FOE(j, 1, c){
                if (m > 3){
                    m--;
                    ma[i][j] = 0;
                }
            }
        }
        FOE(i, 1, r){
            FOE(j, 2, c-1){
                if ((m == 3) && ((ma[i][j]) && (ma[i][j-1]) && (ma[i][j+1]))){

                    m-=3;
                    ma[i][j] = ma[i][j-1] = ma[i][j+1] = 0;
                }
            }
        }
        FOE(j, 1, c){
            FOE(k, 1, r){
                FOE(i, 1, r-1){
                    if ((ma[i][j] == 1) && (ma[i+1][j] == 0)){
                        ma[i+1][j] = 1;
                        ma[i][j] = 0;
                    }
                }
            }

        }
        if ((ma[r][1] == 0) && (ma[r][2] == 1)){
            ma[r][2] = 0;
            int cnt = 1;
            FOD(j, c, 1) FOD(i, r-1, 1){
                if ((cnt == 1) && (ma[i][j] == 0)) {
                    cnt--;
                    ma[i][j] = 1;
                }
            }
        }
    }
    FOE(i, 1, r){
        FOE(j, 1, c){
            if ((i == 1) && (j == 1)) printf("c");
            else if (ma[i][j] == 0) printf(".");
            else printf("*");
        }
        printf("\n");
    }
    return;
}

int main(){
  freopen("C-large.in", "r", stdin);
  freopen("sol.out", "w", stdout);
    int t; scanf("%d", &t);
    FOE(i, 1, t) solve(i);
    return 0;
}
