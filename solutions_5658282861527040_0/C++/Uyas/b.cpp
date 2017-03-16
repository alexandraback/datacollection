#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        int a, b, c; 
        scanf("%d%d%d", &a, &b, &c);
        int ans = 0;
        for (int x = 0; x < a; ++x)
        for (int y = 0 ; y < b; ++y) {
            int z = x & y;
            if (z < c) ++ans;
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
