#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int solve() {
    int a, n;
    scanf("%d%d", &a, &n);
    vector<int> sz(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &sz[i]);
    sort(sz.begin(), sz.end());

    int ans = 100500;

    for (int thr = 0; thr <= n; ++thr) {
        int cur_ans = thr;
        int s = a;
        bool found = true;
        for (int i = 0; i + thr < n; ++i) {
            if (s == 1 && s <= sz[i]) {
                found = false;
                break;
            }
            while (s <= sz[i]) {
                s += s - 1;
                ++cur_ans;
            }
            s += sz[i];
        }
        if (found)
            ans = min(ans, cur_ans);
    }

    return ans;
}

int main() {
    int tt;
    scanf("%d", &tt);
    for (int t = 1; t <= tt; ++t) {
        printf("Case #%d: %d\n", t, solve());
    }

    return 0;
}

