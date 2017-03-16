#include <algorithm>
#include <cassert>
#include <iostream>
#include <cstdio>
using namespace std;

bool solve()
{
    int X, R, C; cin >> X >> R >> C;

    if (R * C % X != 0) return true;
    if (X == 1) return true;

    if (R > C) swap(R, C);
    if (X == 2) return R == 1 && C == 1;
    if (X == 3) return R == 1;
    if (X == 4) return R == 1 || R == 2;

    assert(false);
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
        printf("Case #%d: %s\n", t, solve() ? "RICHARD" : "GABRIEL");
    return 0;
}
