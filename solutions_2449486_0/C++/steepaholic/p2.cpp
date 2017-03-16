#include <iostream>
#include <vector>
using namespace std;

void testcase(int t)
{
    int N, M;
    cin >> N >> M;
    vector<vector<int> > lawn;
    for(int n = 0; n < N; ++n)
    {
        vector<int> row;
        for(int m = 0; m < M; ++m)
        {
            int height;
            cin >> height;
            row.push_back(height);
        }
        lawn.push_back(row);
    }
    bool all_okay = true;
    for(int n = 0; n < N && all_okay; ++n)
    {
        for(int m = 0; m < M && all_okay; ++m)
        {
            if(lawn.at(n).at(m) == 2) continue;
            bool row_okay = true;
            for(int i = 0; i < M; ++i)
            {
                row_okay = row_okay && lawn.at(n).at(i) == 1;
            }
            bool col_okay = true;
            for(int j = 0; j < N; ++j)
            {
                col_okay = col_okay && lawn.at(j).at(m) == 1;
            }
            all_okay = all_okay && (row_okay | col_okay);
        }
    }
    cout << "Case #" << t << ": " << (all_okay ? "YES" : "NO") << endl;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        testcase(t);
    }
}