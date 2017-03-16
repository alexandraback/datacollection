#include <iostream>
#include <vector>
using namespace std;

int sub(int index, int e, int E, int R, const vector<int>& vs, vector<vector<int> >& cache)
{
    if (index == vs.size())
    {
        return 0;
    }
    if (cache[index][e] != -1)
    {
        return cache[index][e];
    }

    int gain = 0;
    for (int i = 0; i <= e; ++i)
    {
        gain = max(gain, vs[index] * i + sub(index + 1, min(E, e - i + R), E, R, vs, cache));
    }

    cache[index][e] = gain;
    return gain;
}

int solve(int E, int R, const vector<int>& vs)
{
    vector<vector<int> > cache(vs.size(), vector<int>(E + 1, -1));
    return sub(0, E, E, R, vs, cache);
}

int main()
{
    int T;
    cin>>T;

    for (int i = 0; i < T; ++i)
    {
        int E, R, N;
        cin>>E>>R>>N;

        vector<int> vs(N);
        for (int j = 0; j < N; ++j)
        {
            cin>>vs[j];
        }

        int result = solve(E, R, vs);

        cout<<"Case #"<<(i + 1)<<": "<<result<<endl;
    }

    return 0;
}
