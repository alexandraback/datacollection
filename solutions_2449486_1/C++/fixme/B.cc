#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int idxTestcase = 1; idxTestcase <= T; ++idxTestcase)
    {
        int N, M;
        scanf("%d%d", &N, &M);
        vector<vector<int> > a(N);
        for (int i = 0; i < N; ++i)
        {
            a[i].assign(M, 0);
            for (int j = 0; j < M; ++j)
                scanf("%d", &a[i][j]);
        }
        vector<int> r(N, 0);
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (a[i][j] > r[i])
                    r[i] = a[i][j];
            }
        }
        vector<int> c(M, 0);
        for (int j = 0; j < M; ++j)
        {
            for (int i = 0; i < N; ++i)
            {
                if (a[i][j] > c[j])
                    c[j] = a[i][j];
            }
        }
        bool res = true;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (r[i] > a[i][j] && c[j] > a[i][j])
                {
                    res = false;
                    break;
                }
            }
        }
        printf("Case #%d: %s\n", idxTestcase, res ? "YES" : "NO");
    }
    return 0;
}
