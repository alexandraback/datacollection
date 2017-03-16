#include <iostream>
#include <vector>
using namespace std;

bool dfs(const vector<vector<bool> > &arrow, int node, vector<bool> &flags)
{
    int N = arrow.size();

    bool ret = false;
    for (int i = 0; i < N; ++i)
    {
        if (arrow[i][node])
        {
            if (flags[i])
            {
                return true;
            }
            flags[i] = true;
            ret |= dfs(arrow, i, flags);
        }
    }

    return ret;
}

bool solve(const vector<vector<bool> > &arrow, const vector<bool> &source)
{
    int N = arrow.size();

    for (int i = 0; i < N; ++i)
    {
        vector<bool> flags(N, false);
        if (source[i] && dfs(arrow, i, flags))
        {
            return true;
        }
    }

    return false;
}
int main()
{
    int T;
    cin>>T;

    for (int caseNum = 1; caseNum <= T; ++caseNum)
    {
        int N;
        cin>>N;

        vector<vector<bool> > arrow(N, vector<bool>(N, false));
        vector<bool> source(N, true);
        for (int i = 0; i < N; ++i)
        {
            int M;
            cin>>M;
            if (M > 0)
            {
                source[i] = false;
            }
            for (int j = 0; j < M; ++j)
            {
                int to;
                cin>>to;
                arrow[i][to - 1] = true;
            }
        }

        cout<<"Case #"<<caseNum<<": "<<(solve(arrow, source)? "Yes": "No")<<endl;
    }

    return 0;
}
