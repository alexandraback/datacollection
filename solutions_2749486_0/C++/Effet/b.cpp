#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define MAX 4000
#define TOMOVE 2000

struct Node {
    int x, y, len;
};

Node pre[MAX][MAX];

int dir[4][2] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

char str[MAX];
bool vis[MAX][MAX];
int x, y;

void print(Node u) {
    // printf("x,y: %d %d\n", u.x, u.y);
    if (u.x == TOMOVE && u.y == TOMOVE)
        return ;
    Node pp = pre[u.x][u.y];
    print(pp);
    if (pp.x == u.x) {
        if (pp.y > u.y) putchar('S');
        else putchar('N');
    } else {
        if (pp.x > u.x) putchar('W');
        else putchar('E');
    }
}

Node qu[MAX*MAX];
int head, tail;

int getAns() {
    memset(vis, false, sizeof(vis));
    vis[500][500] = true;
    // queue<Node> que;
    // que.push((Node){TOMOVE,TOMOVE,0});
    head = tail = 0;
    qu[tail++] = (Node){TOMOVE,TOMOVE,0};
    x += TOMOVE; y += TOMOVE;
    // while (!que.empty()) {
    while (head != tail) {
        // Node cur = que.front(); que.pop();
        Node cur = qu[head++];
        if (cur.x == x && cur.y == y) {
            print(cur);
            puts("");
            return cur.len;
        }
        for (int i=0; i<4; ++i) {
            Node nex = cur;
            nex.len++;
            nex.x += dir[i][0] * nex.len;
            nex.y += dir[i][1] * nex.len;
            if (nex.x < 0 || nex.x >= MAX ||
                nex.y < 0 || nex.y >= MAX) {
                // puts("TOBROND");
                // continue;
            }
            if (!vis[nex.x][nex.y]) {
                pre[nex.x][nex.y] = cur;
                vis[nex.x][nex.y] = true;
                // que.push(nex);
                qu[tail++] = nex;
            }
        }
    }
    return -1;
}

int main() {
    // freopen("B-small-attempt1.bin", "r", stdin);
    // freopen("out", "w", stdout);
    int t, cs=0;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d%d", &x, &y);
        ++ cs;
        printf("Case #%d: ", cs);
        int ans = getAns();
        // printf("%d\n", ans);
    }


    // int mmx = 0;
    // for (int i=-100; i<=100; i++) {
    //     printf("x: %d\n", i);
    //     for (int j=-100; j<=100; j++) {
    //         x = i; y = j;
    //         // printf("x, y: %d %d\n", x, y);
    //         int ans = getAns();
    //         if (ans == -1) {
    //             printf("NOT %d %d\n", i, j);
    //             return 0;
    //         }
    //         if (ans > mmx)
    //             mmx = ans;
    //         // printf("%d\n", ans);
    //     }
    // }

    // printf("max: %d\n", mmx);
    return 0;
}
