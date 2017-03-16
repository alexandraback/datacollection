#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

__int64 gcd(__int64 a, __int64 b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testsCnt;
    scanf("%d", &testsCnt);
    for (int testN = 1; testN <= testsCnt; testN++) {
        __int64 a, b, g, cnt = 1;
        scanf("%I64d/%I64d", &a, &b);
        g = gcd(a, b);
        a /= g;
        b /= g;
        if (b & (b - 1)) {
            printf("Case #%d: impossible\n", testN);
            continue;
        }        
        while (a * 2 < b) {
            a *= 2;
            g = gcd(a, b);
            a /= g;
            b /= g;
            cnt++;
        }
        if (cnt <= 40)
            printf("Case #%d: %I64d\n", testN, cnt);
        else
            printf("Case #%d: impossible\n", testN);
    }
}