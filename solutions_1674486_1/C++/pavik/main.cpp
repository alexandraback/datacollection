#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool search_diamond(const vector<vector<size_t> >& g, size_t v)
{
    vector<size_t> discovered(g.size(), 0);
    queue<size_t> q;
    q.push(v);

    while (!q.empty())
    {
        size_t u = q.front();
        for (size_t i = 0; i < g[u].size(); ++i)
        {
            size_t vertex = g[u][i];
            ++discovered[vertex];
            q.push(vertex);
            if (discovered[vertex] > 1)
                return true;
        }

        q.pop();
    }

    return false;
}

bool has_diamond(const vector<vector<size_t> >& g)
{
    for (size_t i = 1; i < g.size(); ++i)
        if (g[i].size() > 1)
            if (search_diamond(g, i))
                return true;

    return false;
}

int main()
{
    size_t n = 0;
    cin >> n;

    for (size_t t = 1; t <= n; ++t)
    {
        size_t N = 0;
        cin >> N;

        vector<vector<size_t> > g;
        g.push_back(vector<size_t>());
        for (size_t j = 0; j < N; ++j)
        {
            size_t mi = 0;
            cin >> mi;

            vector<size_t> adj_list;
            while (mi)
            {
                size_t adj = 0;
                cin >> adj;
                adj_list.push_back(adj);
                --mi;
            }
            g.push_back(adj_list);
        }

        if (has_diamond(g))
            cout << "Case #" << t << ": Yes" << endl;
        else
            cout << "Case #" << t << ": No" << endl;
    }

    return 0;
}