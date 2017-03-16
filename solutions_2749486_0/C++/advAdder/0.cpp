#include <cstdio>
#include <cstdlib>
#include <cstring>

int dist[300][300];
char last[300][300];
int x, y;

inline void bfs()
{
    int que[40005][2];
    int a, z;
    que[0][0] = 100;
    que[0][1] = 100;
    que[0][2] = 1;
    memset(dist, 0xff, sizeof(dist));
    a = 0; z = 1;
    dist[100][100] = 1;
    while (a != z) {
        int cx = que[a][0];
        int cy = que[a][1];
        if (cx == x && cy == y)
            break;
        ++a;
        if (cx - dist[cx][cy] >= 0 && dist[cx-dist[cx][cy]][cy] < 0) {
            dist[cx-dist[cx][cy]][cy] = dist[cx][cy] + 1;
            last[cx-dist[cx][cy]][cy] = 'W';
            que[z][0] = cx-dist[cx][cy];
            que[z][1] = cy;
            ++z;
        }
        if (cx + dist[cx][cy] <= 200 && dist[cx+dist[cx][cy]][cy] < 0) {
            dist[cx+dist[cx][cy]][cy] = dist[cx][cy] + 1;
            last[cx+dist[cx][cy]][cy] = 'E';
            que[z][0] = cx+dist[cx][cy];
            que[z][1] = cy;
            ++z;
        }
        if (cy - dist[cx][cy] >= 0 && dist[cx][cy-dist[cx][cy]] < 0) {
            dist[cx][cy-dist[cx][cy]] = dist[cx][cy] + 1;
            last[cx][cy-dist[cx][cy]] = 'S';
            que[z][0] = cx;
            que[z][1] = cy-dist[cx][cy];
            ++z;
        }
        if (cy + dist[cx][cy] <= 200 && dist[cx][cy+dist[cx][cy]] < 0) {
            dist[cx][cy+dist[cx][cy]] = dist[cx][cy] +1;
            last[cx][cy+dist[cx][cy]] = 'N';
            que[z][0] = cx;
            que[z][1] = cy+dist[cx][cy];
            ++z;
        }
    }
}

inline void deal()
{
    char st[10000];
    memset(st, 0, sizeof(st));
    scanf("%d%d", &x, &y);
    x += 100;
    y += 100;
    bfs();
    int s = 0;
    while (x != 100 || y != 100) {
        st[s++] = last[x][y];
        if (last[x][y] == 'N')
            y -= dist[x][y]-1;
        else if (last[x][y] == 'S')
            y += dist[x][y]-1;
        else if (last[x][y] == 'W')
            x += dist[x][y]-1;
        else
            x -= dist[x][y]-1;
    }
    st[s] = 0;
    printf("%s\n", strrev(st));
}

int main()
{
    int cases;
    scanf("%d\n", &cases);
    for (int i = 1; i <= cases; ++i) {
        printf("Case #%d: ", i);
        deal();
    }
    return 0;
}
