#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <vector<int> > g;
vector <int> used;
int n;

int t;

bool dfs(int v)
{
    if (used[v] == 2)
        return true;
    if (used[v] == 1)
        return true;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (dfs(g[v][i])) return true;
    }
    used[v] = 2;
    return false;
}

bool Go()
{
    for (int i = 0; i < n; i++)
    {
        used.assign(n, 0);
        if (dfs(i)) return true;
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        g.clear();
        cin >> n;
        g.resize(n);
        used.assign(n, 0);
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            for (int l = 0; l < k; l++)
            {
                int elem;
                cin >> elem;
                elem--;
                g[j].push_back(elem);
            }
        }
        if (Go())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
