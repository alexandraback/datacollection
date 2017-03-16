#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stdlib.h>

using namespace std;

int f(int r, int c, int w) {
    return ((c + w - 1) / w + w - 1) + (r - 1) * (c / w);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int r, c, w;
        cin >> r >> c >> w;
        printf("Case #%d: %d\n", i, f(r, c, w));
    }
    return 0;
}
