#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

int t;
int n, s, p, sco[128];

void solve() {
    scanf("%d%d%d", &n, &s, &p);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sco[i]);
        int a = sco[i] / 3, b = (sco[i] - a) / 2, c = sco[i] - a - b;
        if (c >= p) {
            ++ans;
        } else if (c + 1 == p) {
            if (b == c && b > 0 && s > 0) {
                ++ans;
                --s;
            }
        }
    }
    printf("Case #%d: %d\n", ++t, ans);
}

int main() {
    freopen("B.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
