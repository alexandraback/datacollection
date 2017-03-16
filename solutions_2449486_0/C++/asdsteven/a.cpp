#include <cstdio>
#include <algorithm>

using namespace std;

int a[100][100], r[100], c[100];

const char *solve()
{
        int N, M;
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                        scanf("%d", a[i] + j);
        for (int i = 0; i < N; i++) {
                r[i] = 0;
                for (int j = 0; j < M; j++)
                        r[i] = max(r[i], a[i][j]);
        }
        for (int i = 0; i < M; i++) {
                c[i] = 0;
                for (int j = 0; j < N; j++)
                        c[i] = max(c[i], a[j][i]);
        }
        for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                        if (a[i][j] != min(r[i], c[j]))
                                return "NO";
        return "YES";
}

int main()
{
        int T;
        scanf("%d", &T);
        for (int i = 1; i <= T; i++)
                printf("Case #%d: %s\n", i, solve());
}
