#include<stdio.h>
#include<string.h>
int W[51][51];
int main()
{
    int T, N;
    scanf("%d", &T);
    long long M;
    for(int t = 1; t <= T; t++)
    {
        scanf("%d %lld", &N, &M);
        memset(W, 0, sizeof(W));
        for(int i = 1; i < N; i++)
        {
            for(int j = 1; j < i; j++) W[j][i] = 1;
        }
        long long Lim = (1LL << (N - 2));
        printf("Case #%d: ", t);
        if(Lim < M)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        if(Lim == M) W[1][N] = 1, M--;
        for(int j = 0; j < N - 2; j++)
        {
            if(M & (1 << j))
            {
                W[j + 2][N] = 1;
            }
        }
        printf("POSSIBLE\n");
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++) printf("%d", W[i][j]);
            printf("\n");
        }
    }
}
