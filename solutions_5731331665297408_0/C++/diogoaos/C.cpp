#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

typedef long long lint;

using namespace std;

int a[10];
int pos[10];
bool mark[10];

int deg[10], adj[10][10];
int next;

void dfs(int p, int n) {
    //printf("dfs(%d %d) next = %d\n", p, n, next);
    if (p == n) {
        return;
    }    
    
    if (p == next) {
        next++;
    }
    
    int u = a[p];
    
    if (mark[u]) return;
    mark[u] = true;
    
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        //printf("adj[%d][%d] = %d, pos[%d] = %d\n", u, i, v, v, pos[v]);
        if (pos[v] == next) {
            //printf("indo de u=%d para v=%d. Pos[u] = %d, pos[v] = %d; n\n", u, v, pos[u], pos[v]);
            dfs(next, n);
            i = -1;
        }
    }
}

bool possible(int n) {
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }
    
    
    next = 1;
    
    memset(mark, 0, sizeof(mark));
    dfs(0, n);
    //printf("next = %d\n", next);
    return next == n;
}

int zip[10];
int test;

bool cmp(int x, int y) {
    return (zip[x] < zip[y]);
}

void solve(int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    
    sort(a, a + n, cmp);
    
    while (true) {
        if (possible(n)) {
            break;
        }
        if (!next_permutation(a, a + n, cmp)) {
            puts("AIDS");
            break;
        }
    }
    printf("Case #%d: ", test);
    
    for (int i = 0; i < n; i++) {
        printf("%d", zip[a[i]]);
    }
    
    printf("\n");
}

int main() {
    int ntests, n, m;
    
    scanf("%d", &ntests);
    for (test = 1; test <= ntests; test++) {
        scanf("%d %d", &n, &m);
        memset(deg, 0, sizeof(deg));
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &zip[i]);
        }
        
        for (int j = 0; j < m; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--, y--;
            
            adj[x][deg[x]++] = y;
            adj[y][deg[y]++] = x;
        }
        
        solve(n);
    }
    
    return 0;
}
