#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#define N 1000000
#define dN 10
#define L 10
using namespace std;
typedef pair<int, int> pii;

int ans[N+dN];
vector<int> G[N+dN];
queue<pii> bfs;
bool vis[N+dN];
char s[L];

void init(){
    for(int i=1; i<=N; i++){
        if(i+1 <= N) G[i].push_back(i+1);
        sprintf(s, "%d", i);
        int l = strlen(s);
        reverse(s, s+l);
        int j;
        sscanf(s, "%d", &j);
        G[i].push_back(j);
    }
    ans[1] = 1;
    bfs.push(make_pair(1, 1));
    vis[1] = true;
    while(!bfs.empty()){
        pii p = bfs.front(); bfs.pop();
        int i = p.first, s = p.second;
        for(int j0=0; j0<(int)G[i].size(); j0++){
            int j = G[i][j0];
            if(vis[j]) continue;
            ans[j] = s+1;
            bfs.push(make_pair(j, ans[j]));
            vis[j] = true;
        }
    }
}

int main(){
    init();
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++){
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", kase, ans[n]);
    }
    return 0;
}
