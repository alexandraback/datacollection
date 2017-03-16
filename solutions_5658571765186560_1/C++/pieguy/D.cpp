#include <cstdio>
#include <algorithm>
#include <cassert>

bool solve(int X, int R, int C)
{
    if (X == 1) return false; // obviously
    if (X >= 7) return true; // hole
    if ((R*C) % X) return true; // area
    if (X > R && X > C) return true; // I shape
    if (X >= R+C) return true; // L shape
    if (X > 2*R) return true; // L shape
    if (X <= R && X <= C) return false; // probably right
    if (X == 2) return false;
    if (X == 3) return false;
    if (X == 4)
    {
        if (R == 2) return true; // s shape
        if (R == 3) return false;
    }
    if (X == 5)
    {
        if (R == 3)
        {
            if (C == 5) return true; // w shape
            return false;
        }
        return false;
    }
    if (X == 6)
    {
        if (R == 3) return true; // Y shape
        return false; // 6 4 6 is the only remotely troubling case
    }
    printf("%d %d %d\n", X, R, C);
    assert(false);
    return false;
}

int main()
{
    /*
    for(int X=1; X<=20; X++)
    for(int R=1; R<=20; R++)
    for(int C=R; C<=20; C++)
    {
        solve(X, R, C);
    }
    */
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int X, R, C;
        scanf("%d %d %d", &X, &R, &C);
        if (R>C) { std::swap(R, C); }
        printf("Case #%d: %s\n", t, solve(X, R, C) ? "RICHARD" : "GABRIEL");
    }
}
