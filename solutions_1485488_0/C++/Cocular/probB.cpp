#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

double H;
int n, m;
double C[200][200], F[200][200];

struct node_t
{
    double time;
    int x, y;
    node_t() {};
    node_t(double time, int x, int y): time(time), x(x), y(y) {};
};
bool operator>(const node_t &a, const node_t &b)
{
    return a.time > b.time;
}
double dist[200][200];
bool   sure[200][200];


const int dx[4] = { 0, 0, 1, -1};
const int dy[4] = {-1, 1, 0,  0};

bool valid(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

double work(void)
{
    cin >> H >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> C[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> F[i][j];

    memset(sure, 0, sizeof(sure));
    for (int i = 0; i < n; ++i)
        for (int j = 0 ; j < m; ++j)
            dist[i][j] = INT_MAX;

    priority_queue< node_t, vector<node_t>, greater<node_t> > Q;
    dist[0][0] = 0;
    Q.push(node_t(0, 0, 0));

    while (!sure[n - 1][m - 1]) {
        node_t now = Q.top();
        Q.pop();
        while (sure[now.x][now.y]) {
            now = Q.top();
            Q.pop();
        }
        int nx = now.x;
        int ny = now.y;
        sure[nx][ny] = true;
        // fprintf(stderr, "current node: %d %d\n", nx, ny);

        for (int k = 0; k < 4; ++k) {
            int tx = now.x + dx[k];
            int ty = now.y + dy[k];
            if (valid(tx, ty)) {
                if (C[tx][ty] - F[nx][ny] >= 50 &&
                    C[tx][ty] - F[tx][ty] >= 50 &&
                    C[nx][ny] - F[tx][ty] >= 50) {
                    double time;
                    if (now.time == 0. && C[tx][ty] - H >= 50)
                        time = 0;
                    else {
                        time = max(now.time, (H - (C[tx][ty] - 50.)) / 10.);
                        if (H - 10 * time - F[nx][ny] >= 20)
                            time += 1;
                        else
                            time += 10;
                    }
                    if (time < dist[tx][ty]) {
                        dist[tx][ty] = time;
                        Q.push(node_t(time, tx, ty));
                    }
                }
            }
        }
    }

    return dist[n - 1][m - 1];
}

int main(void)
{
    freopen("probB.in", "r", stdin);
    int __;
    cin >> __;
    for (int _ = 1; _ <= __; ++_) {
        printf("Case #%d: %.10f\n",_ ,  work());
    }
}
