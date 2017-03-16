#include <cstdio>

int main(int argc, char **argv)
{
    int T;
    long long int K, C, S;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        scanf("%lld %lld %lld", &K, &C, &S);

        if (C * S < K)
        {
            printf("Case #%d: IMPOSSIBLE\n", t);
            continue;
        }

        printf("Case #%d:", t);

        long long int index_count = 0;
        long long int depth_count = 0;
        long long int index = 0;

        while (index_count < K)
        {
            index = index * K + index_count;
            index_count++;
            depth_count++;

            if (depth_count == C)
            {
                printf(" %lld", index + 1);
                depth_count = 0;
                index = 0;
            }
        }

        if (depth_count != 0)
        {
            while (depth_count < C)
            {
                index = index * K;
                depth_count++;
            }
            printf(" %lld", index + 1);
        }

        printf("\n");
    }

    return 0;
}
