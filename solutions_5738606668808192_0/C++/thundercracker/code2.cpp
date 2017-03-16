#include <bits/stdc++.h>
using namespace std;

long long get_div(long long N)
{
    long long X = sqrt(N);

    for(int i=2; i<=X; i++)
        if(N%i==0)
            return i;

    return -1;
}

int main()
{
    int T;
    T = 1;

    freopen("out.txt", "w", stdout);

    for(int test=1; test<=T; test++)
    {
        int N, J;
        N = 16, J = 50;

        printf("Case #%d:\n", test);

        for(int i=(1LL<<(N-1))+1; J && i<(1LL<<N); i+= 2)
        {
            int flag = 0;
            vector<long long> X;
            long long num = 0, x = 1;

            for(int j=2; j<=10; j++)
            {
                num = 0;
                x = 1;

                for(int k=0; k<N; k++)
                {
                    if(i&(1LL<<k))
                        num += x;

                    x *= (long long)j;
                }

                X.push_back(get_div(num));

                if(X[X.size()-1]==-1)
                {
                    flag = 1;
                    break;
                }
            }

            if(!flag)
            {
                printf("%lld ", num);

                for(int i=0; i<X.size(); i++)
                    printf("%lld ", X[i]);
                printf("\n");

                J--;
            }
        }
    }

    fclose(stdout);

    return 0;
}
