#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10;
struct node {
    int x,y;
    node(){}
    node(int xx, int yy ){
        x=xx;y=yy;
    }
};
vector<node>L;
int len,N,M,cnt;
bool vis[MAXN];
bool a[MAXN][MAXN];

int two(int x) {
    return 1<<x;
}

void dfs(int u) {
    if (cnt > M) return;
    if (u == N) {cnt++; return;}
    for (int v = 1; v <= N; v++) if (a[u][v]) {
        if (vis[v]) { cnt = M + 1; break; }
        vis[v] = true;
        dfs(v);
        vis[v] = false;
    }
}

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++) {
        printf("Case #%d: ", o);
        memset(a,0,sizeof a);
        cin >> N >> M;
        L.clear();
        for (int i=1;i<N;i++)
        for (int j=2;j<=N;j++) {
            if (i==j) continue;
            L.push_back(node(i,j));
        }
        len = L.size();
        for (int p = 0; p < two(len); p++) {
            for (int i = 0; i < L.size(); i++)
                if ( (p & two(i)) > 0 )
                    a[L[i].x][L[i].y] = 1;
                else
                    a[L[i].x][L[i].y] = 0;
            cnt = 0;
            memset(vis,0,sizeof vis);
            dfs(1);
            if (cnt == M)
                break;
        }
        if (cnt == M) {
            printf("POSSIBLE\n");
            for (int i=1;i<=N;i++) {
                for (int j=1;j<=N;j++)
                    if (a[i][j]) printf("1");
                    else printf("0");
                printf("\n");
            }
        } else {
            printf("IMPOSSIBLE\n");
        }
    }
}
