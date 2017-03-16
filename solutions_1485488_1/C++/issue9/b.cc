#include <cstdio>
#include <cstring>

#define D if(0)
int h,n,m;
int c[128][128];
int f[128][128];
int bt[128][128];
int bt2[128][128];

int solved, t;
int dxs[4] = {1,-1,0,0};
int dys[4] = {0,0,-1,1};

#define max(a,b) ((a) > (b) ? (a) : (b))

int cango(int h, int y, int x, int y2, int x2) {
    // if (y2 >= n || x2 >= m || x2 < 0 || y2 < 0) return 0;
    int cd = c[y2][x2];
    if (cd == -1 || max(h, f[y][x])+50 > cd) return 0;
    if (f[y2][x2]+50 > c[y][x]) return 0;
    return 1;
}

void ff(int y, int x) {
    if (bt[y][x] >= 0) return;
    bt[y][x] = 0;
    for (int i = 0; i < 4; ++i) {
        int x2 = x + dxs[i], y2 = y + dys[i];
        if (y2 >= n || x2 >= m || x2 < 0 || y2 < 0) continue;
        if (cango(::h, y,x,y2,x2)) ff(y2,x2);
    }
}

void dbp() {
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                printf("%4d", bt[y][x]);
            }
            printf("\n");
        }
}

void ref(int y, int x) {
    // refresh according to new h
    // if (bt[y][x] < 0) return;
    if (t < bt[y][x]) return;
    for (int i = 0; i < 4; ++i) {
        int x2 = x + dxs[i], y2 = y + dys[i];
        if (y2 >= n || x2 >= m || x2 < 0 || y2 < 0) continue;

        // best possible t from cur gird
        int bat = t; // max(t, bt[y][x]);
        if (::h - f[y][x] >= 20) bat += 10; else bat += 100;

        if ((bt[y2][x2] == -1 || bt[y2][x2] > bat) && cango(::h, y,x,y2,x2)) {
            // update bt[y2][x2]
            bt[y2][x2] = bat;
        }
    }
}

int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ++ti) {
        printf("Case #%d: ", ti + 1);

        scanf("%d%d%d", &h, &n, &m);

        for (int y = 0; y < n; ++y) for (int x = 0; x < m; ++x) scanf("%d", &c[y][x]);
        for (int y = 0; y < n; ++y) for (int x = 0; x < m; ++x) scanf("%d", &f[y][x]);

        for (int y = 0; y < n; ++y) for (int x = 0; x < m; ++x) if (f[y][x] + 50 > c[y][x]) {
            // unreachable
            c[y][x] = -1;
        }

        // best time
        memset(bt, -1, sizeof(bt));

        // cango
        ff(0,0);

        // time
        // t is in 0.1 s
        t = 0;
        solved = 0;
        while(!solved) {
            // memset(bt2, -1, sizeof(bt2));
            D printf("t = %d, h = %d \n", t, h);
            D dbp();
            ++t;
            if (h>0) h -= 1;
            // refresh bt[][]
            for (int y = 0; y < n; ++y) for (int x = 0; x < m; ++x) 
                if (bt[y][x] >= 0) ref(y,x);
            if (bt[n-1][m-1] != -1 && bt[n-1][m-1] + 1000 < t) solved = 1;
            // update bt to bt2
            // for (int y = 0; y < n; ++y) for (int x = 0; x < m; ++x) {
            //     if (bt2[y][x] != -1) bt[y][x] = bt2[y][x];
            // }
        }

        printf("%g\n", bt[n-1][m-1]*0.1);
    }
    return 0;
}
