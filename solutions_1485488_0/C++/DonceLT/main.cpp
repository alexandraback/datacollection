#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_S = 100;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int humanHeight = 50;
const int swimHeight = 20;

int h;
int n, m;

int height[MAX_S][MAX_S][2];

int d[MAX_S][MAX_S];
bool was[MAX_S][MAX_S];

int wait(int an, int am, int bn, int bm, int time) {
    int up = min(height[an][am][0], height[bn][bm][0]);
    int down = max(height[an][am][1], height[bn][bm][1]);
    int target = up - humanHeight;
    if (down > target)
        return -1;
    int wait = (h - time) - target;
    if (wait < 0)
        return 0;
    return wait;
}

int solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            d[i][j] = -1;
            was[i][j] = 0;
        }

    pair<int, int> now;
    now.first = now.second = 0;
    d[0][0] = 0;

    while (now.first != -1) {
        was[now.first][now.second] = true;
        for (int i = 0; i < 4; i++) {
            int a = now.first + dir[i][0];
            int b = now.second + dir[i][1];
            if (a >= 0 && a < n && b >= 0 && b < m) {
                int nowD = d[now.first][now.second];
                int w = wait(now.first, now.second, a, b, nowD);
                if (w != -1) {
                    int newD = nowD + wait(now.first, now.second, a, b, nowD);

                    int add;
                    if (newD == 0)
                        add = 0;
                    else if (h - newD - height[now.first][now.second][1] >= swimHeight)
                        add = 10;
                    else
                        add = 100;
                    newD += add;

                    if (d[a][b] < 0 || newD < d[a][b]) {
                        d[a][b] = newD;
                    }
                }
            }
        }
        //find new
        now.first = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!was[i][j] && d[i][j] >= 0 && (now.first == -1 || (d[i][j] < d[now.first][now.second]))) {
                    now.first = i;
                    now.second = j;
                }
    }
    return d[n-1][m-1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++) {
        cin >> h >> n >> m;
        for (int a = 0; a < 2; a++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    cin >> height[i][j][a];
        int answer = solve();
        cout << "Case #" << t+1 << ": " << answer / 10 << "." << answer % 10 << endl;
    }
    return 0;
}
