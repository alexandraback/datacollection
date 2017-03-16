#include <stdio.h>

int main ()
{
    int T, N, M, K;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        scanf("%d %d %d", &N, &M, &K);
        int result = 0;
        if (N <= 2 || M <=2)
        {
            result = K;
        }
        else
        {
            int n = (K-2)/3;
            int x = (K-2)%3;
            result = 2*n + 2 + x;
        }
        printf("Case #%d: %d\n", t+1, result);
    }
}