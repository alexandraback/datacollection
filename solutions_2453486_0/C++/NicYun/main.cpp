#include <iostream>
#include <stdio.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)

const int N = 4;

char c[10][10];
bool check(char a[], char target)
{
    REP(i, N)
    {
        if (a[i] != target && a[i] != 'T') return false;
    }
    return true;
}
char testline(char a[])
{
    if(check(a, 'O')) return 'O';
    if(check(a, 'X')) return 'X';
    return 0;
}



int main()
{
    freopen("D:/tc_algo/a.in", "r", stdin);
    freopen("D:/tc_algo/a.out", "w", stdout);

    int T;
    char test[4];
    scanf("%d", &T);
    REP(t, T)
    {
        REP(i, N) scanf("%s", c[i]);

        char win = 0;

        REP(i, N)
        {
            REP(j, N)
            {
                test[j] = c[i][j];
            }
            char res = testline(test);
            if(res != 0) win = res;

            REP(j, N)
            {
                test[j] = c[j][i];
            }
            res = testline(test);
            if(res != 0) win = res;
        }

        REP(i, N)
        {
            test[i] = c[i][i];
        }
        char res = testline(test);
        if(res != 0) win = res;

        REP(i, N)
        {
            test[i] = c[i][N-i-1];
        }
        res = testline(test);
        if(res != 0) win = res;

        if(win != 0)
        {
            printf("Case #%d: %c won\n", t + 1, win);
            continue;
        }

        bool dot = false;
        REP(i, N) REP(j, N) if(c[i][j] == '.') dot = true;
        if(dot)
        {
            printf("Case #%d: Game has not completed\n", t + 1);
        }
        else
        {
            printf("Case #%d: Draw\n", t + 1);
        }

    }
    return 0;
}
