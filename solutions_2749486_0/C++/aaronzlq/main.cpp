#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long llg;

const int N = 1005;
int T, dx, dy, d[N][N];
char pre[N][N];
bool val(int tx, int ty) {
    if(tx<0 || tx>=N)  return  false;
    if(ty<0 || ty>=N)  return  false;
    return  true;
}
void bfs() {
    pair <int, int> u, v;
    int tx, ty;
    queue < pair<int, int> > q;
    q.push(make_pair(500, 500));
    while(!q.empty()) {
        if(d[dx][dy] != -1)  return;
        u = q.front(); q.pop();
        int td = d[u.first][u.second]+1;
        tx = u.first+td; ty = u.second;
        if(val(tx, ty) && d[tx][ty] == -1) {
            q.push(make_pair(tx, ty));
            d[tx][ty] = td;
            pre[tx][ty] = 'E';
        }
        tx = u.first-td; ty = u.second;
        if(val(tx, ty) && d[tx][ty] == -1) {
            q.push(make_pair(tx, ty));
            d[tx][ty] = td;
            pre[tx][ty] = 'W';
        }
        tx = u.first; ty = u.second+td;
        if(val(tx, ty) && d[tx][ty] == -1) {
            q.push(make_pair(tx, ty));
            d[tx][ty] = td;
            pre[tx][ty] = 'N';
        }
        tx = u.first; ty = u.second-td;
        if(val(tx, ty) && d[tx][ty] == -1) {
            q.push(make_pair(tx, ty));
            d[tx][ty] = td;
            pre[tx][ty] = 'S';
        }
    }
}
void printTrace(int dx, int dy) {
    if(dx==500 && dy==500)  return;
    if(pre[dx][dy]=='E')  printTrace(dx-d[dx][dy], dy);
    if(pre[dx][dy]=='W')  printTrace(dx+d[dx][dy], dy);
    if(pre[dx][dy]=='N')  printTrace(dx, dy-d[dx][dy]);
    if(pre[dx][dy]=='S')  printTrace(dx, dy+d[dx][dy]);
    printf("%c", pre[dx][dy]);
}
void run() {
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++) {
        scanf("%d%d", &dx, &dy);
        dx += 500; dy += 500;
        memset(d, -1, sizeof(d));
        memset(pre, 0, sizeof(pre));
        d[500][500] = 0;
        bfs();
        printf("Case #%d: ", Case);
        printTrace(dx, dy);
        printf("\n");
    }
}

int main() {
    freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	run();
	return  0;
}















