#include <bits/stdc++.h>

using namespace std;

static void recurse(string &coin, int pos, vector<string> &coins)
{
    int N = coin.size();
    if (pos == N)
        coins.push_back(coin);
    else
    {
        recurse(coin, pos + 1, coins);
        if (pos + 3 < N && coin[pos] == '0' && coin[pos + 3] == '0')
        {
            coin[pos] = '1';
            coin[pos + 3] = '1';
            recurse(coin, pos + 1, coins);
            coin[pos] = '0';
            coin[pos + 3] = '0';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int T, N, J;
    cin >> T >> N >> J;
    string coin(N, '0');
    coin[0] = '1';
    coin[3] = '1';
    coin[N - 4] = '1';
    coin[N - 1] = '1';
    vector<string> coins;
    recurse(coin, 0, coins);
    assert(int(coins.size()) >= J);
    cout << "Case #1:\n";
    for (int i = 0; i < J; i++)
    {
        cout << coins[i];
        for (int j = 2; j <= 10; j++)
            cout << ' ' << j * j - j + 1;
        cout << '\n';
    }
    return 0;
}
