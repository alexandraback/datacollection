#include <stdio.h>

int main()
{
    /*
    freopen("D-small-attempt2.in", "r", stdin);
    freopen("D-small-attempt2.out", "w", stdout);*/
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    
    int cases;
    scanf("%d", &cases);
    for (int c = 1; c <= cases; c++)
    {
        int X, R, C;
        scanf("%d %d %d", &X, &R, &C);
        
        if (R * C % X != 0)
        {
            printf("Case #%d: RICHARD\n", c);
        }
        else if (X >= 7)
        {
            printf("Case #%d: RICHARD\n", c);
        }
        else if (X == 1 || X == 2)
        {
            printf("Case #%d: GABRIEL\n", c);
        }
        else if (R < (X + 1) / 2 || C < (X + 1) / 2)
        {
            printf("Case #%d: RICHARD\n", c);
        }
        else if (X == 3)
        {
            printf("Case #%d: GABRIEL\n", c);
        }
        else if (X == 4)
        {
            if (R == 2 || C == 2)
            {
                printf("Case #%d: RICHARD\n", c);
            }
            else
            {
                printf("Case #%d: GABRIEL\n", c);
            }
        }
        else if (X == 5)
        {
            if (R * C == 15)
            {
                printf("Case #%d: RICHARD\n", c);
            }
            else
            {
                printf("Case #%d: GABRIEL\n", c);
            }
        }
        else if (X == 6)
        {
            if (R == 3 || C == 3)
            {
                printf("Case #%d: RICHARD\n", c);
            }
            else
            {
                printf("Case #%d: GABRIEL\n", c);
            }
        }
        else
        {
            printf("Case #%d: GABRIEL\n", c);
        }
    }
    
    return 0;
}
