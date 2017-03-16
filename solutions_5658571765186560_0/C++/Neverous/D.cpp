/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

inline
bool main_case(void)
{
    int X = 0;
    int R = 0;
    int C = 0;
    scanf("%d %d %d", &X, &R, &C);
    fprintf(stderr, "%d %d %d\n", X, R, C);
    if(X == 1)
        return false;

    if((R * C) % X)
        return true;

    if(X == 2)
        return false;

    if(X == 3)
        return R < 2 || C < 2;

    if(X == 4)
    {
        if(R < 2 || C < 2)
            return true;

        if(R < 4 && C < 4)
            return true;

        if(R * C <= 8)
            return true;

        return false;
    }

    if(X == 5)
    {
        throw "NOTYET";
    }

    if(X == 6)
    {
        throw "NOTYET";
    }

    return true;
}

int main(void)
{
    int tests = 0;
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        printf("Case #%d: %s\n", t + 1, main_case() ? "RICHARD" : "GABRIEL");

    return 0;
}
