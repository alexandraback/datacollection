#include<stdio.h>
#include<string.h>

#define INF 1000000000

int n, m, h;
int floor[110][110];
int ceil[110][110];
int minTime[110][110];
int passingMinTime[110][110][4];
bool ignore[110][110];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int qx[11000];
int qy[11000];
int qsize;
int qpos;

int calcPassingMinTime(int i, int j, int dir)
{
    if (ignore[i][j]) return INF;
    int ni = i + dx[dir];
    int nj = j + dy[dir];
    if (ni < 0 || ni >= n) return INF;
    if (nj < 0 || nj >= m) return INF;
    if (ignore[ni][nj]) return INF;
    if (floor[i][j] + 50 > ceil[ni][nj]) return INF;
    if (floor[ni][nj] + 50 > ceil[i][j]) return INF;
    int min = h + 50 - ceil[i][j];
    if (min < 0) min = 0;
    int minn = h + 50 - ceil[ni][nj];
    if (minn < 0) minn = 0;
    if (min < minn) return minn;
    return min;
}

int main()
{
    int teste, t;
    int i, j;
    scanf("%d\n", &teste);
    for (t = 0; t < teste; t++)
    {
        scanf("%d %d %d", &h, &n, &m);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf("%d", &ceil[i][j]);
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf("%d", &floor[i][j]);
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                minTime[i][j] = INF;
                ignore[i][j] = false;
                if (ceil[i][j] < floor[i][j] + 50)
                    ignore[i][j] = true;
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                passingMinTime[i][j][0] = calcPassingMinTime(i, j, 0);
                passingMinTime[i][j][1] = calcPassingMinTime(i, j, 1);
                passingMinTime[i][j][2] = calcPassingMinTime(i, j, 2);
                passingMinTime[i][j][3] = calcPassingMinTime(i, j, 3);
            }
        }
        minTime[0][0] = 0;
        qpos = 0;
        qsize = 1;
        qx[0] = 0;
        qy[0] = 0;
        while (qpos < qsize)
        {
            i = qx[qpos];
            j = qy[qpos];
            for (int a = 0; a < 4; a++)
            {
                if (passingMinTime[i][j][a] == 0)
                {
                    int ni = i + dx[a];
                    int nj = j + dy[a];
                    if (minTime[ni][nj] != 0)
                    {
                        minTime[ni][nj] = 0;
                        qx[qsize] = ni;
                        qy[qsize] = nj;
                        qsize++;
                    }
                }
            }
            qpos++;
        }
        while(true)
        {
            int bestTime = INF;
            int besti, bestj;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    if (minTime[i][j] < INF) continue;
                    for (int a = 0; a < 4; a++)
                    {
                        if (passingMinTime[i][j][a] >= INF) continue;
                        int ni = i + dx[a];
                        int nj = j + dy[a];
                        if (minTime[ni][nj] >= INF) continue;
                        int candidate = (minTime[ni][nj] < passingMinTime[i][j][a]) ? passingMinTime[i][j][a] : minTime[ni][nj];
                        if (h - candidate < floor[ni][nj] + 20)
                            candidate += 100;
                        else
                            candidate += 10;
                        if (candidate < bestTime)
                        {
                            bestTime = candidate;
                            besti = i;
                            bestj = j;
                        }
                    }
                }
            }
            if (minTime[n-1][m-1] < INF)
                break;
            if (bestTime >= INF)
                break;
            minTime[besti][bestj] = bestTime;
        }
        /*for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("%d ", minTime[i][j]);
            }
            printf("\n");
        }*/
        printf("Case #%d: %.1lf\n", t + 1, 0.1 * minTime[n-1][m-1]);
    }
    return 0;
}
