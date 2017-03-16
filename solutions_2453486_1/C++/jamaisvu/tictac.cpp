#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
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
char b[5][5];

int x, o;

int solve(){
    int bod = 0;


    REP(i,4){
        x = o = 0;
        REP(j,4){
            switch(b[i][j]){
              case '.':
                bod = 1; break;
              case 'X':
                x++; break;
              case 'O':
                o++; break;
              case 'T':
                x++; o++; break;
            }
        }
        if (x == 4) return 0;
        if (o == 4) return 1;
    }

    REP(i,4){
        x = o = 0;
        REP(j,4){
            switch(b[j][i]){
              case 'X':
                x++; break;
              case 'O':
                o++; break;
              case 'T':
                x++; o++; break;
            }
        }
        if (x == 4) return 0;
        if (o == 4) return 1;
    }

        x = o = 0;
        REP(i,4){
            switch(b[i][i]){
              case 'X':
                x++; break;
              case 'O':
                o++; break;
              case 'T':
                x++; o++; break;
            }
        }
        if (x == 4) return 0;
        if (o == 4) return 1;

        x = o = 0;
        REP(i,4){
            switch(b[i][3 - i]){
              case 'X':
                x++; break;
              case 'O':
                o++; break;
              case 'T':
                x++; o++; break;
            }
        }
        if (x == 4) return 0;
        if (o == 4) return 1;

        if (bod) return 2;
        else return 3;

}

int main() {
    int n;
    scanf("%d\n",&n);
    FOR(i,1,n){
        REP(j,4){
          scanf("%c%c%c%c\n", &b[j][0], &b[j][1], &b[j][2], &b[j][3]);
        }

        switch (solve()){
            case 0:
                printf("Case #%d: X won\n",i);
                break;
            case 1:
                printf("Case #%d: O won\n",i);
                break;
            case 2:
                printf("Case #%d: Game has not completed\n",i);
                break;
            case 3:
                printf("Case #%d: Draw\n",i);
                break;
      }

        scanf("\n");

    }

  return 0;
}
