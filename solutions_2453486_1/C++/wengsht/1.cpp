
/*
ID: wengsht1
LANG: C++
TASK: test
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define MX 100005
#define REP(i,n) for(int i=0;i<(n);i++)
#define OREP(i,n) for(int i=1;i<=(n);i++)

typedef long long          LL;
typedef unsigned long long ULL;
typedef unsigned int       UINT;

int n, m, k, t, c;

int state[4][4];
char tmp[10];
bool judge(int color) {
    REP(i, 4) {
        bool good = true;
        REP(j, 4) {
            if(state[i][j] == color || state[i][j] == 3)
                ;
            else { good = false; break; };
        }
        if(good) return good;
    }
    REP(j, 4) {
        bool good = true;
        REP(i, 4) {
            if(state[i][j] == color || state[i][j] == 3)
                ;
            else { good = false; break; };
        }
        if(good) return good;
    }
    bool good1 = true, good2 = true;
    REP(i, 4) {
        if(state[i][i] == color || state[i][i] == 3)
            ;
        else good1 = false;
        if(state[i][3-i] == color || state[i][3-i] == 3)
            ;
        else good2 = false;

    }
    return good1 | good2;
}
int main() {
    scanf("%d", &t);
    OREP(c, t) {
        bool finish = true;
        REP(i, 4) {
            scanf("%s", tmp);
            REP(j, 4) {
                if(tmp[j] == '.') {
                    state[i][j] = 0;
                    finish = false;
                }
                else if(tmp[j] == 'X') state[i][j] = 1;
                else if(tmp[j] == 'O') state[i][j] = 2;
                else state[i][j] = 3;
            }
        }
        printf("Case #%d: ", c);
        if(judge(1)) printf("X won\n");
        else if(judge(2)) printf("O won\n");
        else if(finish) printf("Draw\n");
        else printf("Game has not completed\n");
    }
    return 0;
}

