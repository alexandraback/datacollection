#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
int b, m;
int ways[MAX];
int g[MAX][MAX];

bool back(int x, int y) {
    if (x == b - 1)
        return ways[b - 1] == m;
    int nextx = x, nexty = y + 1;
    if (nexty == b) {
        nextx = x + 1;
        nexty = nextx + 1;
    }
    if (back(nextx, nexty))
        return true;
    g[x][y] = 1;
    ways[y] += ways[x];
    if (back(nextx, nexty))
        return true;
    ways[y] -= ways[x];
    g[x][y] = 0;
    return false;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        scanf("%d%d", &b, &m);
        memset(g, 0, sizeof(g));
        memset(ways, 0, sizeof(ways));
        ways[0] = 1;
        if (back(0, 1)) {
            printf("Case #%d: POSSIBLE\n", cs);
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < b; j++)
                    printf("%d", g[i][j]);
                puts("");
            }
        } else
            printf("Case #%d: IMPOSSIBLE\n", cs);
    }
}
