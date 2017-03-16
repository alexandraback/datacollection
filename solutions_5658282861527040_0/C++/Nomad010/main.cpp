#include <cstdio>

int main(int argc, char** argv)
{
    int T = 0;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t)
    {
        printf("Case #%d: ", t);
        long long A, B, K;
        scanf("%lld %lld %lld", &A, &B, &K);
        
        long long answer = 0;
        for(long long i = 0; i < A; ++i)
            for(long long j = 0; j < B; ++j)
                if((i & j) < K)
                    ++answer;
        printf("%lld\n", answer);
    }
    return 0;
}