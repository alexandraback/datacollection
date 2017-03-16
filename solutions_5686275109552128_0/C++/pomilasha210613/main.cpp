#include <bits/stdc++.h>

using namespace std;

const int inf = 1000 * 1000 * 1000;

int dp[1005][1005], n, res;
vector <int> mass;

void input()
{
    cin >> n;
    mass.clear();
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        mass.push_back(m);
    }
}

void CountDP()
{
    for (int i = 1; i <= 1000; ++i)
        for (int j = i + 1; j <= 1000; ++j)
        {
            dp[i][j] = j;
            for (int k = 1; k < j; ++k)
                if (dp[i][j] > dp[i][k] + dp[i][j - k] + 1)
                    dp[i][j] = dp[i][k] + dp[i][j - k] + 1;
        }
}


int main()
{
    freopen("aaa.in","r",stdin);
    freopen("aaa.out","w",stdout);
    CountDP();
    int test;
    cin >> test;
    for (int i = 0; i < test; ++i)
    {
        input();
        res = inf;
        for (int j = 1; j <= 1000; ++j)
        {
            int kol = 0;
            for (int k = 0; k < n; ++k)
                kol = kol + dp[j][mass[k]];
            if (res > kol + j)
                res = kol + j;
        }
        cout << "Case #" << i + 1 << ": " << res;
        cout << '\n';
    }
    return 0;
}
