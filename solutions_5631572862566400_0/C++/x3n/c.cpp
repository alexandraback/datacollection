#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

const int MAXN = 1000;

unordered_set<int> pre[MAXN];
int succ[MAXN], iter_visited[MAXN];
bool visited[MAXN];
bool dfs_prev_called;

int dfs_prev(int vertex);
int dfs_succ(int vertex);

int dfs_prev(int vertex)
{
    dfs_prev_called = true;
    //cout << "dfs_prev " << vertex + 1 << endl;

    int m = 0;

    for (int v : pre[vertex]) {
        if (!visited[v]) {
            visited[v] = true;
            if (succ[v] == vertex)
                m = max(m, max(dfs_succ(v), dfs_prev(v)));
            else m = max(m, dfs_prev(v));
        }
    }

    return m + 1;
}

int dfs_succ(int vertex)
{
    //cout << "dfs_succ " << vertex + 1 << endl;

    if (!visited[succ[vertex]]) {
        visited[succ[vertex]] = true;
        if (succ[succ[vertex]] == vertex)
            return 1 + max(dfs_succ(succ[vertex]), dfs_prev(succ[vertex]));
        else return 1 + dfs_succ(succ[vertex]);
    }

    return 1;
}

int dfs(int vertex)
{
    int cur = vertex, count = 0;
    while (iter_visited[cur] == 0) {
        iter_visited[cur] = ++count;
        cur = succ[cur];
    }
    return count - iter_visited[cur] + 1;
}

int main()
{
    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            pre[i].clear();
        }
        for (int i = 0; i < n; i++) {
            int f;
            cin >> f;
            succ[i] = f - 1;
            pre[f - 1].insert(i);
        }

        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[j] = false;
                iter_visited[j] = 0;
            }

            dfs_prev_called = false;
            visited[i] = true;

            int d = dfs_succ(i);

            if (dfs_prev_called)
                m = max(m, d);
            else {
                m = max(m, dfs(i));
            }

            //cout << endl;
        }

        cout << "Case #" << tt << ": " << m << endl;
    }

    return 0;
}
