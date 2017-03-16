#include <iostream>

using namespace std;

int T;
int e, r, n;
int values[10000020];
int cache[10][20];

int dp(int en, int at)
{
    if (at >= n) return 0;
    if (cache[en][at] != -1) return cache[en][at];
    int ans = -1;
    for (int i = 0; i <= en; i++)
    {
        ans = max(ans, dp(min(e, en - i + r), at + 1) + i * values[at]);
    }
    cache[en][at] = ans;
    return ans;
}

int main()
{
    cin >> T;
    for (int c = 1; c <= T; c++)
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 20; j++)
                cache[i][j] = -1;
        cin >> e >> r >> n;
        for (int i = 0; i < n; i++)
            cin >> values[i];
        cout << "Case #" << c << ": " << dp(e, 0) << '\n';
    }
    return 0;
}

