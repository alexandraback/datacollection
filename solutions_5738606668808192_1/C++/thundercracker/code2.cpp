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
    int T, wow = 0;
    T = 1;

    freopen("sixteen.txt", "w", stdout);

    vector<long long> Y;

    Y.push_back(3);
    Y.push_back(2);
    Y.push_back(5);
    Y.push_back(2);
    Y.push_back(7);
    Y.push_back(2);
    Y.push_back(3);
    Y.push_back(2);
    Y.push_back(11);

    for(int test=1; test<=T; test++)
    {
        int N, J;
        N = 16, J = 500;

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

            if(!flag && num%11==0)
            {
                X[X.size()-1] = 11;

                if(X==Y)
                {
                    printf("1");

                    for(int i=1; i<=16; i++)
                        printf("0");

                    printf("%015lld ", num%1000000000000000);

                    printf("3 2 5 2 7 2 3 2 11\n");

                    J--;
                    wow++;
                }
            }
        }
    }

    fclose(stdout);

    return 0;
}
