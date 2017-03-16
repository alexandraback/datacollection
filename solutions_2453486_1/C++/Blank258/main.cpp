# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

char map[5][5];


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("out", "w", stdout);
    int dot, t, i, j, cnt = 1;
    int owin, xwin, o, x;
    scanf("%d", &t);
    while(cnt <= t)
    {
        for(i = dot = 0; i < 4; i++)
        {
            scanf("%s", map[i]);
            if(!strlen(map[i]))
            {
                i--;
            }
            else
            {
                for(j = 0; j < 4; j++)
                {
                    if(map[i][j] == '.')
                    {
                        dot++;
                    }
                }
            }
        }
        o = x = 0;
        for(i = 0; i < 4; i++)
        {
            owin = xwin = 0;
            for(j = 0; j < 4; j++)
            {
                if(map[i][j] == 'X')
                {
                    xwin++;
                }
                else if(map[i][j] == 'O')
                {
                    owin++;
                }
                else if(map[i][j] == 'T')
                {
                    owin++;
                    xwin++;
                }
                else if(map[i][j] == '.')
                {
                    break;
                }
            }
            if(owin == 4)   o++;
            if(xwin == 4)   x++;
        }
        for(j = 0; j < 4; j++)
        {
            owin = xwin = 0;
            for(i = 0; i < 4; i++)
            {
                if(map[i][j] == 'X')
                {
                    xwin++;
                }
                else if(map[i][j] == 'O')
                {
                    owin++;
                }
                else if(map[i][j] == 'T')
                {
                    owin++;
                    xwin++;
                }
                else if(map[i][j] == '.')
                {
                    break;
                }
            }
            if(owin == 4)   o++;
            if(xwin == 4)   x++;
        }
        owin = xwin = 0;
        for(i = j = 0; i < 4; i++, j++)
        {
            if(map[i][j] == 'X')
            {
                xwin++;
            }
            else if(map[i][j] == 'O')
            {
                owin++;
            }
            else if(map[i][j] == 'T')
            {
                owin++;
                xwin++;
            }
            else if(map[i][j] == '.')
            {
                break;
            }
        }
        if(owin == 4)   o++;
        if(xwin == 4)   x++;
        xwin = owin = 0;
        for(i = 0, j = 3; i < 4; i++, j--)
        {
            if(map[i][j] == 'X')
            {
                xwin++;
            }
            else if(map[i][j] == 'O')
            {
                owin++;
            }
            else if(map[i][j] == 'T')
            {
                owin++;
                xwin++;
            }
            else if(map[i][j] == '.')
            {
                break;
            }
        }
        if(owin == 4)   o++;
        if(xwin == 4)   x++;
        if(o > x)
        {
            printf("Case #%d: O won\n", cnt++);
            continue;
        }
        if(x > o)
        {
            printf("Case #%d: X won\n", cnt++);
            continue;
        }
        if(x == o && dot == 0)
        {
            printf("Case #%d: Draw\n", cnt++);
            continue;
        }
        if(x == o && dot != 0)
        {
            printf("Case #%d: Game has not completed\n", cnt++);
            continue;
        }
    }
    return 0;
}

