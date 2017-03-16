#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

template <class It>
bool possible(const vector<vector<int> >& adj, const vector<vector<bool> >& mat, It prefix, It prefixEnd)
{
    int N = (int)adj.size();
    vector<bool> visited(N, false);
    stack<int> s;
    s.push(*prefix);
    visited[*prefix] = true;
    for (++prefix; prefix != prefixEnd; ++prefix)
    {
        while (true)
        {
            if (s.empty())
                return false;
            if (mat[s.top()][*prefix])
                break;
            s.pop();
        }
        s.push(*prefix);
        visited[*prefix] = true;
    }
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        for (auto it = adj[t].begin(); it != adj[t].end(); ++it)
        {
            if (!visited[*it])
            {
                s.push(*it);
                visited[*it] = true;
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase)
    {
        int N, M;
        cin >> N >> M;
        vector<pair<int, int> > zips(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> zips[i].first;
            zips[i].second = i;
        }
        sort(zips.begin(), zips.end());
        vector<int> perm(N);
        for (int i = 0; i < N; ++i)
            perm[zips[i].second] = i;
        vector<vector<int> > adj(N);
        vector<vector<bool> > mat(N);
        for (int i = 0; i < N; ++i)
            mat[i].assign(N, false);
        for (int i = 0; i < M; ++i)
        {
            int x, y;
            cin >> x >> y;
            int u = perm[x - 1];
            int v = perm[y - 1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            mat[u][v] = true;
            mat[v][u] = true;
        }
        vector<int> path(N);
        vector<bool> used(N, false);
        path[0] = 0;
        used[0] = true;
        for (int prefixLen = 2; prefixLen <= N; ++prefixLen)
        {
            for (int i = 0; i < N; ++i)
            {
                if (!used[i])
                {
                    used[i] = true;
                    path[prefixLen - 1] = i;
                    if (possible(adj, mat, path.begin(), path.begin() + prefixLen))
                        break;
                    used[i] = false;
                }
            }
        }
        cout << "Case #" << testcase << ": ";
        for (int i = 0; i < N; ++i)
            cout << zips[path[i]].first;
        cout << "\n";
    }
    return 0;
}
