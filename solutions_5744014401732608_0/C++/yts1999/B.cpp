#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int mp[60][60];

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ",t);
        int n;
        long long m;
        scanf("%d%lld",&n,&m);
        if ((1ll << (n - 2)) < m) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        else
            printf("POSSIBLE\n");
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i < j)
                    mp[i][j] = 1;
                else
                    mp[i][j] = 0;
        long long cnt = (1ll << (n - 2)) - m;
        if (cnt != 0) {
            cnt--;
            mp[1][n] = 0;
        }
        for (int i = n - 1; i > 1; i--)
            if (cnt & (1 << (n - i - 1)))
                mp[1][i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                printf("%d",mp[i][j]);
            printf("\n");
        }
    }
    return 0;
}
