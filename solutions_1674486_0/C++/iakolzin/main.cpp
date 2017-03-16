#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > gr;
vector <bool> w;

bool DFS(int v, bool ret)
{
    if (ret && w[v])
        return true;
    w[v] = true;
    for (int i = 0; i < gr[v].size(); i++)
        if (DFS(gr[v][i], v))
            return true;
    return false;
}

bool Solve()
{
    for (int i = 0; i < gr.size(); i++)
        for (int j = 0; j < gr[i].size(); j++)
            for (int k = j + 1; k < gr[i].size(); k++)
            {
                w.assign(gr.size(), false);
                DFS(gr[i][j], false);
                if (DFS(gr[i][k], true))
                    return true;
            }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        int n;
        cin >> n;
        gr.clear();
        gr.resize(n);
        w.assign(n, false);
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                x--;
                gr[i].push_back(x);
            }
        }
        bool res = Solve();
        printf("Case #%d: ", t + 1);
        if (res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}