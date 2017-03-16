#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, F[1005], IF[1005];
int vis[1005];
bool good[1005];
int mm[1005];

void dfs(int now) {
    vis[now] = 1;
    int next = F[now];
    if(good[next]) {
        good[now] = true;
        return;
    }
    if(vis[next] == 1) {
        return;
    }
    dfs(next);
    if(good[next]) {
        good[now] = true;
    }
}

int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        printf("Case #%d: ", cas);
      
        memset(good, false, sizeof(good));
        for(int i = 1; i <= N; i++) {
            scanf("%d", &F[i]);
        }
        for(int i = 1; i <= N; i++) {
            if(i == F[F[i]]) {
                good[i] = true;
            }
        }
        
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= N; i++) {
            mm[i] = 1;
        }
        
        for(int j = 1; j <= N; j++) {
            if(!good[j]) {
                int st = j;
                int now = j;
                int tmp = 1;
                int pre;
            
                while(true) {
                    pre = now;
                    now = F[now];
                    tmp++;
                    if(good[now]) {
                        mm[now] = max(mm[now], tmp);
                        break;
                    }
                    if(now == st) {
                        ans = max(ans, tmp - 1);
                        break;
                    }
                    else {
                        if(vis[now] == j) {
                            break;
                        }
                        vis[now] = j;
                    }
                }
            }
        }
        
        int tmp = 0;
        for(int i = 1; i <= N; i++) {
            if(good[i]) {
                tmp += mm[i];
            }
        }
        ans = max(ans, tmp);
        printf("%d\n", ans);
    }
    return 0;
}