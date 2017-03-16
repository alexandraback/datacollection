#include <stdio.h>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<double,pii> pdii;

const int N = 100;
int cl[N][N], fl[N][N];
double dist[N][N];

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int T = 1; T <= cases; ++T) {
        int H, N, M;
        scanf("%d%d%d", &H, &N, &M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                scanf("%d", &cl[i][j]);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                scanf("%d", &fl[i][j]), dist[i][j] = 1e10;
        priority_queue<pdii, vector<pdii>, greater<pdii> > h;
        dist[0][0] = 0;
        h.push(make_pair(0.0, pii(0,0)));
        while (!h.empty()) {
            double t = h.top().first;
            int x = h.top().second.first;
            int y = h.top().second.second;
            h.pop();
            if (t > dist[x][y]+1e-6) continue;
            for (int d = 0; d < 4; ++d) {
                int xx = (int[]){0,-1,0,1}[d] + x;
                int yy = (int[]){1,0,-1,0}[d] + y;
                if (unsigned(xx) < N && unsigned(yy) < M) {
                    if (cl[xx][yy] - fl[x][y] < 50 ||
                        cl[x][y] - fl[xx][yy] < 50 ||
                        cl[xx][yy] - fl[xx][yy] < 50 ||
                        cl[xx][yy] - H < 50) continue;
                    if (0 < dist[xx][yy]) {
                        dist[xx][yy] = 0;
                        h.push(make_pair(0, pii(xx,yy)));
                    }
                }
            }
        }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (dist[i][j] < 1e10)
                    h.push(make_pair(dist[i][j], pii(i,j)));
        while (!h.empty()) {
            double t = h.top().first;
            int x = h.top().second.first;
            int y = h.top().second.second;
            h.pop();
            if (t > dist[x][y]+1e-6) continue;
            for (int d = 0; d < 4; ++d) {
                int xx = (int[]){0,-1,0,1}[d] + x;
                int yy = (int[]){1,0,-1,0}[d] + y;
                if (unsigned(xx) < N && unsigned(yy) < M) {
                    if (cl[xx][yy] - fl[x][y] < 50 ||
                        cl[x][y] - fl[xx][yy] < 50 ||
                        cl[xx][yy] - fl[xx][yy] < 50) continue;
                    double w = max((H-(cl[xx][yy]-50)) / 10.0 - t, 0.0);
                    w += H-fl[x][y]-(t+w)*10 >= 20 ? 1 : 10;
                    w += dist[x][y];
                    if (w < dist[xx][yy]) {
                        dist[xx][yy] = w;
                        h.push(make_pair(w, pii(xx,yy)));
                    }
                }
            }
        }
        printf("Case #%d: %lf\n", T, dist[N-1][M-1]);
    }
}
