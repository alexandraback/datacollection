#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int n, T;
struct {
    vector<int> edge;
}v[1001]; 
bool ok;
char flag[1001];

void dfs(int s) {
    flag[s] = 1;
    for (int i = 0; i < v[s].edge.size(); i++) {
        int cv = v[s].edge[i];
        if (!flag[cv]) dfs(cv);
        else ok = true;
    }
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        scanf("%d", &n);
        ok = false;
        memset(flag, 0, sizeof(flag));
        for (int i = 1; i <= n; i++) v[i].edge.clear();
        for (int i = 1; i <= n; i++) {
            int m;
            scanf("%d", &m);
            int w;
            while (m--) {
                scanf("%d", &w);
                v[w].edge.push_back(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            memset(flag, 0, sizeof(flag));
            dfs(i);
            if (ok) break;
        }    
        printf("Case #%d: ", k);
        if (ok) printf("Yes\n");
        else printf("No\n");
    }

//    system("pause");
    return 0;
}
