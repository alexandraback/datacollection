#include <iostream>

using namespace std;

const int MAXN = 2000000;

bool vis[MAXN + 1] = {};

inline int getDigit(int x, int &basic)
{
    int ans = 0;
    do
    {
        basic *= 10;
        x /= 10;
        ans++;
    }
    while (x != 0);
    basic /= 10;
    return ans;
}

void solve(void)
{
    int l, r;
    cin >> l >> r;
    int ans = 0;
    int basic = 1;
    int digit = getDigit(l, basic);
    for (int i = l; i<= r; i++)
    {
        for (int j = 0, x = i; j < digit; j++, x = x % 10 * basic + x / 10)
        {
            if ((x > i) && (x <= r) && (!vis[x]))
            {
                vis[x] = true;
                ans++;
            }
        }
        for (int j = 0, x = i; j < digit; j++, x = x % 10 * basic + x / 10)
        {
            if ((x > i) && (x <= r))
            {
                vis[x] = false;
            }
        }
    }
    cout << ans << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    int numTest;
    cin >> numTest;
    for (int testCase = 1; testCase <= numTest; testCase++)
    {
        cout << "Case #" << testCase << ": ";
        solve();
    }
    return 0;
}

