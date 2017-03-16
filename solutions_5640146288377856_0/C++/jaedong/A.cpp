#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        int r, c, w;
        scanf("%d%d%d", &r, &c, &w);
        int last = w;
        if (c % w == 0) last--;
        printf("Case #%d: %d\n", cs, r * (c / w) + last);
    }
}
