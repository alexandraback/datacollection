#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <sstream>

#define mp make_pair
#define INF (0)

using namespace std;

typedef pair<int, int> pii;

int n, m, h;
int f[128][128], c[128][128];

int move(int x1, int y1, int x2, int y2, int h, bool dropping = true) {
    if (x2<0 || x2>=n || y2<0 || y2>=m) return INF;
    if (c[x2][y2] - f[x2][y2] < 50) return INF;
    if (c[x1][y1] - f[x2][y2] < 50) return INF;
    if (c[x2][y2] - f[x1][y1] < 50) return INF;
    if (!dropping && c[x2][y2] - h < 50) return INF;
    int waterDrop = max(0, h+50-c[x2][y2]);
    int newH = h-waterDrop;
    if (newH >= f[x1][y1]+20) return 10+waterDrop;
    return 100+waterDrop;
}

bool st[128][128];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void calcStart() {
    int x, y;
    x = y = 0;
    queue<pii> q;
    q.push(mp(x, y));
    memset(st, 0, sizeof(st));
    st[0][0] = true;
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        x = cur.first;
        y = cur.second;
        for(int i=0; i<4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (move(x, y, nx, ny, h, false) && !st[nx][ny]) {
                st[nx][ny] = true;
                q.push(mp(nx, ny));
            }
        }
    }
    return;
}

int dijkstra(int x, int y) {
    bool u[128][128];
    memset(u, 0, sizeof(u));
    priority_queue<pair<int, pii> > pq;
    pq.push(mp(0, mp(x, y)));
    while(!pq.empty()) {
        pair<int, pii> cur = pq.top();
        pq.pop();
        int t = -cur.first;
        int w = max(0, h-t);
        x = cur.second.first;
        y = cur.second.second;
        if (u[x][y]) continue;
        if (x == n-1 && y == m-1) return t;
        u[x][y] = true;
        for(int i=0; i<4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int moveTime = move(x, y, nx, ny, w);
            if (moveTime && !u[nx][ny]) {
                int newTime = t + moveTime;
                pq.push(mp(-newTime, mp(nx, ny)));
            }
        }
    }
    return -1;
}

int main() {
    int i, j;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int NT, T;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        cin>>h>>n>>m;
        for(i=0; i<n; ++i) {
            for(j=0; j<m; ++j) {
                cin>>c[i][j];
            }
        }
        for(i=0; i<n; ++i) {
            for(j=0; j<m; ++j) {
                cin>>f[i][j];
            }
        }
        calcStart();
        int res=(1<<30);
        for(i=0; i<n; ++i) {
            for(j=0; j<m; ++j) {
                if (st[i][j]) {
                    res = min(res, dijkstra(i, j));
                }
            }
        }
        cout<<"Case #"<<T<<": "<<res/10<<"."<<res%10<<endl;
    }
    return 0;
}
