#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
#define MP make_pair

const int dir[4][2] = {
    1, 0, -1, 0, 0, -1, 0, 1
};
const double INF = 1e100;
const int MAXN = 128;
double cost[MAXN][MAXN];
int H, N, M;
int F[MAXN][MAXN], C[MAXN][MAXN];

struct Zzz {
    double t;
    int x, y;
    Zzz(){}
    Zzz(double _t, int _x, int _y) 
        : t(_t), x(_x), y(_y){}
    bool operator<(const Zzz& rhs) const{
        return t > rhs.t;
    }
};

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}

double getCost(Zzz tmp, int x, int y) {
    if (C[x][y] - F[x][y] < 50) {
        return INF;
    }
    if (C[tmp.x][tmp.y] - F[x][y] < 50) {
        return INF;
    }
    if (C[x][y] - F[tmp.x][tmp.y] < 50) {
        return INF;
    }
    if (C[x][y] - max(F[x][y] * 1.0, H - tmp.t * 10) >= 50) {
        return 0;
    } else {
        return (50 - (C[x][y] - max(F[x][y] * 1.0, H - tmp.t * 10))) / 10.0;
    }
}

void bfs() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cost[i][j] = INF;
        }
    }
    cost[0][0] = 0;
    priority_queue<Zzz> q;
    q.push(Zzz(0, 0, 0));
    while (!q.empty()) {
        Zzz tmp = q.top(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = tmp.x + dir[i][0];
            int ty = tmp.y + dir[i][1];
            if (!check(tx, ty)) continue;
            double c = getCost(tmp, tx, ty);
            if (c == INF) continue;
            if (tmp.t + c > 1e-6) {
                if (H - (tmp.t + c) * 10 - F[tmp.x][tmp.y] >= 20) {
                    c = c + 1;
                } else {
                    c = c + 10;
                }
            }
            if (cost[tx][ty] > tmp.t + c) {
                cost[tx][ty] = tmp.t + c;
                q.push(Zzz(tmp.t + c, tx, ty));
            }
        }
    }
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int nCase; scanf("%d", &nCase);
    for (int tCase = 1; tCase <= nCase; ++tCase) {
        scanf("%d %d %d", &H, &N, &M);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                scanf("%d", &C[i][j]);
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                scanf("%d", &F[i][j]);
            }
        }
        bfs();
        printf("Case #%d: %.10lf\n", tCase, cost[N-1][M-1]);
    }
    return 0;
}