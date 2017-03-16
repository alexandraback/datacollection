#include <iostream>
#include <vector>
using namespace std;

int getNum(int n, int m)
{
    int count = 0;

    while (n % m == 0)
    {
        n /= m;
        ++count;
    }

    return count;
}

int solve(int N, int M, vector<int>& vs)
{
    int result = 0;
    int min3 = 0;
    int min5 = 0;

    for (int i = 0; i < vs.size(); ++i)
    {
        min3 = max(min3, getNum(vs[i], 3));
        min5 = max(min5, getNum(vs[i], 5));
        while (vs[i] % 3 == 0)
        {
            vs[i] /= 3;
        }
        while (vs[i] % 5 == 0)
        {
            vs[i] /= 5;
        }
    }
    for (int i = 0; i < min3; ++i)
    {
        result = result * 10 + 3;
    }
    for (int i = 0; i < min5; ++i)
    {
        result = result * 10 + 5;
    }
    N -= min3 + min5;

    for (int i = 0; i < vs.size(); ++i)
    {
        if (4 * N == vs[i])
        {
            for (int j = 0; j < N; ++j)
            {
                result = result * 10 + 4;
                return result;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        result = result * 10 + rand() % 4 + 2;
    }

    return result;
}

int main()
{
    int T;
    cin>>T;

    for (int i = 0; i < T; ++i)
    {
        int R, N, M, K;
        cin>>R>>N>>M>>K;

        cout<<"Case #"<<(i + 1)<<":"<<endl;

        for (int j = 0; j < R; ++j)
        {
            vector<int> vs(K);
            for (int k = 0; k < K; ++k)
            {
                cin>>vs[k];
            }

            int result = solve(N, M, vs);
            cout<<result<<endl;
        }
    }

    return 0;
}
