#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<cctype>
#include<climits>
#include<algorithm>
#include<complex>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long LL;

const int MaxN = 100 + 5, MaxM = 100 + 5;
const int oo = 0x7fffffff / 3;

int T, H, N, M, waitTime;
bool vis[MaxN][MaxM];
int up[MaxN][MaxM], down[MaxN][MaxM];
int dis[MaxN][MaxM];

struct Node {
    int x, y;
    Node() {}
    Node(int _x, int _y): x(_x), y(_y) {}
};
queue<Node> Q;

bool ok(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

bool reachable(int nx, int ny, int tx, int ty, int downSpeed) {
    int cntLever = max(0, H - dis[nx][ny] * downSpeed);
    if (cntLever <= up[tx][ty] - 50 && down[nx][ny] <= up[tx][ty] - 50 &&
        down[tx][ty] <= up[tx][ty] - 50 && down[tx][ty] <= up[nx][ny] - 50) {
        waitTime = 0; return true;
    }
    else {
        if (downSpeed == 0) return false;
        if (down[nx][ny] <= up[tx][ty] - 50 &&
        down[tx][ty] <= up[tx][ty] - 50 && down[tx][ty] <= up[nx][ny] - 50) {
            waitTime = cntLever - (up[tx][ty] - 50);
            return true;
        }else return false;
    }
}

void spfa(int downSpeed, int moveFast, int moveSlow) {
    Node now; int nx, ny;
    while (!Q.empty()) {
        now = Q.front(); Q.pop();
        nx = now.x; ny = now.y; vis[nx][ny] = false;
        for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy)
            if (abs(dx + dy) == 1 && ok(nx + dx, ny + dy)) {
                int tx = nx + dx, ty = ny + dy;
                if (reachable(nx, ny, nx + dx, ny + dy, downSpeed)) {
                    int cntLever = max(0, H - (dis[nx][ny] + waitTime) * downSpeed);
                    int cost = waitTime;
                    if (cntLever - down[nx][ny] >= 20) 
                        cost += moveFast;
                    else cost += moveSlow;
                    if (dis[nx][ny] + cost < dis[tx][ty]) {
                        dis[tx][ty] = dis[nx][ny] + cost;
                        if (!vis[tx][ty]) {
                            vis[tx][ty] = true;
                            Q.push(Node(tx, ty));
                        }
                    }
                }
            }
    }
}

int main() {

    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    scanf("%d", &T);
    for (int te = 1; te <= T; ++te) {
        scanf("%d%d%d", &H, &N, &M);
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                scanf("%d", &up[i][j]);
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                scanf("%d", &down[i][j]);
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j) dis[i][j] = oo;
        dis[1][1] = 0;
        Q.push(Node(1, 1));
        memset(vis, false, sizeof(vis)); vis[1][1] = true;
        spfa(0, 0, 0);
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                if (dis[i][j] == 0) {
                    Q.push(Node(i, j)); vis[i][j] = true;
                }
        spfa(1, 10, 100);
        printf("Case #%d: %.1lf\n", te, dis[N][M] / 10.0);
    }

    return 0;

}

