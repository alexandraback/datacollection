/*
 * Author: tender
 * Created Time:  2013/5/12 17:49:16
 * File Name: b.cpp
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <set>

using namespace std;
const double pi = acos(-1.0);
int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d: ", ii);
        int x, y;
        scanf("%d%d", &x, &y);
        if (x >= 0)
            for (int i = 0; i < x; i++)
                printf("WE");
        else {
            x = -x;
            for (int i = 0; i < x; i++)
                printf("EW");
        }
        if (y >= 0)
            for (int i = 0; i < y; i++)
                printf("SN");
        else {
            y = -y;
            for (int i = 0; i < y; i++)
                printf("NS");
        }
        printf("\n");
    }
    return 0;
}
