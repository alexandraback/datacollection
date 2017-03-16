#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long na[110], nb[110];
int xa[110], xb[110], n, m;
long long dp[110][110][2][2];
void dfs(int x, int y){
    int i;
    long long t, s, tt, ss;
    if (x == n || y == m){
        dp[x][y][0][0] = dp[x][y][0][1] = 0;
        dp[x][y][1][0] = dp[x][y][1][1] = 0;
        return;
    }
    if (dp[x][y][0][0] >= 0) return;
    dfs(x + 1, y + 1);
    dp[x][y][0][0] = max(dp[x + 1][y + 1][0][0], dp[x + 1][y + 1][1][0]);
    dp[x][y][1][0] = max(dp[x + 1][y + 1][0][0], dp[x + 1][y + 1][1][0]);
    dp[x][y][0][1] = na[x];
    dp[x][y][1][1] = nb[y];
    t = 0;
    s = na[x];
    for (i = y; i < m; i++){
        dfs(x + 1, i);
        tt = t + dp[x + 1][i][1][0];
        ss = s;
        if (xa[x] == xb[i]){
            tt += min(s, dp[x + 1][i][1][1]);
            ss -= min(s, dp[x + 1][i][1][1]);
        }
        if (tt > dp[x][y][0][0]){
            dp[x][y][0][0] = tt;
            dp[x][y][0][1] = ss;
        }else if (tt == dp[x][y][0][0]){
            dp[x][y][0][0] = tt;
            dp[x][y][0][1] = max(ss, dp[x][y][0][1]);
        }
        tt = t + dp[x + 1][i][0][0];
        ss = s;
        if (tt > dp[x][y][0][0]){
            dp[x][y][0][0] = tt;
            dp[x][y][0][1] = ss;
        }else if (tt == dp[x][y][0][0]){
            dp[x][y][0][0] = tt;
            dp[x][y][0][1] = max(ss, dp[x][y][0][1]);
        }
        if (xa[x] == xb[i]){
            t += min(s, nb[i]);
            s -= min(s, nb[i]);
        }
    }
    tt = t;
    ss = s;
    if (tt > dp[x][y][0][0]){
        dp[x][y][0][0] = tt;
        dp[x][y][0][1] = ss;
    }else if (tt == dp[x][y][0][0]){
        dp[x][y][0][0] = tt;
        dp[x][y][0][1] = max(ss, dp[x][y][0][1]);
    }
    t = 0;
    s = nb[y];
    for (i = x; i < n; i++){
        dfs(i, y + 1);
        tt = t + dp[i][y + 1][0][0];
        ss = s;
        if (xa[i] == xb[y]){
            tt += min(s, dp[i][y + 1][0][1]);
            ss -= min(s, dp[i][y + 1][0][1]);
        }
        if (tt > dp[x][y][1][0]){
            dp[x][y][1][0] = tt;
            dp[x][y][1][1] = ss;
        }else if (tt == dp[x][y][1][0]){
            dp[x][y][1][0] = tt;
            dp[x][y][1][1] = max(ss, dp[x][y][1][1]);
        }
        tt = t + dp[i][y + 1][1][0];
        ss = s;
        if (tt > dp[x][y][1][0]){
            dp[x][y][1][0] = tt;
            dp[x][y][1][1] = ss;
        }else if (tt == dp[x][y][1][0]){
            dp[x][y][1][0] = tt;
            dp[x][y][1][1] = max(ss, dp[x][y][1][1]);
        }
        if (xa[i] == xb[y]){
            t += min(s, na[i]);
            s -= min(s, na[i]);
        }
    }
    tt = t;
    ss = s;
    if (tt > dp[x][y][1][0]){
        dp[x][y][1][0] = tt;
        dp[x][y][1][1] = ss;
    }else if (tt == dp[x][y][1][0]){
        dp[x][y][1][0] = tt;
        dp[x][y][1][1] = max(ss, dp[x][y][1][1]);
    }
}
int main(){
    int T, ri = 1, i, t;
    freopen("C-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++){
            scanf("%lld%d", &na[i], &xa[i]);
        }
        t = 0;
        for (i = 1; i < n; i++){
            if (xa[i] == xa[t]){
                na[t] += na[i];
            }else{
                t++;
                xa[t] = xa[i];
                na[t] = na[i];
            }
        }
        n = t + 1;
        for (i = 0; i < m; i++){
            scanf("%lld%d", &nb[i], &xb[i]);
        }
        t = 0;
        for (i = 1; i < m; i++){
            if (xb[i] == xb[t]){
                nb[t] += nb[i];
            }else{
                t++;
                xb[t] = xb[i];
                nb[t] = nb[i];
            }
        }
        m = t + 1;
        memset(dp, -1, sizeof(dp));
        dfs(0, 0);
        printf("Case #%d: %lld\n", ri++, max(dp[0][0][0][0], dp[0][0][1][0]));
    }
    return 0;
}
