#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

#define  clr(arr, x)  memset(arr, (x), sizeof(arr))
#define  rep(i, n)  for(int i = 0; i < (n); i++)
#define  repu(i, l, r)  for(int i = (l); i <= (r); i++)
#define  repd(i, r, l)  for(int i = (r); i >= (l); i--)
#define  MP  make_pair
#define  PB  push_back
#define  reget(str)  freopen(str, "r", stdin)
#define  vi  vector<int>

typedef long long llg;

int T, dp[15][6], v[15];
void run() {
    int e, r, n;
    scanf("%d", &T);
    repu(Case, 1, T) {
        scanf("%d%d%d", &e, &r, &n);
        repu(i, 1, n)  scanf("%d", v+i);
        clr(dp, -1);
        dp[0][e] = 0;
        rep(i, n)  repu(j, 0, e) {
            if(dp[i][j] == -1)  continue;
            repu(k, 0, j) {
                int tmp = min(j-k+r, e);
                if(dp[i+1][tmp]==-1 || dp[i+1][tmp]<dp[i][j]+k*v[i+1])
                    dp[i+1][tmp] = dp[i][j]+k*v[i+1];
            }
        }
        int ans = 0;
        repu(i, 1, n) repu(j, 0, e)  ans = max(ans, dp[i][j]);
        printf("Case #%d: %d\n", Case, ans);
    }
}

int main() {
	reget("data.in");
	freopen("data.out", "w", stdout);
	run();
	return  0;
}
















