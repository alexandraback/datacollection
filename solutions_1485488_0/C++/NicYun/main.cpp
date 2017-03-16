#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); ++i)

const int N = 101;
const double EPS = 1e-6;

int T, n, m, h, c[N][N], f[N][N];

struct node{
    int x, y;
    double time;
    bool operator < (const node & b) const{
        return time > b.time;
    }
};

priority_queue<node> q;
bool used[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool can_move(int x, int y, int i, int j, double hi)
{
    if(c[i][j] - hi < 50 || c[i][j] - f[i][j] < 50 || c[i][j] - f[x][y] < 50)
        return false;
    if(c[x][y] - f[i][j] < 50) return false;
    return true;
}

void init()
{
    while(!q.empty()) q.pop();
    memset(used, 0, sizeof(used));
    vector<node> tq;
    tq.push_back(node{0, 0, 0.0});
    used[0][0] = 1;
    size_t r = 0;
    while(r < tq.size()){
        node now = tq[r];
        REP(k, 4){
            int i = now.x + dx[k];
            int j = now.y = dy[k];
            if(i >= 0 && i < n && j >= 0 && j < m){
                if(!used[i][j] && can_move(now.x, now.y, i, j, h)){
                    used[i][j] = 1;
                    tq.push_back(node{i, j, 0.0});
                }
            }
        }
        r++;
    }
    REP(i, tq.size()) q.push(tq[i]);
}

double bfs()
{
    init();
    memset(used, 0, sizeof(used));
    while(!q.empty()){
        node now = q.top();
        q.pop();
        if(now.x == n - 1 && now.y == m - 1) return now.time;
        if(used[now.x][now.y]) continue;
        used[now.x][now.y] = 1;
        REP(k, 4){
            int i = now.x + dx[k];
            int j = now.y + dy[k];
            if(i >= 0 && i < n && j >= 0 && j < m){
                double hi = max(0.0, h - now.time * 10);
                double cost = 0.0;
                if(c[i][j] - hi < 50){
                    cost = (double)(hi - c[i][j] + 50) / 10;
                    hi = c[i][j] - 50;
                }
                if(can_move(now.x, now.y, i, j, hi)){
                    if(hi - f[now.x][now.y] >= 20 - EPS) cost += 1;
                    else cost += 10;
                    q.push(node{i, j, now.time + cost});
                }
            }
        }
    }
    exit(-1);
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    scanf("%d", &T);
    REP(t, T){
        scanf("%d %d %d", &h, &n, &m);
        REP(i, n) REP(j, m) scanf("%d", &c[i][j]);
        REP(i, n) REP(j, m) scanf("%d", &f[i][j]);
        double res = bfs();
        printf("Case #%d: %.1lf\n", t + 1, res);
    }
    return 0;
}
