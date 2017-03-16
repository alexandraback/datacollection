//T-shirt is honor for programmers!
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <sstream>
#define inf 1000000007
#define eps 1e-8
#define M 105
#define For(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
int v[M];
int e, r, n;
int dp[M][M];

int main(int argc, char** argv) {
    freopen("123.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    int cs = 0;
    while (T--) {
        cs++;
        scanf("%d%d%d", &e, &r, &n);
        long long s = 0;
        For(i, 0, n)
        scanf("%d", &v[i]), s += v[i];
        if (e <= r) {
            printf("Case #%d: %lld\n", cs, s * e);
            continue;
        }
        //可以满足的组数
        memset(dp, -1, sizeof (dp));
        dp[0][e] = 0;

        For(i, 1, n + 1) {

            For(j, 0, e + 1) {
                if (dp[i-1][j] == -1)
                    continue;
                For(k,0,j+1){
                    dp[i][min(k+r,e)]=max(dp[i][min(k+r,e)],dp[i-1][j]+(j-k)*v[i-1]);
                }
//                dp[i][r] = max(dp[i][r], dp[i - 1][j] + j * v[i - 1]);
//                int t = j + r;
//                int c = min(t, e);
//                int d = 0;
//                if (t > e) {
//                    d = t - e;
//                }
//                dp[i][c] = max(dp[i][c], dp[i - 1][j] + d * v[i - 1]);
            }
        }

        printf("Case #%d: %d\n", cs,dp[n][r]);
    }

    return 0;
}

