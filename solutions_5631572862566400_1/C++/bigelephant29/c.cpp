#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 1000 + 10;

int nxt[MAX];
bool vis[MAX];
vector<int> v[MAX];

int rd(int x, int len, const int ban){
    int siz = (int)v[x].size(), ans = len;
    for(int i = 0 ; i < siz ; i++){
        if(v[x][i] != ban) ans = max(ans, rd(v[x][i], len+1, ban));
    }
    return ans;
}

int calc(int x, int y){
    return rd(x, 1, y) + rd(y, 1, x);
}

int dfs(int x, const int y, int len){
    if(nxt[x] == y) return len;
    if(vis[nxt[x]]) return -1;
    vis[x] = true;
    int tmp = dfs(nxt[x], y, len+1);
    vis[x] = false;
    return tmp;
}

int main(){
    int TN;
    scanf("%d", &TN);
    for(int casen = 1 ; casen <= TN ; casen++){
        printf("Case #%d: ", casen);
        int n, ans = 0;
        scanf("%d", &n);
        for(int i = 1 ; i <= n ; i++){
            int t;
            scanf("%d", &t);
            nxt[i] = t;
            v[nxt[i]].push_back(i);
        }
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            if(nxt[i] > i && nxt[ nxt[i] ] == i){
                sum += calc(i, nxt[i]);
            }
        }
        ans = sum;
        for(int i = 1 ; i <= n ; i++){
            memset(vis, 0, sizeof(vis));
            ans = max(ans, dfs(i, i, 1));
        }
        printf("%d\n", ans);
        for(int i = 1 ; i <= n ; i++) v[i].clear();
    }
    return 0;
}
