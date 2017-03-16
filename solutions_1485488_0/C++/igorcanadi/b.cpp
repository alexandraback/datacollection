#include <cstdio>
#include <vector>
#include <set>
#define MAX 100

using namespace std;

double dist[MAX][MAX];
int ceiling[MAX][MAX], floor[MAX][MAX];
int H; // initial water level
int N, M;

int dxy[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

class cmp {
public:
    bool operator () (const pair <int, int>&a, const pair <int, int>& b) {
        if (dist[a.first][a.second] != dist[b.first][b.second]) {
            return dist[a.first][a.second] < dist[b.first][b.second];
        }
        return a < b;
    }
};

set <pair <int, int>, cmp> Q;

void load() {
    scanf("%d%d%d", &H, &N, &M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &ceiling[i][j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &floor[i][j]);
        }
    }
}

double edge(pair <int, int> from, pair <int, int> to, double time) {
    if (to.first < 0 || to.second < 0 || to.first >= N || to.second >= M) {
        return -1.0;
    }
    if (floor[from.first][from.second] + 50 > ceiling[to.first][to.second]) {
        return -1.0;
    }
    if (floor[to.first][to.second] + 50 > ceiling[to.first][to.second]) {
        return -1.0;
    }
    if (floor[to.first][to.second] + 50 > ceiling[from.first][from.second]) {
        return -1.0;
    }

    if (time < 1e-12 && H + 50 <= ceiling[to.first][to.second]) {
        return 0.0;
    }

    double water_level = H - time * 10.0;
    double additional_time = 0.0;
    double floor_to_water = water_level - floor[from.first][from.second];

    if (water_level + 50 > ceiling[to.first][to.second]) {
        additional_time += (water_level + 50.0 - ceiling[to.first][to.second]) / 10.0;
        floor_to_water = ceiling[to.first][to.second] - 50 - floor[from.first][from.second];
    }

    if (floor_to_water + 1e-12 > 20.0) additional_time += 1;
    else additional_time += 10;

    return additional_time;
}

double solve() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            dist[i][j] = -1.0;
        }
    }
    dist[0][0] = 0.0;
    Q.insert(make_pair(0, 0));

    while (Q.size()) {
        pair <int, int> s = *Q.begin();
        Q.erase(Q.begin());

        for (int p = 0; p < 4; ++p) {
            pair <int, int> t(s.first + dxy[p][0], s.second + dxy[p][1]);

            double e = edge(s, t, dist[s.first][s.second]);

            if (e > -0.5 && (dist[t.first][t.second] < -0.5 || dist[t.first][t.second] > dist[s.first][s.second] + e)) {
                Q.erase(t);
                dist[t.first][t.second] = dist[s.first][s.second] + e;
                Q.insert(t);
            }
        }
    }

    return dist[N-1][M-1];
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tt = 1; tt <= T; ++tt) {
        load();
        printf("Case #%d: %lf\n", tt, solve());
    }


    return 0;
}
