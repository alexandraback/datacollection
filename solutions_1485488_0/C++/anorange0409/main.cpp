#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 105;
const int M = 1000000;
const double inf = 1e9;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int cell[N][N], floor[N][N];
bool vis[N][N];
double h, f[N][N];
int n, m;
int qx[M], qy[M];

void solve(){
    cin >> h >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j ++)
            cin >> cell[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j ++){
            cin >> floor[i][j];
            f[i][j] = inf;
        }
    int l = 0, r = 0;
    qx[0] = 0; qy[0] = 0;
    memset(vis, 0, sizeof(vis));
    vis[0][0] = true;
    f[0][0] = 0;
    while (l <= r){
        int x = qx[l], y = qy[l];
        for (int k = 0; k < 4; k++){
            int xx = x + dx[k], yy = y + dy[k];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            double hnow = h - f[x][y] * 10;
            if (floor[x][y] + 50 > cell[xx][yy]) continue;
            if (floor[xx][yy] + 50 > cell[xx][yy]) continue;
            if (floor[xx][yy] + 50 > cell[x][y]) continue;
            double t;
            if (hnow + 50 <= cell[xx][yy]) t = 0;
            else t = (hnow + 50 - cell[xx][yy]) / 10.0;
            double del;
            hnow -= t * 10;
            if (hnow == h) del = 0; else {
            if (hnow - floor[x][y] >= 20) del = 1;
                else del = 10;
            }

            if (f[x][y] + del + t < f[xx][yy]){
                f[xx][yy] = f[x][y]+ del + t;
                if (!vis[xx][yy]){
                    ++r; qx[r] = xx; qy[r] = yy;
                    vis[xx][yy] = true;
                }
            }
        }
        l++; vis[x][y] = false;
    }
    printf("%.7lf\n", f[n-1][m-1]);
}

int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("small.out", "w", stdout);
    int T; cin >> T;
    for (int i = 1; i <= T; i++){
        printf("Case #%d: " , i);
        solve();
    }

}
