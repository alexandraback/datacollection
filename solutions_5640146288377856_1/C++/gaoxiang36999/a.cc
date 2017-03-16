#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long LL;
int t, r, c, w;
int main() {
    freopen("Ain.in", "r", stdin);
    freopen("Aout.out", "w", stdout);
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        scanf("%d%d%d", &r, &c, &w);
        int ans = 0;
        ans = r * (c / w);
        if(c % w == 0) ans += (w - 1);
        else ans += w;
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
