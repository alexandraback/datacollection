#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define _clr(x) memset(x, 0, sizeof(x))
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP_1(i, n) for (int i = 1; i <= (n); i++)
int xRow[4], xCol[4], oRow[4], oCol[4], xDia[2], oDia[2];

int main() {
//    freopen("A-large.in", "r", stdin);
//    freopen("A-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    REP_1(cas, T) {
        bool complete = true;
        char buf[10];
        _clr(xRow);
        _clr(xCol);
        _clr(oRow);
        _clr(oCol);
        _clr(xDia);
        _clr(oDia);
        REP(i, 4) {
            scanf("%s", &buf);
            REP(j, 4) {
                if (buf[j] == 'O') {
                    oRow[i]++;
                    oCol[j]++;
                } else if (buf[j] == 'X') {
                    xRow[i]++;
                    xCol[j]++;
                } else if (buf[j] == 'T') {
                    oRow[i]++;
                    oCol[j]++;
                    xRow[i]++;
                    xCol[j]++;
                } else if (buf[j] == '.') {
                    complete = false;
                }
            }
            if (buf[i] == 'O') {
                oDia[0]++;
            } else if (buf[i] == 'X') {
                xDia[0]++;
            } else if (buf[i] == 'T') {
                oDia[0]++;
                xDia[0]++;
            }
            if (buf[3 - i] == 'O') {
                oDia[1]++;
            } else if (buf[3 - i] == 'X') {
                xDia[1]++;
            } else if (buf[3 - i] == 'T') {
                oDia[1]++;
                xDia[1]++;
            }
        }
        printf("Case #%d: ", cas);
        bool pnt = false;
        REP(i, 4) {
//            cout << "!! " << i << endl;
            if (oRow[i] == 4 || oCol[i] == 4 || oDia[i & 1] == 4) {
                puts("O won");
                pnt = true;
                break;
            } else if (xRow[i] == 4 || xCol[i] == 4 || xDia[i & 1] == 4) {
                puts("X won");
                pnt = true;
                break;
            }
        }
        if (!pnt) {
            if (complete) {
                puts("Draw");
            } else  {
                puts("Game has not completed");
            }
        }
    }
    return 0;
}




