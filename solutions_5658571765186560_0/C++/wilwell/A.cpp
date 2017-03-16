#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for (int i = 1; i <= TEST; ++i)
    {
        int x, r, c;
        scanf("%d%d%d", &x, &r, &c);
        if (x == 1)
        {
            printf("Case #%d: GABRIEL\n", i);
            continue;
        }
        if (x == 2)
        {
            if ((r * c) % 2 == 0)
            {
                printf("Case #%d: GABRIEL\n", i);
            }
            else
            {
                printf("Case #%d: RICHARD\n", i);
            }
            continue;
        }
        if (x == 3)
        {
            if ((c * r) % 3 == 0 && c > 1 && r > 1)
            {
                printf("Case #%d: GABRIEL\n", i);
            }
            else
            {
                printf("Case #%d: RICHARD\n", i);
            }
        }
        if (x == 4)
        {
            if ((c * r) % 4 == 0 && ((c >= 3 && r >= 4) || (c >= 4 && r >= 3)))
            {
                printf("Case #%d: GABRIEL\n", i);
            }
            else
            {
                printf("Case #%d: RICHARD\n", i);
            }
            continue;
        }
        if (x > 6)
        {
            printf("Case #%d: RICHARD\n", i);
            continue;
        }
    }

}
