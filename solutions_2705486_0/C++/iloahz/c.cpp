#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1125100;
const int MAXS = 26;
const int MAXL = 4005;

int n;
struct Trie{
    Trie* son[MAXS];
    bool flag;
    void init(){
        for (int i = 0;i < MAXS;i++) son[i] = NULL;
        flag = false;
    }
}   t[MAXN], *rt;
int tot;
char s[MAXL];

void ins(char *s){
    Trie *cur = rt;
    for (int i = 0;s[i];i++){
        int id = s[i] - 'a';
        if (!cur->son[id]){
            cur->son[id] = &t[tot++];
            cur->son[id]->init();
        }
        cur = cur->son[id];
    }
    cur->flag = true;
}

void prep(){
    freopen("dict.txt", "r", stdin);
//    freopen("dict1.txt", "r", stdin);
    tot = 0;
    rt = &t[tot++];
    rt->init();
    while (~scanf("%s", s)){
        ins(s);
    }
//    printf("tot = %d\n", tot);
}

void init(){
    scanf("%s", s);
}

int f[MAXN][5];

void dfs(Trie* x, int y, int z, int k){
//    printf("x->flag = %d\n", x->flag);
    if (x->flag){
//        printf("%d %d %d\n", y, z - 1, k);
        f[y][z - 1] = min(f[y][z - 1], k);
    }
    if (s[y] == 0) return;
    int id = s[y] - 'a';
    if (x->son[id]){
//        printf("go %c\n", s[y]);
        dfs(x->son[id], y + 1, min(z + 1, 5), k);
    }
    if (z >= 5){
        for (int i = 0;i < MAXS;i++){
            if (x->son[i]){
                dfs(x->son[i], y + 1, 1, k + 1);
            }
        }
    }
}

void work(){
    n = strlen(s);
    for (int i = 0;i <= n;i++){
        for (int j = 0;j < 5;j++){
            f[i][j] = n + 1;
        }
    }
    f[0][4] = 0;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < 5;j++){
            if (f[i][j] <= n){
//                printf("f[i][j] %d %d %d\n", i, j, f[i][j]);
                dfs(rt, i, j + 1, f[i][j]);
            }
        }
    }
//    printf("%d\n", f[4][4]);
    int ans = n + 1;
    for (int i = 0;i < 5;i++){
        ans = min(ans, f[n][i]);
    }
    printf("%d\n", ans);
}

int main(){
    int T, t = 0;
    prep();
//    freopen("c.in", "r", stdin);
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
//    freopen("A-large.in", "r", stdin);
//    freopen("A-large.out", "w", stdout);
    scanf("%d", &T);
    while (T--){
        init();
        printf("Case #%d: ", ++t);
        work();
    }
    return 0;
}
