#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2000;
const int HALFN = MAXN / 2;
const int MAXS = 500;
const int DIR_N = 0;
const int DIR_S = 1;
const int DIR_E = 2;
const int DIR_W = 3;
const int dirX[] = {0, 0, 1, -1};
const int dirY[] = {1, -1, 0, 0};

char path[MAXN][MAXN];
int steps[MAXN][MAXN];

void init()
{
    memset(path, -1, sizeof(path));
    queue<int> qx;
    queue<int> qy;
    queue<int> qstep;
    qx.push(HALFN);
    qy.push(HALFN);
    qstep.push(1);
    while (!qx.empty())
    {
        int x = qx.front();
        int y = qy.front();
        int step = qstep.front();
        //printf("u %d %d %d\n", step, x - HALFN, y - HALFN);
        for (int k = 0; k < 4; ++k)
        {
            int tx = x + step * dirX[k];
            int ty = y + step * dirY[k];
            if (tx >= 0 && tx < MAXN)
            {
                if (ty >= 0 && ty < MAXN)
                {
                    if (step + 1 < MAXS)
                    {
                        if (path[tx][ty] == -1)
                        {
                            //printf("v %d %d %d\n", step + 1, tx - HALFN, ty - HALFN);
                            path[tx][ty] = k;
                            steps[tx][ty] = step;
                            qx.push(tx);
                            qy.push(ty);
                            qstep.push(step + 1);
                        }
                    }
                }
            }
        }
        qx.pop();
        qy.pop();
        qstep.pop();
    }
}

void test()
{
    for (int x = -10; x <= 10; ++x)
    {
        for (int y = -10; y <= 10; ++y)
        {
            if (x == 0 && y == 0)
            {
                printf(" * ");
            }
            else
            {
                printf("%2d ", path[x + HALFN][y + HALFN]);
            }
        }
        printf("\n");
    }
}

char ans[MAXS];

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);
    init();
    //test();
    int T;
    int x, y;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%d", &x, &y);
        int num = 0;
        x += HALFN;
        y += HALFN;
        int step = steps[x][y];
        while (step)
        {
            //printf("%d %d\n", x - HALFN, y - HALFN);
            switch(path[x][y])
            {
            case DIR_N:
                y -= step;
                ans[num++] = 'N';
                break;
            case DIR_S:
                y += step;
                ans[num++] = 'S';
                break;
            case DIR_E:
                x -= step;
                ans[num++] = 'E';
                break;
            case DIR_W:
                x += step;
                ans[num++] = 'W';
                break;
            }
            --step;
        }
        printf("Case #%d: ", t);
        for (int i = num - 1; i >= 0; --i)
        {
            putchar(ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
