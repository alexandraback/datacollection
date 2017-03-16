#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

int x, y;

struct p_t {
    int x;
    int y;
    int step;
    int pre;
};

p_t p[210 * 210 * 210];
int val[210][210][2222];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void get_path(int c) {
    std::vector<p_t> path;
    while (c != -1) {
        path.push_back(p[c]);
        c = p[c].pre;
        //printf("ok? %d", c);
    }

    for (int i = path.size() - 2; i >= 0; i--) {
        if (path[i].x == path[i + 1].x) {
            if (path[i].y >= path[i + 1].y) {
                printf("N");
            } else
                printf("S");
        } else {
            if (path[i].x >= path[i + 1].x) {
                printf("E");
            } else
                printf("W");
        }
    }
    printf("\n");
}

void bfs() {
    memset(val, 0, sizeof(val));

    int cur = 0;
    int tail = 1;
    while (1) {
        if (cur == tail) break;
        p_t& curp = p[cur++];
        //printf("%d ", cur);
        //printf("%d %d %d\n", curp.x, curp.y, curp.step);
        //if (curp.x == 0 && curp.y == 0 && curp.step == 0)
        //    break;
        if (curp.x == x && curp.y == y)
            break;

        for (int i = 0; i < 4; i++) {
            int nx = curp.x + dx[i] * (curp.step + 1);
            int ny = curp.y + dy[i] * (curp.step + 1);

            if (nx < 0 || nx > 200 || ny < 0 || ny > 200)
                continue;
            if (val[nx][ny][curp.step + 1] == 0) {
                val[nx][ny][curp.step + 1] = 1;
                p[tail].x = nx;
                p[tail].y = ny;
                p[tail].step = curp.step + 1;
                p[tail].pre = cur - 1;
                tail++;
            }
        }
    }
    get_path(cur - 1);
}

void init() {
    p[0].x = 100;
    p[0].y = 100;
    p[0].step = 0;
    p[0].pre = -1;
    val[100][100][0] = 1;
}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    //freopen("test.dat", "r", stdin);
    freopen("answer", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int idx = 1; idx <= t; idx++) {
        printf("Case #%d: ", idx);
        scanf("%d %d", &x, &y);

        x += 100;
        y += 100;

        init();
        bfs();
    }
}
