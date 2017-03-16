#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <string.h>
#include <math.h>

using namespace std;

int X, R, C;

int run()
{
    cin >> X >> R >> C;

    if(R > C) {
        swap(R, C);
    }
    if(X > 6 || (X + 1)/2 > R || X > C || (R * C % X != 0)) {
        return -1;
    }

    if(X < 4) {
        return 0;
    }

    if(X == 4 && R < 3) {
        return -1;
    }
    if(X == 5 && R == 3 && C < 10) {
        return -1;
    }
    if(X == 5) {
        return 0;
    }

    if(X == 6 && R < 4) {
        return -1;
    }
    return 0;
}


int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        int res = run();
        if(res != 0) {
            printf("RICHARD\n");
        } else {
            printf("GABRIEL\n");
        }
    }

    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

