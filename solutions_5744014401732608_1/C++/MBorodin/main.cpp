#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

typedef long long LL;

vector <vector <int> > g;
vector <LL> dp;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    LL t;
    cin >> t;
    for (LL i = 0;i < t;i++) {
        printf ("Case #%d: ", i + 1);
        LL b, m;
        cin >> b >> m;
        g.clear();
        g.resize(b);
        dp.clear();
        dp.resize(b);
        dp[0] = 1;
        dp[1] = 1;
        for (LL j = 0;j < b;j++) {
            g[j].resize(b);
        }
        for (LL j = 2;j < b;j++) {
            dp[j] = 2 * dp[j - 1];
        }
        if (dp[b - 1] < m) {
            printf ("IMPOSSIBLE\n");
            continue;
        }
        printf ("POSSIBLE\n");
        for (LL j = 0;j < b;j++)
        {
            for (LL k = 0;k < b;k++)
            {
                if (k > j){
                    g[j][k] = 1;
                }
                else{
                    g[j][k] = 0;
                }
            }
        }
        LL her = b - 2;
        LL razn = dp[b - 1] - m;
        while (razn > 0)
        {
            if (razn >= dp[her]){
                g[her][b - 1] = 0;
                razn -= dp[her];
            }
            her--;
        }
        for (LL j = 0;j < b;j++){
            for (LL k = 0;k < b;k++){
                printf ("%d", g[j][k]);
            }
            printf ("\n");
        }
    }
    return 0;
}
