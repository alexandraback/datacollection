#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

#define INF 10000000

int V, H, W;
int C[110][110], F[110][110], dist[110][110];

int DY[] = { -1, 0, 1, 0 };
int DX[] = { 0, 1, 0, -1 };

int movetime(int x, int y, int nx, int ny, int t) {
    if (!(F[y][x] <= C[ny][nx]-50 && F[ny][nx] <= C[ny][nx]-50 && F[ny][nx] <= C[y][x]-50)) return INF;
    if (t == 0 && V <= C[ny][nx]-50) return 0;
    int ft = max(t, V - (C[ny][nx]-50));
    return (V - ft >= F[y][x]+20) ? ft + 10 : ft + 100;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int caseno = 1; caseno <= T; caseno++) {
        scanf("%d%d%d", &V, &H, &W);
        for (int y = 0; y < 110; y++) for (int x = 0; x < 110; x++) {
            C[y][x] = F[y][x] = 0;
            dist[y][x] = INF;
        }
        for (int y = 1; y <= H; y++) for (int x = 1; x <= W; x++) scanf("%d", &C[y][x]);
        for (int y = 1; y <= H; y++) for (int x = 1; x <= W; x++) scanf("%d", &F[y][x]);

        priority_queue<pair<int,pair<int,int> > > Q;
        Q.push(make_pair(0, make_pair(1, 1)));
        dist[1][1] = 0;

        while (!Q.empty()) {
            int mydist = -Q.top().first;
            int x = Q.top().second.first, y = Q.top().second.second;
            Q.pop();
            if (mydist != dist[y][x]) continue;
            for (int d = 0; d < 4; d++) {
                int nx = x + DX[d], ny = y + DY[d];
                int m = movetime(x, y, nx, ny, dist[y][x]);
                if (m < dist[ny][nx]) {
                    dist[ny][nx] = m;
                    Q.push(make_pair(-m, make_pair(nx, ny)));
                }
            }
        }

        printf("Case #%d: %d.%d\n", caseno, dist[H][W]/10, dist[H][W]%10);
    }
    return 0;
}
