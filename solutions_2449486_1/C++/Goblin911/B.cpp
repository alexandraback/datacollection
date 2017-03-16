#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int mv[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
struct Node {
    int x, y;
    int height;
    Node(int x, int y, int height = 0) {
        this->x = x;
        this->y = y;
        this->height = height;
    }
    bool operator < (Node t) const {
        return height > t.height;
    }
};

priority_queue<Node> p;
int n, m, a[102][102], b[102][102];
bool v[102][102], f[102][102];
void init() {
    //while (!p.empty()) p.pop();
    memset(a, 0 ,sizeof(a));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            b[i][j] = a[i][j];
            a[i][0] = max(a[i][0], a[i][j]);
            a[0][j] = max(a[0][j], a[i][j]);
            a[i][j] = 100;
            //p.push(Node(i, j, a[i][j]));
        }
    memset(v, 0, sizeof(v));
}

/*bool check(int x, int y) {
    bool res = false;
    for (int i = 1; i <= n; i++) if (a[x][y] < a[i - 1][x]) 
}*/

void solve() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            a[i][j] = min(a[i][j], a[i][0]);
            a[i][j] = min(a[i][j], a[0][j]);
            if (a[i][j] > b[i][j]) {
                printf("NO\n");
                return;
            }
        }
    printf("YES\n");
/*

    while (!p.empty()) {
        Node t = p.top();p.pop(); 
        if (!check(t.x, t.y)) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");*/
}

int main() {
//    freopen("data.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        init();
        solve();
    }
}

