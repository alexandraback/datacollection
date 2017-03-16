#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

#define ROW 4
#define COL 4
#define LINE 4

const char result[4][100] = {"X won", "O won", "Draw", "Game has not completed"};
char matrix[ROW][COL + 1];

int
main ()
{
    int T, ans;
    int cntx, cnto, cntdot;

    scanf ("%d", &T);
    for (int k = 1; k <= T; ++k) {
        for (int i = 0; i < ROW; ++i) {
            scanf ("%s", matrix[i]);
        }
        cntdot = 0;
        ans = -1;
        for (int i = 0; i < ROW; ++i) {
            cntx = cnto = 0;
            for (int j = 0; j < COL; ++j) {
                cntx += (matrix[i][j] == 'X' || matrix[i][j] == 'T');
                cnto += (matrix[i][j] == 'O' || matrix[i][j] == 'T');
                cntdot += (matrix[i][j] == '.');
            }
            if (cntx == LINE) ans = 0;
            else if (cnto == LINE) ans = 1;
        }
        for (int j = 0; j < COL; ++j) {
            cntx = cnto = 0;
            for (int i = 0; i < ROW; ++i) {
                cntx += (matrix[i][j] == 'X' || matrix[i][j] == 'T');
                cnto += (matrix[i][j] == 'O' || matrix[i][j] == 'T');
                cntdot += (matrix[i][j] == '.');
            }
            if (cntx == LINE) ans = 0;
            else if (cnto == LINE) ans = 1;
        }
        cntx = cnto = 0;
        for (int i = 0; i < ROW; ++i) {
            cntx += (matrix[i][i] == 'X' || matrix[i][i] == 'T');
            cnto += (matrix[i][i] == 'O' || matrix[i][i] == 'T');
            cntdot += (matrix[i][i] == '.');
        }
        if (cntx == LINE) ans = 0;
        else if (cnto == LINE) ans = 1;

        cntx = cnto = 0;
        for (int i = 0; i < ROW; ++i) {
            cntx += (matrix[i][COL - 1 - i] == 'X' || matrix[i][COL - 1 - i] == 'T');
            cnto += (matrix[i][COL - 1 - i] == 'O' || matrix[i][COL - 1 - i] == 'T');
            cntdot += (matrix[i][COL - 1 - i] == '.');
        }
        if (cntx == LINE) ans = 0;
        else if (cnto == LINE) ans = 1;

        if (ans == -1 && cntdot != 0) ans = 3;
        else if (ans == -1 && cntdot == 0) ans = 2;

        printf ("Case #%d: %s\n", k, result[ans]);
    }
    return 0;
}
