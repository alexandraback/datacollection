#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;

bool canTrap(int x, int r, int c)
{
    if (r > c)
        return canTrap(x, c, r);
    if (x >= 7)
        return true;
    if ((r * c) % x != 0)
        return true;
    if (x == 1)
        return false;
    if (x == 2)
        return false;
    if (x == 3)
        return (r == 1);
    if (x == 4)
        return (r <= 2) || (c <= 3);
    if (x == 5)
        return (r <= 2) || (r == 3 && c == 5);
    if (x == 6)
        return (r <= 3) ;
    return false;
}

int main()
{
    int t, test;
    scanf("%d", &test);
    for (t = 0; t < test; t++)
    {
        int x, r, c;
        scanf("%d %d %d", &x, &r, &c);

        if (canTrap(x, r, c))
            printf("Case #%d: RICHARD\n", t+1);
        else
            printf("Case #%d: GABRIEL\n", t+1);
    }
    return 0;
}
