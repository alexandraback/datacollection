#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int T, c, d, v;
bool vis[100];
vector<int> p;

int solve() {
    for (int i = v; i >= 1; i--) {
        if (!vis[i]) continue;
        for (int j = v; j > i; j--) {
            if (vis[j]) vis[i + j] = 1;
        }
    }

    int ret = 0;
    for (int i = 1; i <= v; i++) {
        if (!vis[i]) {
            ret++;
            for (int j = v; j >= 1; j--) {
                if (vis[j]) vis[j + i] = true;
            }
            vis[i] = true;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        p.clear();
        memset(vis, 0, sizeof vis);
        scanf("%d%d%d", &c, &d, &v);
        for (int j = 0; j < d; j++) {
            int tmp;
            scanf("%d", &tmp);
            vis[tmp] = 1;
        }
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}
