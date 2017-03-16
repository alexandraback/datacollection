#include <bits/stdc++.h>

using namespace std;

const int MX = 60;
long long p2[MX];
string bad = "IMPOSSIBLE", good = "POSSIBLE";

void solve(int z)
{
    cout << "Case #" << z << ": ";
    int n;
    long long m;
    cin >> n >> m;
    if (m > p2[n - 2])
    {
        cout << bad << '\n';
    }
    else
    {
        cout << good << '\n';
        bool g[MX][MX];
        memset(g, false, sizeof(g));
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                g[i][j] = true;
            }
        }

        long long cur = p2[n - 2];
        int to_rem = 2;

        for (int i = n - 3; i >= 0; i--)
        {
            //cout << cur << " " << p2[i] << " " << to_rem << endl;
            if (cur - p2[i] >= m)
            {
                cur -= p2[i];
                g[1][to_rem] = false;
            }
            to_rem++;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << g[i][j];
            }
            cout << '\n';
        }
    }
}

int main()
{
    long long cp = 1;
    for (int i = 0; i < MX; i++)
    {
        p2[i] = cp;
        cp *= 2;
    }
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
}
