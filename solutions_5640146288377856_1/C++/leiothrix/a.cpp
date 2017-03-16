#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, r, c, w, t;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d%d", &r, &c, &w);
        if (c % w) {
            t = c / w - 1;
            t += w + 1;
        } else t= c / w - 1 + w;
        printf("Case #%d: %d\n", ca, (r - 1)* (c / w) + t);
    }
    return 0;
}

