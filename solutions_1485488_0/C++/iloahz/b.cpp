#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const double EPS = 1e-8;
const double INF = 1e10;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int h, n, m;
int cel[MAXN][MAXN];
int flr[MAXN][MAXN];
double ans;
bool fil[MAXN][MAXN];
struct node{
    int x, y;
    node(int tx, int ty){
        x = tx;
        y = ty;
    }
};
double dist[MAXN][MAXN];
bool inq[MAXN][MAXN];

void init(){
    scanf("%d%d%d", &h, &n, &m);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            scanf("%d", &cel[i][j]);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            scanf("%d", &flr[i][j]);
}

bool range(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

double go(double ht, int x, int y, int z){
    int nx = x + dx[z];
    int ny = y + dy[z];
    //constraints 1
    if (ht + 50 > cel[nx][ny] + EPS) return -1;
    if (flr[x][y] + 50 > cel[nx][ny] + EPS) return -1;
    if (flr[nx][ny] + 50 > cel[nx][ny] + EPS) return -1;
    //constraints 2
    if (flr[nx][ny] + 50 > cel[x][y] + EPS) return -1;
    if (flr[x][y] + 20 > ht) return 10;
        else return 1;
}

bool update(int x, int y, int z){
    int nx = x + dx[z];
    int ny = y + dy[z];
    //printf("%d %d %d %d\n", x, y, nx, ny);
    if (flr[x][y] + 50 > cel[nx][ny] + EPS) return false;
    if (flr[nx][ny] + 50 > cel[nx][ny] + EPS) return false;
    if (flr[nx][ny] + 50 > cel[x][y] + EPS) return false;
    double t = dist[x][y];
    double ht = h - t * 10;
    if (ht + 50 > cel[nx][ny] + EPS){
        if (cel[nx][ny] + EPS < 50) return false;
        t += (ht - cel[nx][ny] + 50) / 10;
        ht = h - t * 10;
    }
    bool flag = false;
    double opt = t + go(ht, x, y, z);
    if (opt > 0){
        if (dist[nx][ny] < 0 || dist[nx][ny] > opt){
            dist[nx][ny] = opt;
            flag = true;
        }
    }
    return flag;
}

void bfs(int x, int y){
    queue<node> q;
    memset(inq, false, sizeof(inq));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            dist[i][j] = -1;
    dist[x][y] = 0;
    q.push(node(x, y));
    inq[x][y] = true;
    while (!q.empty()){
        node tmp = q.front();
        q.pop();
        int x = tmp.x;
        int y = tmp.y;
        inq[x][y] = false;
        if (x == n && y == m){
            ans = min(ans, dist[x][y]);
            return;
        }
        for (int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (range(nx, ny)){
                if (update(x, y, i)){
                    if (!inq[nx][ny]){
                        q.push(node(nx, ny));
                        inq[nx][ny] = true;
                    }
                }
            }
        }
    }
}

void floodfill(int x, int y){
    bfs(x, y);
    fil[x][y] = true;
    for (int i = 0;i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (range(nx, ny)){
            if (!fil[nx][ny] && go(h, x, y, i) > 0){
                floodfill(nx, ny);
            }
        }
    }
}

void work(){
    ans = INF;
    memset(fil, false, sizeof(fil));
    floodfill(1, 1);
}

int main(){
#ifdef ILOAHZ
    //freopen("b.in", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
#endif
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        init();
        work();
        printf("Case #%d: %.8f\n", ++t, ans);
    }
    return 0;
}
