#include <iostream>
#include <vector>
using namespace std;

string solve(const vector<vector<int> >& m)
{
    int N = m.size();
    int M = m[0].size();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            bool cuttableRow = true;
            for (int k = 0; k < M; ++k)
            {
                if (m[i][k] > m[i][j])
                {
                    cuttableRow = false;
                }
            }
            bool cuttableCol = true;
            for (int k = 0; k < N; ++k)
            {
                if (m[k][j] > m[i][j])
                {
                    cuttableCol = false;
                }
            }

            if (!cuttableRow && !cuttableCol)
            {
                return "NO";
            }
        }
    }

    return "YES";
}

int main()
{
    int T;
    cin>>T;

    for (int i = 0; i < T; ++i)
    {
        int N, M;
        cin>>N>>M;

        vector<vector<int> > m(N, vector<int>(M));
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                cin>>m[j][k];
            }
        }

        string result = solve(m);
        cout<<"Case #"<<(i + 1)<<": "<<result<<endl;
    }

    return 0;
}
