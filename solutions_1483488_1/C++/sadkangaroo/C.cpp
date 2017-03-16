#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<cctype>
#include<climits>
#include<algorithm>
#include<complex>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long LL;

int ans;
int T, A, B;
int vis[2000000 + 5];

void solve(int x) {
   int t0 = 10; while (t0 <= x) t0 *= 10;
   int y;
   for (int tt = 10; x >= tt; tt *= 10) {
       y = x / tt + x % tt * (t0 / tt); 
       if (y >= (tt / 10) && y > x && y <= B && vis[y] != x) {
           ans++;
           vis[y] = x;
       }
   }
}

int main() {

    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    scanf("%d", &T);
    for (int te = 1; te <= T; ++te) {
        memset(vis, 0, sizeof(vis));
        ans = 0;
        scanf("%d%d", &A, &B);
        for (int x = A; x <= B; ++x)
            solve(x);
        printf("Case #%d: %d\n", te, ans);
    }

    return 0;

}

