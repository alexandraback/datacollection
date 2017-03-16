#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int MAXH = 10010;
const int MAXN = 105;
const int INF = 1000100100;
const int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
const int MAXQ = MAXN*MAXN*MAXH;
int ans[MAXN][MAXN][MAXH];
bool inq[MAXN][MAXN][MAXH];
int q[MAXQ][3];
int c[MAXN][MAXN], f[MAXN][MAXN];

#define IN(x,y) ((x)>=0&&(x)<n&&(y)>=0&&(y)<m)

bool can(int fx, int fy, int tx, int ty, int h) {
    if (c[tx][ty] - f[fx][fy] < 50) return 0;
    if (c[tx][ty] - f[tx][ty] < 50) return 0;
    if (c[tx][ty] - h < 50) return 0;
    if (c[fx][fy] - f[tx][ty] < 50) return 0;
    return 1;
}

int main() {
    freopen("B-large.in","r",stdin);
    FILE *fp = fopen("B-large.out","w");
    int T, ca, i, j, H, n, m;
    scanf("%d",&T);
    for (ca = 1 ; ca <= T ; ++ca) {
        printf("solving case %d\n",ca);
        scanf("%d%d%d",&H,&n,&m);
        for (i = 0 ; i < n ; i++)
            for (j = 0 ; j < m ; j++)
                scanf("%d",&c[i][j]);
        for (i = 0 ; i < n ; i++)
            for (j = 0 ; j < m ; j++)
                scanf("%d",&f[i][j]);
        memset(inq, 0, sizeof(inq));
        memset(ans, 0x3f, sizeof(ans));
        q[0][0] = 0; q[0][1] = 0; q[0][2] = H;
        ans[0][0][H] = 0;
        int qh, qt;
        for (qh = 0, qt = 1 ; qh != qt ; ++qh) {
            // stay
            int td = max(0, q[qh][2] - 1);
            int tc = 1;
            int cost = ans[q[qh][0]][q[qh][1]][q[qh][2]];
            if (cost + tc < ans[q[qh][0]][q[qh][1]][td]) {
                ans[q[qh][0]][q[qh][1]][td] = cost + tc;
                if (!inq[q[qh][0]][q[qh][1]][td]) {
                    inq[q[qh][0]][q[qh][1]][td] = 1;
                    q[qt][0] = q[qh][0];
                    q[qt][1] = q[qh][1];
                    q[qt][2] = td;
                    if (++qt == MAXQ) qt = 0;
                }
            }
            // move
            for (int d = 0 ; d < 4 ; d++) {
                int tx = q[qh][0] + dir[d][0];
                int ty = q[qh][1] + dir[d][1];

                if (!IN(tx,ty)) continue;
                if (can(q[qh][0], q[qh][1], tx, ty, q[qh][2])) {
                    if (q[qh][2] == H) {td = H; tc = 0;}
                    else {
                        if (q[qh][2] - f[q[qh][0]][q[qh][1]] >= 20) {
                            tc = 10;
                        } else tc = 100;
                        td = max(0, q[qh][2] - tc);
                    }
                    if (cost + tc < ans[tx][ty][td]) {
                        ans[tx][ty][td] = cost + tc;
                        if (!inq[tx][ty][td]) {
                            inq[tx][ty][td] = 1;
                            q[qt][0] = tx;
                            q[qt][1] = ty;
                            q[qt][2] = td;
                            if (++qt == MAXQ) qt = 0;
                        }
                    }
                }
            }
            inq[q[qh][0]][q[qh][1]][q[qh][2]] = 0;
        }
        int best = INF;
        for (int tmph = 0 ; tmph <= H ; ++tmph) {
            if (ans[n-1][m-1][tmph] < best)
                best = ans[n-1][m-1][tmph];
        }
        fprintf(fp, "Case #%d: %d.%d\n", ca, best/10, best%10);
    }
    fclose(fp);
    return 0;
}
