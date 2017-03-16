#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XWON "X won"
#define OWON "O won"
#define DRAW "Draw"
#define NOT_COMPLETE "Game has not completed"
#define OUTPUT_STRING "Case #%d: %s\n"

char map[5][10];
int nCase;

void PrintResult(int cn, const char* res)
{
    printf(OUTPUT_STRING, cn, res);
}

int main()
{
    scanf("%d", &nCase);

    for (int cn=1; cn<=nCase; ++cn)
    {        
        for (int i=0; i<4; ++i)
        {
            scanf("%s", map[i]);
        }

        int resultFound = false;
        int hasDot = false;
        int o = 0;
        int x = 0;
        int t = 0;

        // check whether someone won
        for (int i=0; i<4 && !resultFound; ++i)
        {
            o = x = t = 0;
            for (int j=0; j<4; ++j)
            {
                o += (map[i][j] == 'O') ? 1 : 0;
                x += (map[i][j] == 'X') ? 1 : 0;
                t += (map[i][j] == 'T') ? 1 : 0;
                hasDot = map[i][j] == '.' ? true : hasDot;
            }
            if (o==3 && t==1 || o==4) 
            {
                PrintResult(cn, OWON);
                resultFound = true;
            }else
            if (x==3 && t==1 || x==4) 
            {
                PrintResult(cn, XWON);
                resultFound = true;
            }
        }

        for (int j=0; j<4 && !resultFound; ++j)
        {
            o = x = t = 0;
            for (int i=0; i<4; ++i)
            {
                o += (map[i][j] == 'O') ? 1 : 0;
                x += (map[i][j] == 'X') ? 1 : 0;
                t += (map[i][j] == 'T') ? 1 : 0;
            }
            if (o==3 && t==1 || o==4) 
            {
                PrintResult(cn, OWON);
                resultFound = true;
            }else
            if (x==3 && t==1 || x==4) 
            {
                PrintResult(cn, XWON);
                resultFound = true;
            }
        }

        o = x = t = 0;
        for (int i=0; i<4 && !resultFound; ++i)
        {            
            o += (map[i][i] == 'O') ? 1 : 0;
            x += (map[i][i] == 'X') ? 1 : 0;
            t += (map[i][i] == 'T') ? 1 : 0;
            if (o==3 && t==1 || o==4) 
            {
                PrintResult(cn, OWON);
                resultFound = true;
            }else
            if (x==3 && t==1 || x==4) 
            {
                PrintResult(cn, XWON);
                resultFound = true;
            }
        }

        o = x = t = 0;
        for (int i=0; i<4 && !resultFound; ++i)
        {
            o += (map[i][3-i] == 'O') ? 1 : 0;
            x += (map[i][3-i] == 'X') ? 1 : 0;
            t += (map[i][3-i] == 'T') ? 1 : 0;
            if (o==3 && t==1 || o==4) 
            {
                PrintResult(cn, OWON);
                resultFound = true;
            }else
            if (x==3 && t==1 || x==4) 
            {
                PrintResult(cn, XWON);
                resultFound = true;
            }
        }

        if (resultFound) continue;

        // check whether board is full
        // otherwise game hasn't completed
        if (hasDot)
        {
            PrintResult(cn, NOT_COMPLETE);
        } else
        {
            PrintResult(cn, DRAW);
        }
    }

    return 0;
}