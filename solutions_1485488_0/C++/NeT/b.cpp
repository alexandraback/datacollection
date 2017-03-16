#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

typedef double real;
typedef long long int64;

#define Eo(x) { cerr << #x << " = " << x << endl; }

#define inf 0x3f3f3f3f

#define maxn (1 << 7)

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = { 0,-1, 0, 1};

int n, m;
int c[maxn][maxn], f[maxn][maxn], h0;

inline bool onb(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool check_move(int x1, int y1, int x2, int y2, int t) {
    int h = h0 - t;
    if(h < f[x1][y1]) h = f[x1][y1];
    if(h         > c[x2][y2] - 50) return false;
    if(f[x1][y1] > c[x2][y2] - 50) return false;
    if(f[x2][y2] > c[x2][y2] - 50) return false;
    if(f[x2][y2] > c[x1][y1] - 50) return false;
    return true;
}
int get_move_start_time(int x1, int y1, int x2, int y2) {
    int t0 = h0 - (c[x2][y2] - 50);
    if(t0 < 0) t0 = 0;
    if(!check_move(x1, y1, x2, y2, t0))
        return inf;
    return t0;
}

int get_move_time(int x1, int y1, int x2, int y2, int t) {
    if(get_move_start_time(x1, y1, x2, y2) > t)
        return inf;
    int h = h0 - t;
    if(h < f[x1][y1]) h = f[x1][y1];
    if(h - f[x1][y1] >= 20) return 10;
    else return 100;
}

int res[maxn][maxn], was[maxn][maxn];
typedef pair<int, int> ipair;
typedef pair<int, ipair> event_t;

set<event_t> all;

void relax(int x, int y, int nt) {
    if(res[x][y] <= nt) return;
    all.erase(make_pair(res[x][y], make_pair(x, y)));
    res[x][y] = nt;
    all.insert(make_pair(res[x][y], make_pair(x, y)));
}

void dfs(int x, int y) {
    relax(x, y, 0);
    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k], ny = y+dy[k];
        if(!onb(nx, ny)) continue;
        if(res[nx][ny] > 0 && get_move_start_time(x, y, nx, ny) == 0)
            dfs(nx, ny);
    }
}
            
void heap_dijk() {
    while(!all.empty()) {
        int x = all.begin()->second.first;
        int y = all.begin()->second.second;
        all.erase(all.begin());
        if(res[x][y] == inf) break;

        for(int k = 0; k < 4; k++) {
            int nx = x+dx[k], ny = y+dy[k];
            if(!onb(nx, ny)) continue;

            int move_start_time = max(res[x][y], get_move_start_time(x, y, nx, ny));
            if(move_start_time == inf) continue;

            relax(nx, ny, move_start_time + get_move_time(x, y, nx, ny, move_start_time));
        }
    }
    all.clear();
}

int main() {
    int t = 1, tc;
    for(scanf("%d", &tc); t <= tc; ++t) {
        printf("Case #%d: ", t);

        scanf("%d%d%d", &h0, &n, &m);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &c[i][j]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &f[i][j]);

        memset(res, 0x3f, sizeof(res));
        memset(was, 0, sizeof(was));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                all.insert(make_pair(res[i][j], make_pair(i, j)));
        dfs(0, 0);

        heap_dijk();

        printf("%d.%d\n", res[n-1][m-1] / 10, res[n-1][m-1] % 10);
    }
    return 0;
}
