#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
bool vis[MAXN];
int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T; cin>>T;
    for(int cs = 1; cs <= T; cs ++) {
        cerr << "Processing Case #" << cs << "...\n";
        printf("Case #%d: ", cs);
        int n; cin >> n;
        for(int i = 1; i <= 2500; i ++) vis[i] = 0;
        for(int i = 0, x; i < 2 * n - 1; i ++) {
            for(int j = 0; j < n; j ++) {
                scanf("%d", &x);
                vis[x] ^= 1;
            }
        }
        for(int i = 1, j = 0; i <= 2500; i ++) {
            if(vis[i]) {
                printf("%d%c", i, j == n - 1 ? '\n' : ' ');
                ++ j;
            }
        }
    }
    return 0;
}

