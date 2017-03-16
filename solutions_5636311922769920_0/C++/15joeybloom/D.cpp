#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        long long int K, C, S;
        scanf("%lld %lld %lld", &K, &C, &S);

        if(S == K)
        {
            printf("Case #%d:", t);
            for(int i = 1; i <= S; i++)
            {
                printf(" %d", i);
            }
            printf("\n");
        }
        else if(S*C < K)
        {
            printf("Case #%d: IMPOSSIBLE\n", t);
        }
        else
        {
            long long int Ks[100];
            Ks[0] = 1;
            for(int i = 1; i < 100; i++)
                Ks[i] = K * Ks[i-1];

            int x = K/C;
            if(K%C)
                x++;
            long long int k = 0;

            printf("Case #%d:", t);
            for(int i = 0; i < x; i++)
            {
                long long int s = 0;
                for(int j = 0; j < C; j++)
                {
                    s += k * Ks[j];
                    k = (k+1)%K;
                }
                printf(" %lld", s+1);
            }
            printf("\n");
        }
    }
}
