#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 1010

using namespace std;

int T, N, to[MaxN];
int exist[MaxN];
int ans2[MaxN], f[MaxN], ans3[MaxN];

int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

int main() {
    freopen("C-large (2).in", "r", stdin);
    freopen("C-large (2).out", "w", stdout);
    int T0 = 0;
    scanf("%d", &T);
    for ( ; T; --T) {
        memset(ans3, 0, sizeof(ans3));
        memset(ans2, 0, sizeof(ans2));
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &to[i]);
        int ans = 0, tot2 = 0;
        for (int i = 1; i <= N; ++i) {
            bool flag = false;
            int cnt = 1;
            memset(exist, 0, sizeof(exist));
            exist[i] = 1;
            int j;
            for (j = to[i]; !exist[j]; j = to[j]) {
                ++cnt;
                exist[j] = cnt;
                //printf("%daa\n", j);
            }
            if (j == i) {
                ans = max(ans, cnt);
            }
            if (cnt == exist[j] + 1) {
                ans2[i] = cnt;
                ans3[j] = max(ans3[j], cnt);
                //printf("%d!%d %d\n", i, j, cnt);
            }
        }
        for (int i = 1; i <= N; ++i) {
            f[i] = i;
            if (ans3[to[i]] != 0) {
                ans2[i] = max(ans2[i], ans3[i] + ans3[to[i]] - 2);
            }
        }
        for (int i = 1; i <= N; ++i) {
            int x = find(i), y = find(to[i]);
            if (x != y) {
                f[x] = y;
                ans2[y] = max(ans2[y], ans2[x]);
            }
        }
        for (int i = 1; i <= N; ++i) {
            if (find(i) == i) {
                tot2 += ans2[i];
            }
        }
        printf("Case #%d: %d\n", ++T0, max(ans, tot2));
    }
    return 0;
}
