#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int64_t dp[101][101];
int64_t a[101],at[101],b[101],bt[101];
int main() {
    freopen("/Users/fengyelei/Desktop/in.in", "r", stdin);
    freopen("/Users/fengyelei/Desktop/out", "w", stdout);
    int T;scanf("%d",&T);
    for (int c=1; c<=T; c++) {
        int n, m, i, j, k;
        scanf("%d %d",&n,&m);
        for (i=0; i<n; i++) {
            scanf("%lld %lld",&a[i],&at[i]);
        }
        for (i=0; i<m; i++) {
            scanf("%lld %lld",&b[i],&bt[i]);
        }
        memset(dp, 0, sizeof(dp));
        int64_t res = 0;
        for (i=0; i<n; i++) {
            for (j=0; j<m; j++) {
                if (at[i] == bt[j]) {
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+min(a[i],b[j]));
                    int64_t c1=a[i], c2=b[j], p=i, q=j;
                    while (c1!=c2) {
                        if (c1<c2) {
                            p++;
                            while(p<n&&at[p]!=at[i]) p++;
                            if (p<n) dp[p+1][q+1] = max(dp[p+1][q+1], dp[i][j]+min(c2,a[p]+c1)), c1+=a[p];
                            else break;
                        }
                        else {
                            q++;
                            while(q<m&&bt[q]!=at[i]) q++;
                            if (q<m) dp[p+1][q+1] = max(dp[p+1][q+1], dp[i][j]+min(c1,c2+b[q])), c2+=b[q];
                            else break;
                        }
                    }
                }
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
                dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
            }
        }
        for (i=0; i<=n; i++) for(j=0;j<=m; j++) res = max(res, dp[i][j]);
        printf("Case #%d: %lld\n", c, res);
    }
}