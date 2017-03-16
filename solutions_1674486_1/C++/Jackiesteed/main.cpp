#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <iomanip>




using namespace std;

const int MAXN = 1100;
typedef long long LL;
int T;
int N;

LL dp[MAXN][MAXN];


int g[MAXN][100];
int M[MAXN];
bool vis[MAXN];

void DP(int x)
{
    if(vis[x]) return;

    vis[x] = true;
    for(int i = 0; i < M[x]; i++)
    {
        int y = g[x][i];
        dp[x][y] += 1;
        DP(y);
        for(int j = 1; j <= N; j++)
        {
            dp[x][j] += dp[y][j];
        }
    }
}



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;
    for(int ncase = 1; ncase <= T; ncase++)
    {

        cin >> N;

        for(int i = 1; i <= N; i++)
        {
            cin >> M[i];
            for(int j = 0; j < M[i]; j++)
            {
                cin >> g[i][j];
            }
        }
        memset(dp, 0, sizeof(dp));
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= N; i++)
        {
            DP(i);
        }
        bool bingo = false;
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(dp[i][j] >= 2)
                {
                    bingo = true;
                    break;
                }
            }
            if(bingo) break;
        }


        cout << "Case #" << ncase << ": ";
        if(bingo) cout << "Yes" << endl;
        else cout << "No" << endl;
    }













    return 0;
}

