#include<cstdio>
#include<algorithm>

int G[105][105];
int H[105][105];

int main()
{
    int T;
    scanf("%d\n",&T);

    for (int ii = 1; ii <= T; ++ii)
    {
        int N, M;
        scanf("%d %d\n", &N, &M);
        for (int i = 0; i < N; ++i) for (int j = 0 ;j < M; ++j)
        {
            scanf("%d", G[i]+j);
            H[i][j] = 100;
        }

        for(int i = 0; i < N; ++i)
        {
            int A = 0;
            for(int j = 0;j < M; ++j) A = std::max(A,G[i][j]);
            for(int j = 0;j < M; ++j) H[i][j] = A;
        }
        for(int j = 0;j < M; ++j)
        {
            int B = 0;
            for(int i = 0; i < N; ++i) B = std::max(B,G[i][j]);
            for(int i = 0; i < N; ++i) H[i][j] = std::min(B,H[i][j]);
        }

        bool found = false;
        for (int i = 0; i < N; ++i) for (int j = 0 ;j < M; ++j)
        {
            if(H[i][j] != G[i][j])
            {
//                printf("%d %d %d %d\n", i,j,G[i][j], H[i][j]);
                found = true;
                goto L;
            }
        }
L:
        printf("Case #%d: %s\n", ii, found ? "NO":"YES");
    }
    return 0;
}
