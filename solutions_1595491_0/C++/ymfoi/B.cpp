#include <cstdio>
#include <cstring>
#include <algorithm>

void work() {

    const int MAXN = 1000;
    const int INF = 0x3f3f3f3f;

    int S, N, ti, p;
    static int f[MAXN + 1][MAXN + 1];

    memset(f, 0, sizeof f);
    scanf("%d %d %d", &N, &S, &p);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &ti);
        for (int j = 0; j <= i && j <= S; j++)
        {
            int v1 = j && ti >= 2 ? 
                f[i - 1][j - 1] + (((ti - 2) / 3 + 2) >= p) : -INF;

            int v2 = f[i - 1][j] + 
                (std::max(
                        ti >= 1 ? (ti - 1) / 3 + 1 : -INF,
                        ti % 3 ? -INF : ti / 3) >= p);
            f[i][j] = std::max(v1, v2);
        }
    }
    printf("%d\n", f[N][S]);
}

int main() {
    
    int case_num;

//    freopen("in", "r", stdin);
    scanf("%d", &case_num);
    for (int i = 0; i < case_num; i++)
    {
        printf("Case #%d: ", i + 1);
        work();
    }

    return 0;
}
