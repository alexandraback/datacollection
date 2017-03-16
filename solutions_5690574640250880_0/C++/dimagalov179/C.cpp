#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, amount;
pair<int, int> start;
vector<vector<bool> > used;
vector<pair<int, int> > D;

int to_int(int a, int b)
{
    return a * m + b;
}

bool can_go(int a, int b)
{
    return a >= 0 && a < n && b >= 0 && b < m;
}

void dfs(vector<bool> & field, pair<int, int> current)
{
    used[current.first][current.second] = true;
    int mines = 0;
    for (int i = 0; i < D.size(); ++i)
        if (can_go(current.first + D[i].first, current.second + D[i].second))
            if (field[to_int(current.first + D[i].first, current.second + D[i].second)])
                ++mines;
    if (mines == 0)
        for (int i = 0; i < D.size(); ++i)
            if (can_go(current.first + D[i].first, current.second + D[i].second) && !used[current.first + D[i].first][current.second + D[i].second])
                dfs(field, make_pair(current.first + D[i].first, current.second + D[i].second));
}

bool check(vector<bool> & field)
{
    for (int i = 0; i <= 0; ++i)
    {
        for (int j = 0; j <= 0; ++j)
        {
            if (field[to_int(i, j)] == false)
            {
                start = make_pair(i, j);
                used.assign(n, vector<bool>(m, false));
                dfs(field, start);
                bool is_good = true;
                for (int ii = 0; ii < n; ++ii)
                {
                    for (int jj = 0; jj < m; ++jj)
                    {
                        if (field[to_int(ii, jj)] == false && !used[ii][jj])
                        {
                            is_good = false;
                            break;
                        }
                    }
                }
                if (is_good)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    ifstream cin("input.txt");
    // ofstream cout("output.txt");
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            if (i != 0 || j != 0)
                D.push_back(make_pair(i, j));
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        cin >> n >> m >> amount;
        vector<bool> field(n * m, true);
        for (int i = 0; i < n * m - amount; ++i)
            field[i] = false;
        bool found = false;
        do
        {
            // for (int i = 0; i < field.size(); ++i)
            //     cout << (field[i] ? 1 : 0);
            // cout << endl;
            if (check(field))
            {
                found = true;
                break;
            }
            // random_shuffle(field.begin(), field.end());
        } while (next_permutation(field.begin(), field.end()));

        cout << "Case #" << q + 1 << ":" << endl;
        if (!found)
            cout << "Impossible" << endl;
        else
            for (int i = 0; i < field.size(); ++i)
                cout << (i == to_int(start.first, start.second) ? "c" : (field[i] ? "*" : ".")) << ((i + 1) % m == 0 ? "\n" : "");
    }
}