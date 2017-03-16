/*
 * Author: tender
 * Created Time:  2013/4/27 9:08:57
 * File Name: a.cpp
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
    int cas;
    freopen("A-large.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        double r, t;
        scanf("%lf%lf", &r, &t);
        double d = (2 * r - 1) * (2 * r - 1) + 8 * t;
        d = sqrt(d);
        double x = ((1 - 2 * r) + d) / 2 / 2;
        long long ans = x - 3;
        while(((2 * r + 2 * ans - 1) * ans) <= t) ans++;
        printf("Case #%d: %lld\n", ii, ans - 1);
    }
    return 0;
}
