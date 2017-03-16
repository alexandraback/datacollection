#include <set>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int T, N, M;
    cin >> T;
    for (int task = 1; task <= T; task++)
    {
        cout << "Case #" << task << ": ";
        cin >> N >> M;
        vector<vector<int> > lawn(N);
        set<int> numbers;
        for (int i = 0; i < N; i++)
        {
            lawn[i].resize(M);
            for (int j = 0; j < M; j++)
            {
                cin >> lawn[i][j];
                numbers.insert(lawn[i][j]);
            }
        }
        vector<int> row(N), col(M);
        bool result = true;
        for (set<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it)
        {
            for (int i = 0; i < N && result; i++)
                for (int j = 0; j < M; j++)
                {
                    if (lawn[i][j] != *it) continue;
                    if (row[i] > *it && col[j] > *it)
                    {
                        result = false;
                        break;
                    }
                    else
                    {
                        row[i] = max(row[i], *it);
                        col[j] = max(col[j], *it);
                    }
                }
        }
        cout << (result ? "YES" : "NO") << endl;
    }
    return 0;
}
