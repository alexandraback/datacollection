#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;


int T, J, P, S, K;
int ans[2000][3];
int vis12[20][20], vis23[20][20], vis13[20][20];
int vis[20][20][20];
int cnt;

void dfs(int i, int j, int k) {
    if(vis[i][j][k] == 1) return;
    if(vis12[i][j] >= K || vis23[j][k] >= K || vis13[i][k] >= K) return;
    vis[i][j][k] = 1;
    vis12[i][j]++;
    vis23[j][k]++;
    vis13[i][k]++;
    ans[cnt][0] = i, ans[cnt][1]=j, ans[cnt][2] = k;
    cnt++;
    dfs(i, j, (k + 1) % S);
    dfs(i, (j + 1) % P, (k + 1) % S);
    dfs((i+1)%J, (j + 1) % P, (k + 1) % S);
}

int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        printf("Case #%d: ", cas);
        scanf("%d%d%d%d", &J, &P, &S, &K);
        memset(vis12, 0, sizeof(vis12));
        memset(vis23, 0, sizeof(vis23));
        memset(vis13, 0, sizeof(vis13));
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        
        for(int i = 0; i < J; i++) {
            for(int j = 0; j < P; j++) {
                for(int k = 0; k < S; k++) {
                    dfs(i, j, k);
                }
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; i++) {
            printf("%d %d %d\n", ans[i][0]+1, ans[i][1]+1, ans[i][2]+1);
        }
    }
    return 0;
}