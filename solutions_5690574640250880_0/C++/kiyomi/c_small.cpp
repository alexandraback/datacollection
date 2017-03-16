#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int T, R, C, M;
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
int m[10][10], cnt[10][10], vis[10][10];
int m1[10][10][30], m2[10][10][30], m3[10][10][30];
char ans[10][10];

int cas1[] = {
    0, 1, 3, 7, 39, 31, 63, 127, 255, 1279,
    1023, 2047, 4095, 8191, 1085439, 32767,
    3248127, 1114111, -1, 3276799, -1, 7602175,
    -1, -1, 16777215
};

int cas2[30], cas3[30];

void put() {
    for (int i = 0; i < 25; i++) {
        m1[5][5][i] = cas1[i];
        if (cas1[i] == -1) {
            m2[5][5][i] = m3[5][5][i] = -1;
        } else {
            m2[5][5][i] = 4;
            if (i <= 13 || i == 15)
                m3[5][5][i] = 0;
            else if (i == 14 || i == 17)
                m3[5][5][i] = 2;
            else if (i == 16 || i == 19)
                m3[5][5][i] = 3;
            else
                m3[5][5][i] = 4;
        }
    }
}

bool valid(int x, int y, int rr, int rc) {
    return x >= 0 && y >= 0 && x < rr && y < rc;
}

void dfs(int x, int y, int rr, int rc) {
    if (vis[x][y])
        return;
    vis[x][y] = 1;
    if (cnt[x][y])
        return;
    for (int i = 0; i < 8; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (valid(x1, y1, rr, rc) && m[x1][y1] == 0)
            dfs(x1, y1, rr, rc);
    }
}

void prep(int rr, int rc) {
    int n = rr * rc;
    for (int i = 0; i < (1 << n) - 1; i++) {
        int c1 = 0;
        for (int j = 0; j < n; j++) {
            int r = j / rc;
            int c = j % rc;
            vis[r][c] = cnt[r][c] = 0;
            //cout << j << " " << r << " " << c << "\n";
            if (i & (1 << j))
                m[r][c] = 1;
            else
                m[r][c] = 0;
            c1 += 1 - m[r][c];
        }
        int m5 = n - c1;
        if (m1[rr][rc][m5] != -1)
            continue;
        if (c1 <= 1) {
            m1[rr][rc][m5] = i;
            for (int j = 0; j < rr; j++) {
                for (int k = 0; k < rc; k++) {
                    if (m[j][k] == 0) {
                        m2[rr][rc][m5] = j;
                        m3[rr][rc][m5] = k;
                        break;
                    }
                }
            }
        } else {
            for (int j = 0; j < rr; j++) {
                for (int k = 0; k < rc; k++) {
                    if (m[j][k] == 0) {
                        for (int l = 0; l < 8; l++) {
                            int aj = j + dx[l];
                            int ak = k + dy[l];
                            if (valid(aj, ak, rr, rc))
                                cnt[j][k] += m[aj][ak];
                        }
                    }
                }
            }
            int c2 = -1;
            int c3 = -1;
            for (int j = 0; j < rr; j++) {
                for (int k = 0; k < rc; k++) {
                    if (m[j][k] == 0 && cnt[j][k] == 0) {
                        c2 = j;
                        c3 = k;
                        break;
                    }
                }
            }
            if (c2 != -1) {
                bool ok = true;
                dfs(c2, c3, rr, rc);
                for (int j = 0; j < rr; j++) {
                    for (int k = 0; k < rc; k++) {
                        if (m[j][k] == 0 && !vis[j][k]) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) {
                    m1[rr][rc][m5] = i;
                    m2[rr][rc][m5] = c2;
                    m3[rr][rc][m5] = c3;
                }
            }
        }
    }
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    memset(m1, -1, sizeof m1);
    memset(m2, -1, sizeof m2);
    memset(m3, -1, sizeof m3);

    put();

    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            if (i + j < 10)
                prep(i, j);

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> R >> C >> M;
        printf("Case #%d:\n", t);
        if (m1[R][C][M] == -1) {
            cout << "Impossible\n";
        } else {
            int b = m1[R][C][M];
            int n = R * C;
            for (int i = 0; i < n; i++) {
                int r = i / C;
                int c = i % C;
                if (b & (1 << i))
                    ans[r][c] = '*';
                else
                    ans[r][c] = '.';
            }
            ans[m2[R][C][M]][m3[R][C][M]] = 'c';
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++)
                    printf("%c", ans[i][j]);
                printf("\n");
            }
        }
    }

    return 0;

}
