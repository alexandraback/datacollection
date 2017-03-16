#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1012;

int T,D;
int P[maxn];

int main() {
    freopen("/Users/zhanghanyuan/Documents/codejam/Qualification/B1.in","r",stdin);
    freopen("/Users/zhanghanyuan/Documents/codejam/Qualification/B1.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
        scanf("%d",&D);
        int w = 0;
        for (int i = 1;i <= D; i++) {
                scanf("%d",&P[i]);
                if (w < P[i]) w = P[i];
        }
        int ans = w;
        for (int i = 1;i <= w; i++) {
            int s = 0;
            for (int j = 1;j <= D; j++) {
                int k = (P[j]-1)/i;
                s += k;
            }
            if (s+i <= ans) ans = s+i;
        }
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
