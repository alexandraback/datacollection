#include <stdio.h>
#include <vector>
using namespace std;
vector<int> e[1010];
int u[1010];
bool dfs(int x, int xx){
    int i, y;
    if (u[x] == xx) return true;
    u[x] = xx;
    for (i = 0; i < e[x].size(); i++){
        y = e[x][i];
        if (dfs(y, xx)) return true;
    }
    return false;
}
int main(){
    int T, ri = 1, n, i, x, m;
    freopen("A-small-attempt1 (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (i = 1; i <= n; i++){
            u[i] = 0;
            e[i].clear();
            scanf("%d", &m);
            while (m--){
                scanf("%d", &x);
                e[i].push_back(x);
            }
        }
        for (i = 1; i <= n; i++){
            if (u[i] == 0){
                if (dfs(i, i)) break;
            }
        }
        if (i <= n) printf("Case #%d: Yes\n", ri++);
        else printf("Case #%d: No\n", ri++);
    }
    return 0;
}
