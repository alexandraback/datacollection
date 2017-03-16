#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

bool cycle;
vector<int> v[1024];
int used[1024];

void dfs(int nod) {
     used[nod] = 1;
     //printf("%d %d\n", nod, v[nod].size());
     for (int i = 0; i < v[nod].size(); ++i) {
         if (used[v[nod][i]]) {
            cycle = true;
            break;
         } else {
            dfs(v[nod][i]);
         }
     }
}

int main() {
    
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int t, n, m, in[1024];

    
    scanf("%d", &t);
    
    for (int test = 1; test <=t; ++test) {
        memset(in, 0, sizeof(in));
        memset(used, 0, sizeof(used));
        scanf("%d", &n);
        int a;
        for (int i = 1; i <= n; ++i) {
            vector<int>().swap(v[i]);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &in[i]);
          
            for (int j = 1; j <= in[i]; ++j) {
                scanf("%d", &a);
                v[a].push_back(i);
                //printf("--> %d %d %d\n", a, i, v[a].size());
            }
        }
        //printf("fmm -> %d\n", v[3].size());
        cycle = false;
        for (int i = 1; i <= n && !cycle; ++i) {
            if (!in[i]) {
               memset(used, 0, sizeof(used));
               dfs(i);
            }
        }
        if (cycle) {
           printf("Case #%d: Yes\n", test);
        } else {
           printf("Case #%d: No\n", test);
        }
    }
    
    return 0;
}
