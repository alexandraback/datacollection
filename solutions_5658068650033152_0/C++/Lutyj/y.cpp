#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 20;

int N, M, K;
int f[MAXN][MAXN];
bool mark[MAXN][MAXN];

bool dfs(int r, int c)
{
    if (f[r][c] == 1) return false;
    mark[r][c] = true;

    if (r == 0 || r == N-1 || c == 0 || c == M-1) {
        return true;
    } else {
        if (r > 0 && !mark[r-1][c] && dfs(r-1, c)) return true;
        if (r < N-1 && !mark[r+1][c] && dfs(r+1, c)) return true;
        if (c > 0 && !mark[r][c-1] && dfs(r, c-1)) return true;
        if (c < M-1 && !mark[r][c+1] && dfs(r, c+1)) return true;
    }


    return false;
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        printf("Case #%d: ", t+1);

        scanf("%d%d%d", &N, &M, &K);
        int my = N*M;

        for (int mask = 3; mask < 1<<(N*M); ++mask) {
            int y = 0;

            for (int r = 0; r < N; ++r)
                for (int c = 0; c < M; ++c) {
                    f[r][c] = (mask & (1<<(r*M+c))) ? 1 : 0;
                    y += f[r][c];
                }

            int z = 0;

            for (int r = 0; r < N; ++r)
                for (int c = 0; c < M; ++c) {
                    memset(mark, 0, sizeof(mark));
                    if (!dfs(r, c)) ++z;
                }

            if (z >= K && y <= my) my = y;
        }

        printf("%d\n", my);
    }

    return 0;
}
