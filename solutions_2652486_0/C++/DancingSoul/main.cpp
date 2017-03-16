#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int cas, CAS, r, n, m, k, i, j, found, a[20], ans[20], fd;

void dfs1(int k, int t){
    if (k > n){
        if (t == 1) fd = 1;
        return;
    }
    dfs1(k + 1, t);
    if (t % ans[k] == 0) dfs1(k + 1, t / ans[k]);
}
int check(){
    for (int i = 1; i <= k; i++){
        fd = 0;
        dfs1(1, a[i]);
        if (!fd) return 0;
    }
    return 1;
}
void dfs(int k, int low){
    if (k > n){
        if (check()) found = 1;
        return;
    }
    for (int i = low; i <= m; i++){
        ans[k] = i;
        dfs(k + 1, i);
        if (found) return;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &CAS);
    for (cas = 1; cas <= CAS; cas++){
        scanf("%d%d%d%d", &r, &n, &m, &k);
        printf("Case #%d:\n", cas);
        for (i = 1; i <= r; i++){
            for (j = 1; j <= k; j++) scanf("%d", &a[j]);
            found = 0;
            dfs(1, 2);
            if (found){
                for (j = 1; j <= n; j++) printf("%d", ans[j]);
                puts("");
            }else{
                for (j = 1; j <= n; j++) putchar('1');
                puts("");
            }
        }
    }
}
