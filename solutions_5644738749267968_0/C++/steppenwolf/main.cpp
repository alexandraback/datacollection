#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    vector<double> weights[2];
    int N;
    cin >> N;

    for (int i = 0; i < 2; ++i)
    {
        double weight;
        for (int j = 0; j < N; ++j)
        {
            cin >> weight;
            weights[i].push_back(weight);
        }
        sort(weights[i].begin(), weights[i].end());
    }

    int warPoints = 0, deceiptWarPoint = 0;
    vector<bool> used(N, false);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!used[j] && weights[0][i] < weights[1][j])
            {
                used[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (!used[i])
        {
            ++warPoints;
        }
    }

    for (int i = N - 1, j = N - 1; i >= 0 && j >= 0;)
    {
        if (weights[0][i] > weights[1][j])
        {
            deceiptWarPoint++;
            j--, i--;
        }
        else
        {
            j--;
        }
    }

    cout << deceiptWarPoint << " " << warPoints << endl;
}

int main()
{
    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test)
    {
        cout << "Case #" << test << ":" << endl;
        solve();
    }

    return 0;
}
