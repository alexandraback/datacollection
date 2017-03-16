#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int ans, vis[1500], next[1500], maxl[1500];

void find(int x){
        memset(vis, 0, sizeof(vis));
        int pre = 0;
        int len = 1;

        int i = x;
        while (true) {
                vis[i] = true;
                if (next[i] == pre) {   // CP
                        maxl[i] = max(maxl[i], len);
                        break;
                } else if (vis[next[i]]) {
                        if (next[i] == x) ans = max(ans, len); // circle;
                        break;
                }
                len ++;
                pre = i;
                i = next[i]; 
        }
}

int main(){
        freopen("c.in", "r", stdin);
        freopen("c.out", "w", stdout);

        int tt, ca = 0;
        scanf("%d", &tt);
        while (tt--) {
                printf("Case #%d: ", ++ca);
                int n;
                scanf("%d", &n);
                for (int i = 1; i <= n; i ++) scanf("%d", &next[i]);
                ans = 0;
                memset(maxl, 0, sizeof(maxl));
                for (int i = 1; i <= n; i ++) find(i);
                int tot = 0;
                for (int i = 1; i <= n; i ++) {
                        int j = next[i];
                        if (next[j] == i && i < j) {
                                tot += maxl[i] + maxl[j] - 2;
                        }
                }
                ans = max(ans, tot);
                printf("%d\n", ans);
        }
}
