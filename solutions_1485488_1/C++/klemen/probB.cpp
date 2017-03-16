#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int H, N, M;
int C[150][150];
int F[150][150];
int R[150][150];

void printR()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d ", R[i][j]);
        printf("\n");
    }
}

int offset_x[4] = {1, 0, -1, 0};
int offset_y[4] = {0, 1, 0, -1};

void solve(int T)
{
    scanf("%d %d %d", &H, &N, &M);
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            scanf("%d", &C[i][j]);
            R[i][j] = -1;
        }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &F[i][j]);
    
    
    // bfs
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > >pq;
    
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        if (R[cy][cx] < 0) {
            R[cy][cx] = 0;
            pq.push(make_pair(0, make_pair(cy, cx)));
            
            for (int i = 0; i < 4; i++) {
                int ny = cy + offset_y[i];
                int nx = cx + offset_x[i];
                if (ny >= 0 && ny < N &&
                    nx >= 0 && nx < M &&
                    H <= C[ny][nx] - 50 &&
                    F[cy][cx] <= C[ny][nx] - 50 &&
                    F[ny][nx] <= C[ny][nx] - 50 &&
                    F[ny][nx] <= C[cy][cx] - 50)
                    q.push(make_pair(ny, nx));
            }
        }
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            R[i][j] = -1;
    
    // dijkstra
    while (!pq.empty()) {
        int ct = pq.top().first;
        int cy = pq.top().second.first;
        int cx = pq.top().second.second;
        pq.pop();
        
        if (R[cy][cx] < 0) {
            R[cy][cx] = ct;
            
            for (int i = 0; i < 4; i++) {
                int ny = cy + offset_y[i];
                int nx = cx + offset_x[i];
                if (ny >= 0 && ny < N &&
                    nx >= 0 && nx < M &&
                    F[cy][cx] <= C[ny][nx] - 50 &&
                    F[ny][nx] <= C[ny][nx] - 50 &&
                    F[ny][nx] <= C[cy][cx] - 50) {
                    int w = H - (C[ny][nx] - 50); // time we have to wait this square opens
                    int t = max(ct, w); // time when we make the move
                    int nh = H - t; // new water level
                    int sh = nh - F[cy][cx]; // water level in the square
                    if (sh >= 20)
                        t += 10;
                    else
                        t += 100;
                    pq.push(make_pair(t, make_pair(ny, nx)));
                }
            }
        }
    }
    
    int r = R[N - 1][M - 1];
    printf("Case #%d: %d.%d\n", T, r / 10, r % 10);
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++)
        solve(i + 1);
}