#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int grid[10][10];
vector<int> g[10];
int vis[10];

bool can_walk(vector<int> perm)
{
    int city = perm[0];
    stack<int> cities;
    cities.push(city);
    memset(vis, 0, sizeof(vis));
    int i;
    for (i = 1; i < perm.size(); ++i)
    {
        vis[city] = 1;
        if (!grid[city][perm[i]])
        {
            if (cities.empty()) return false;
            city = cities.top();
            cities.pop();
            --i;
        }
        else
        {
            cities.push(city);
            city = perm[i];
        }
    }
    return i == perm.size();
}

int main()
{
    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test)
    {
        memset(grid, 0, sizeof(grid));
        int n, m;
        cin >> n >> m;

        vector<string> codes(n);

        vector<int> perm(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> codes[i];
            perm[i] = i + 1;
        }

        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            grid[a][b] = grid[b][a] = 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        string res;
        do
        {
            if (can_walk(perm))
            {
                string r;
                for (int i = 0; i < n; ++i)
                {
                    r += codes[perm[i] - 1];
                }
                if (res.size() == 0 || r < res) res = r;
            }
        }
        while(next_permutation(perm.begin(), perm.end()));

        cout << "Case #" << test << ": " << res << endl;
    }

    return 0;
}
