#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 105;
int a, n;
int v[maxn];

int main() {
    freopen("in1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d", &a, &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        if (a <= 1) {
            printf("Case #%d: %d\n", cas, n);
            continue;
        }
        sort(v + 1, v + n + 1);
        vector<int> ans;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (a <= v[i]) {
                ans.push_back(cur + n - i + 1);
                while (a <= v[i]) {
                    cur++;
                    a += (a - 1);
                }
            }
            a += v[i];
        }
        for (int i = 0; i < ans.size(); i++)
            cur = min(cur, ans[i]);
        printf("Case #%d: %d\n", cas, cur);
    }
    return 0;
}