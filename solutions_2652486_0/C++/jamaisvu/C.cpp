#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>

#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long int lli;
/*******************************************************/

int suma[20];
int map[100][1000];
int f1[1000], f2[1000], f3[1000];

int main() {
    int R, N, M, K;

    scanf("%*d");

    scanf("%d%d%d%d", &R, &N, &M, &K);

    memset(map, 0, sizeof(int) * 1000);

    int f = 0;
    FOR(a,2,5)FOR(b,a,5)FOR(c,b,5){ map[f][0] = a;map[f][1] = b;map[f][2] = c;map[f][3] = a*b;map[f][4] = a*c;
    map[f][5] = b*c; map[f][6] = a*b*c; map[f][7] = 1;   f1[f]= a; f2[f] = b; f3[f] = c; f++; }

    int ok, zle, was;
    printf("Case #1:\n");
    REP(j,R){

        REP(m,K)scanf("%d", &suma[m]);
        was = 0;

        REP(x,f){
            zle = 0;
               REP(m,K){
                   ok = 0;

                    REP(d,8){
                        if( map[x][d] == suma[m] ) ok = 1;
                    }
                    if (!ok){zle = 1; break;}
               }
               if (!zle ){ printf ("%d%d%d\n", f1[x],f2[x],f3[x]); was = 1;break;}
        }
        if (!was)printf ("%d%d%d\n", f1[2],f2[3],f3[4]);

    }


  return 0;
}
