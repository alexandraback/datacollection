#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int T;
    int prob = 1;
    for (cin >> T; T--; )
    {
        bool leaf[1001]; for (int i = 0; i < 1001; i++) {leaf[i] = true;}
        vector<int> inherits_from[1001];
        int N; cin >> N;
        for (int i = 1; i <= N; i++)
        {
            int count; cin >> count;
            while (count--)
            {
                int from; cin >> from;
                leaf[from] = false;
                inherits_from[i].push_back(from);
            }
        }

        bool singlyConnected = true;
        for (int i = 1; i <= N; i++)
        {
            if (leaf[i])
            {
                bool visited[1001];
                for (int j = 0; j < 1001; j++) { visited[j] = false; }
                queue<int> to_visit;
                to_visit.push(i);
                while (!to_visit.empty())
                {
                    int k = to_visit.front(); to_visit.pop();
                    //cout << "visiting " << k << " with leaf " << i << endl;
                    if (visited[k])
                    {
                        //cout << "leaf " << i << " already visited "
                           // << k << endl;
                        singlyConnected = false;
                        break;
                    }
                    visited[k] = true;
                    for (unsigned int j = 0; j < inherits_from[k].size(); j++)
                    {
                        to_visit.push(inherits_from[k][j]);
                    }
                }
            }
            if (!singlyConnected)
            {
                break;
            }
        }

        cout << "Case #" << prob++ << ": ";
        if (singlyConnected)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}

