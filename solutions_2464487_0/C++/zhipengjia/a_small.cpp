#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

void work() {
    int r, t;
    scanf("%d%d", &r, &t);
    int ans = 0;
    while (true) {
        int need = (r + 1) * (r + 1) - r * r;
        if (t < need) break;
        ans ++;
        t -= need;
        r += 2;
    }
    printf("%d\n", ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test ++) {
        printf("Case #%d: ", test + 1);
        work();
    }

    return 0;
}