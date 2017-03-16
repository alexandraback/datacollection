#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cstring>

using namespace std;

const int MAX_SIZE = 110;

int initHeight;
int width, height;
int top[MAX_SIZE][MAX_SIZE];
int bottom[MAX_SIZE][MAX_SIZE];
double dist[MAX_SIZE][MAX_SIZE];
bool reached[MAX_SIZE][MAX_SIZE];

const int DX[4] = {-1, 0, 1, 0};
const int DY[4] = {0, 1, 0, -1};

struct Point {
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int x, y;
    bool operator<(const Point& p) const {
        return false;
    }
};

const double INF_DIST = 1e100;

double computeDist(const Point& p1, const Point& p2) {
    int cellBot = max(bottom[p1.x][p1.y], bottom[p2.x][p2.y]);
    int cellTop = min(top[p1.x][p1.y], top[p2.x][p2.y]);


    if (cellTop - cellBot < 50) {
        return INF_DIST;
    } else if (dist[p1.x][p1.y] == 0 && cellTop - initHeight >= 50) {
        return 0;
    } else {
        double minTime = max(dist[p1.x][p1.y], (initHeight - (cellTop - 50)) / 10.0);
        double curHeight = max(initHeight - minTime * 10.0, 0.0);
        if (curHeight - bottom[p1.x][p1.y] >= 19.9999999) {
            return minTime + 1;
        } else {
            return minTime + 10;
        }
    }
}

void dijkstra() {
    priority_queue<pair<double, Point> > q;
    q.push(make_pair(0, Point(0, 0)));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            dist[x][y] = INF_DIST;
            reached[x][y] = false;
        }
    }
    dist[0][0] = 0;

    while (!q.empty()) {
        Point p = q.top().second;
        q.pop();
        
        if (reached[p.x][p.y]) continue;
        reached[p.x][p.y] = true;
        
        for (int i = 0; i < 4; i++) {
            Point pp(p.x + DX[i], p.y + DY[i]);
            if (pp.x >= 0 && pp.y >= 0 && pp.x < width && pp.y < height) {
                if (!reached[pp.x][pp.y]) {
                    double d = computeDist(p, pp);
                    if (d < dist[pp.x][pp.y]) {
                        dist[pp.x][pp.y] = d;
                        q.push(make_pair(-d, pp));
                    }
                }
            }
        }
    }
}

int main() {
    int nCases;
    scanf("%d", &nCases);
    for (int iCase = 1; iCase <= nCases; iCase++) {
        printf("Case #%i: ", iCase);
        scanf("%d%d%d", &initHeight, &height, &width);
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                scanf("%d", &top[x][y]);
            }
        }
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                scanf("%d", &bottom[x][y]);
            }
        }
        dijkstra();
        printf("%.8f\n", dist[width - 1][height - 1]);
    }
    return 0;
}
