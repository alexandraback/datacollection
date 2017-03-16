#include<bits/stdc++.h>

#define MOD 1000000007
#define MODSET(d) if ((d) >= MOD) d %= MOD;

using namespace std;

int graph[10][10];
int t, n, m;
bool possible;
bool goodGraph;

bool visited[10];

int paths(int u, int target)
{
    visited[u] = true;

    if (u == target)
    {
        visited[u] = false;
        return 1;
    }
    else
    {
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (graph[u][i] && visited[i])
            {
                goodGraph = false;
            }
            else if (graph[u][i])
            {
                ans += paths(i, target);
            }
        }

        visited[u] = false;

        return ans;
    }
}

void generategraph(int i, int j)
{
    if (j == n)
        generategraph(i+1, 0);
    else if (i == n-1)
    {
        memset(visited, false, sizeof(visited));
        goodGraph = true;

        if (paths(0, n-1) == m)
        {
            if (goodGraph)
            {
                cout << "Case #" << t << ": POSSIBLE\n";
                possible = true;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << graph[i][j];
                    }
                    cout << "\n";
                }
            }
        }
    }
    else if (i == j)
        generategraph(i, j+1);
    else
    {
        if (i < j)
        {
            graph[i][j] = false;
            generategraph(i, j+1);

            if (possible)
                return;

            graph[i][j] = true;
            generategraph(i, j+1);
        }
        else
        {
            graph[i][j] = !graph[j][i];
            generategraph(i, j+1);
        }
    }
}

int main()
{
    #ifdef VSP4
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // VSP4

    int T, i, j, k, d;
    char c;

    cin >> T;

    for (t = 1; t <= T; t++)
    {
        cin >> n >> m;

        memset(graph, false, sizeof(graph));

        possible = false;

        generategraph(0, 0);

        if (!possible)
        {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        }

    }

    return 0;
}
