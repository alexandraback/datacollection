#include <iostream>
#include <stdio.h>
using namespace std;

int check(int a, int b, int c, int d, int& x_need, int& o_need)
{
    int t = a + b + c + d;
    //printf("%d %d %d %d\n", a,b,c,d);
    if ((t & 7) == 4)
    {
        return 1;
    }
    if ((t >> 3) == 4)
    {
        return 2;
    }
    int zero = (a == 0) + (b == 0) + (c == 0) + (d == 0);

    if ((t & 7) + zero == 4 && zero < x_need)
    {
        x_need = zero;
    }
    else if ((t >> 3) + zero == 4 && zero < o_need)
    {
        o_need = zero;
    }
    return 0;
}

int main()
{
    int case_num, i(0), j, k, x, o, t, dot;
    int map[4][4];
    char temp;
    int turn;
    scanf("%d", &case_num);
    while (i++ < case_num)
    {
        scanf("%c", &temp);
        x = o = t = dot = 0;
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 5; k++)
            {
                scanf("%c", &temp);
                if (temp == 'X')
                {
                    map[j][k] = 1;
                    x++;
                }
                else if (temp == 'O')
                {
                    map[j][k] = 8;
                    o++;
                }
                else if (temp == 'T')
                {
                    map[j][k] = 9;
                    t++;
                }
                else if (temp == '.')
                {
                    map[j][k] = 0;
                    dot++;
                }
            }
        }
        printf("Case #%d: ", i);
        if (x==o)
        {
            turn = 2;
        }
        else
        {
            turn = 1;
        }
        int x_need = 5;
        int o_need = 5;
        if (check(map[0][0], map[0][1], map[0][2], map[0][3], x_need, o_need) == turn
            || check(map[1][0], map[1][1], map[1][2], map[1][3], x_need, o_need) == turn
            || check(map[2][0], map[2][1], map[2][2], map[2][3], x_need, o_need) == turn
            || check(map[3][0], map[3][1], map[3][2], map[3][3], x_need, o_need) == turn
            || check(map[0][0], map[1][0], map[2][0], map[3][0], x_need, o_need) ==  turn
            || check(map[0][1], map[1][1], map[2][1], map[3][1], x_need, o_need) ==  turn
            || check(map[0][2], map[1][2], map[2][2], map[3][2], x_need, o_need) == turn
            || check(map[0][3], map[1][3], map[2][3], map[3][3], x_need, o_need) == turn
            || check(map[0][0], map[1][1], map[2][2], map[3][3], x_need, o_need) == turn
            || check(map[0][3], map[1][2], map[2][1], map[3][0], x_need, o_need) == turn)
        {
            if (turn == 1)
            {
                printf("X won\n");
            }
            else
            {
                printf("O won\n");
            }
        }
        else if (dot == 0)
        {
            printf("Draw\n");
        }
        else
        {
            printf("Game has not completed\n");
        }
    }
    return 0;
}
