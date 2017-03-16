//#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

double besttime[100][100];
int n, m, h, fl[100][100], ce[100][100];
queue< pair<int, int> > q;

void dfs(int x, int y) {
    //cout << x << ' ' << y << endl;
    besttime[x][y] = 0;
    q.push(make_pair(x, y));
    if (ce[x][y] - fl[x+1][y] >= 50 && ce[x+1][y] - max(h, max(fl[x][y], fl[x+1][y])) >= 50)
        dfs(x+1, y);
    if (ce[x][y] - fl[x][y+1] >= 50 && ce[x][y+1] - max(h, max(fl[x][y], fl[x][y+1])) >= 50)
        dfs(x, y+1);
}

void relax(int x0, int y0, double time, int x1, int y1) {
    double time1;
    if (!(ce[x0][y0] - fl[x1][y1] >= 50 && ce[x1][y1] - max(fl[x0][y0], fl[x1][y1]) >= 50)) return;
    double dt = max(0., ((h-time*10)+50-ce[x1][y1])/10);
    time1 = time + dt + (h-(time+dt)*10 - fl[x0][y0] >= 20 ? 1 : 10);
    if (besttime[x1][y1] > time1) {
        q.push(make_pair(x1, y1));
        besttime[x1][y1] = time1;
    }
    //cout << x0 << y0 << ' ' << x1 << y1 << ' ' << time << ' ' << time1 << endl;
}

void solve(int t) {
    cin >> h >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> ce[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> fl[i][j];
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            besttime[i][j] = 1000000000;
    dfs(0, 0);
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        int x = v.first, y = v.second;
        double time = besttime[x][y];
        relax(x, y, time, x-1, y);
        relax(x, y, time, x+1, y);
        relax(x, y, time, x, y-1);
        relax(x, y, time, x, y+1);
    }
    cout.precision(20);
    cout << fixed << "Case #" << t << ": " << besttime[n-1][m-1] << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve(i+1);

    return 0;
}
