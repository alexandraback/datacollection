#include <cstdio>
#include <cstring>
using namespace std;

const int MAXR = 50, MAXC = 50;
const int dr[] = {-1, -1, -1, 0, 1, 1,  1,  0};
const int dc[] = {-1,  0,  1, 1, 1, 0, -1, -1};

int R, C, N, cur;

bool v[MAXR+1][MAXR+1], pone;
int mark[MAXR+1][MAXC+1], c0;

void add(int r, int c, int d)
{
    if (r == 0 || r > R || c == 0 || c > C) return;

    if (mark[r][c] == 0) ++cur;
    mark[r][c] += d;
    if (mark[r][c] == 0) --cur;
}

bool rec(int r, int c)
{
    if (r == 0 || r > R || c == 0 || c > C) return false;
    if (r == 1 && !pone) return false;
    if (v[r][c]) return false;

    v[r][c] = true;
    for (int t = 0; t < 8; ++t) add(r+dr[t], c+dc[t], 1);

    if (N == cur) {
        return true;
    }

    if (N > cur) {
        if (rec(r+1, c)) return true;
        if (rec(r-1, c)) return true;
        if (rec(r, c+1)) return true;
        if (rec(r, c-1)) return true;
    }

    v[r][c] = false;
    for (int t = 0; t < 8; ++t) add(r+dr[t], c+dc[t], -1);
    return false;
}

int solve()
{
    pone = true; cur = 0;
    memset(v, 0, sizeof(v));
    memset(mark, 0, sizeof(mark));

    for (int c = 1; c <= C; ++c) {
        add(1, c, 1);
        if (rec(1, c)) { c0 = c; return 1; }
        add(1, c, -1);
    }

    pone = false; cur = 0;
    memset(v, 0, sizeof(v));
    memset(mark, 0, sizeof(mark));

    for (int c = 1; c <= C; ++c) {
        add(2, c, 1);
        if (rec(2, c)) { c0 = c; return 2; }
        add(2, c, -1);
    }

    return -1;
}

int main()
{
    int T; scanf("%d", &T);

    for (int t = 0; t < T; ++t) {
        scanf("%d%d%d", &R, &C, &N); N = R*C - N;

        printf("Case #%d:\n", t+1);
        int res;

        memset(mark, 0, sizeof(mark));
        if (N == 1) { mark[1][1] = 1; res = 1; c0 = 1; } else res = solve();

        if (res == -1) { printf("Impossible\n"); continue; }

        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j)
                if (i == res && j == c0)
                    printf("c");
                else
                    printf("%s", mark[i][j] ? "." : "*");

            printf("\n");
        }
    }

    return 0;
}
