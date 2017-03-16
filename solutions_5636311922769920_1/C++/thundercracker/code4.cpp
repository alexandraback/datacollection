#include <bits/stdc++.h>
using namespace std;

long long power[105];

int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("LG2.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    power[0] = 1;

    for(int test=1; test<=T; test++)
    {
        long long K, C, S;
        scanf("%lld %lld %lld", &K, &C, &S);

        vector<long long> X;

        for(int i=1; i<=100; i++)
            power[i] = power[i-1]*K;

        for(int i=1; i<=K; )
        {
            long long ptr = 0;

            for(int j=C-1; j>=0; j--)
            {
                if(i<=K)
                    ptr += power[j]*(i-1);
                else
                    ptr += power[j]*(K-1);

                i++;
            }

            X.push_back(ptr+1);
        }

        if(X.size()>S)
            printf("Case #%d: IMPOSSIBLE\n", test);
        else
        {
            printf("Case #%d: ", test);

            for(int i=0; i<X.size(); i++)
                printf("%lld ", X[i]);
            printf("\n");
        }
    }

    fclose(stdout);
    fclose(stdin);

    return 0;
}
