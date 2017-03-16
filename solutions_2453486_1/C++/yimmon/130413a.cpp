/*========================================================================
#   FileName: 130413a.cpp
#     Author: YIMMON
#      Email: yimmon.zhuang@gmail.com
#   HomePage: http://qr.ae/8DMzu
# LastChange: 2013-04-13 10:57:42
========================================================================*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T;
char g[5][5];

inline void judge(char ch, int &x, int &o)
{
    if(ch == 'T') ++x, ++o;
    else if(ch == 'X') ++x;
    else if(ch == 'O') ++o;
}

inline int solve()
{
    for(int i = 0; i < 4; ++i)
        for(int j = 0, x = 0, o = 0; j < 4; ++j)
            if(judge(g[i][j], x, o), x == 4)
                return 1;
            else if(o == 4)
                return 2;
    for(int i = 0; i < 4; ++i)
        for(int j = 0, x = 0, o = 0; j < 4; ++j)
            if(judge(g[j][i], x, o), x == 4)
                return 1;
            else if(o == 4)
                return 2;
    for(int i = 0, x = 0, o = 0; i < 4; ++i)
        if(judge(g[i][i], x, o), x == 4)
            return 1;
        else if(o == 4)
            return 2;
    for(int i = 0, x = 0, o = 0; i < 4; ++i)
        if(judge(g[i][3-i], x, o), x == 4)
            return 1;
        else if(o == 4)
            return 2;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            if(g[i][j] == '.')
                return 4;
    return 3;
}

int main(int argc, char **argv)
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d: ", cas);
        for(int i = 0; i < 4; ++i)
            scanf("%s", g[i]);
        switch(solve())
        {
        case 1:
            puts("X won");
            break;
        case 2:
            puts("O won");
            break;
        case 3:
            puts("Draw");
            break;
        case 4:
            puts("Game has not completed");
        }
    }

    return 0;
}
