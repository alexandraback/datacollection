#include<iomanip>
#include<queue>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int l[101][101];
int h[101][101];
int ans, n, m, hh;
double f[101][101];
bool visited[101][101];

struct Combine {
    double value;
    int  x, y;
    Combine(double v, int x, int y) : value(v), x(x), y(y) {}
    bool operator<(const Combine &b) const {
        return value > b.value;
    }
};

void input() {
    scanf("%d%d%d", &hh, &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", h[i] + j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", l[i] + j);
}

vector< vector<int> > kNextMove = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};

bool legal(int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

double get_time(double arrive, int l, int h, int nl, int nh) {
    double waterLevel = hh - 10 * arrive;
    if (nh - l < 50) return 1e100;
    if (h - nl < 50) return 1e100;
    if (nh - nl < 50) return 1e100;
    double spend;
    if (nh - waterLevel >= 50) {
        spend = 0;
    } else {
        spend = (50 - (nh - waterLevel)) / 10;
        waterLevel = nh - 50;
    }
    if (arrive + spend > 1e-6)
        spend += waterLevel - l >= 20 ? 1 : 10;
    return spend;
}

template<class T>
void get_time_wrapper(T &q, int x, int y, int nx, int ny) {
    if (not legal(nx, ny)) return;
    double spend = get_time(f[x][y], l[x][y], h[x][y], l[nx][ny], h[nx][ny]);
    if (f[nx][ny] > f[x][y] + spend) {
        f[nx][ny] = f[x][y] + spend;
        q.push(Combine(f[nx][ny], nx, ny));
    }
}


void work() {
    priority_queue<Combine> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            f[i][j] = 1e100;
    f[0][0] = 0;
    memset(visited, 0, sizeof(visited));
    q.push(Combine(f[0][0], 0, 0));
    while (not q.empty()) {
        int x = q.top().x;
        int y = q.top().y;
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        for (const auto & i : kNextMove)
            get_time_wrapper(q, x, y, x + i[0], y + i[1]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    cout << setiosflags(ios::fixed);
    cout << setprecision(6);
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " ;
        input();
        work();
        cout << f[n - 1][m - 1] << endl;
    }

}
