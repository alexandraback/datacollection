#include <iostream>
#include <cstdio>
using namespace std;

bool judge(int x, int r, int c)
{
    if ((r*c) % x > 0) return false;
    if (x == 1 || x == 2) return true;
    if (r < c) swap(r, c);
    if (x == 3)
    {
        if (r < 3) return false;
        if (r == 3 && c == 1) return false;
        return true;
    }
    if (x == 4)
    {
        if (r < 4) return false;
        if ((r == 4 && c == 1) || (r == 4 && c == 2))return false;
        return true;
    }
}

int main()
{
    //freopen("D-small-attempt0.in", "r", stdin);
    //freopen("D-small-attempt0.out", "w", stdout);
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        int x, r, c;
        scanf("%d %d %d", &x, &r, &c);
        printf("Case #%d: %s\n", cas, judge(x,r,c)?("GABRIEL"):("RICHARD"));
    }
    return 0;
}
