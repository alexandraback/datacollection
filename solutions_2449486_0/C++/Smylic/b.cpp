#include <iostream>

using namespace std;

int a[128][128];
int v[128][128];
int n, m, k;

bool dfs(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return true;

    if (v[i][j] || a[i][j] > k)
        return false;

    bool res = false;
    v[i][j] = 1;

    res |= dfs(i-1, j);
    res |= dfs(i, j-1);
    res |= dfs(i+1, j);
    res |= dfs(i, j+1);

    return res;
}

int main()
{
    int t;
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        cin >> n >> m;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cin >> a[i][j];

        bool ok = true;

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            {
                bool x = true;
                for (int k=0; k<n; k++)
                    x &= a[k][j] <= a[i][j];
                if (x)
                    continue;
                x = true;
                for (int k=0; k<m; k++)
                    x &= a[i][k] <= a[i][j];
                ok &= x;
            }

        cout << "Case #" << tt << ": " << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
