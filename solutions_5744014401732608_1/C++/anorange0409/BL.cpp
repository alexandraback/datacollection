#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 55;
int len,N,cnt;
long long M;
bool a[MAXN][MAXN];

bool vis[MAXN];

int two(int x) {
    return 1<<x;
}

void dfs(int u) {
    //if (cnt > M) return;
    if (u == N) {cnt++; return;}
    for (int v = 1; v <= N; v++) if (a[u][v]) {
        if (vis[v]) { cnt = M + 1; break; }
        vis[v] = true;
        dfs(v);
        vis[v] = false;
    }
}

int main() {
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++) {
        printf("Case #%d: ", o);
        memset(a,0,sizeof a);
        cin >> N >> M;
        //int mm = M;
        long long t = 1;
        for (int i = 1; i <= N - 2; i++)
            t *= 2;
       // cout << t << endl;
        if (M > t) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for (int i = 1; i < N; i++)
            for (int j = i + 1; j < N; j++)
                a[i][j] = 1;

        if (M == t) {
            M--;
            a[1][N] = 1;
        }

        int index = 2;
        while (M > 0) {
            if (M & 1)
                a[index][N] = 1;
            M /= 2;
            index++;
        }
            printf("POSSIBLE\n");
            for (int i=1;i<=N;i++) {
                for (int j=1;j<=N;j++)
                    if (a[i][j]) printf("1");
                    else printf("0");
                printf("\n");
            }
//            cnt = 0;
//            memset(vis, 0, sizeof vis);
//            dfs(1);
//            if (cnt == mm)
//                cout << "rock!!";
//            else
//                cout <<"shit "<< mm << " " << cnt << endl;

    }
}
