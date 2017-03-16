#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <cassert>
#include <cmath>
#include <queue>

using namespace std;

const int N = 18;
const int oo = (1 << 30);

int dp[N][N], v[N];

int main()
{
    freopen("out.txt", "w", stdout);
    int tcas, cas = 0;
    cin >> tcas;
    while(tcas --)
    {
        int E, R, n;
        cin >> E >> R >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        memset(dp, -1, sizeof(dp));
        dp[0][E] = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= E; j++)
            {
                if(dp[i][j] == -1) continue;
                for(int k = 0; k <= j; k++)
                {
                    int nextJ = min(E, R + j - k);
                    dp[i + 1][nextJ] = max(dp[i + 1][nextJ], dp[i][j] + k * v[i]);
                }
            }
        }
        int ans = -oo;
        for(int i = 1; i <= E; i++)
        {
            if(dp[n][i] == -1) continue;
            ans = max(ans, dp[n][i]);
        }
        cout << "Case #" << ++cas << ": " << ans << endl;
    }
    return 0;
}
