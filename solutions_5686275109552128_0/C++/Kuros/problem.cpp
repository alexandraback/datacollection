#include <stdio.h>
#include <set>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define MAXN 110111
#define tl(x) (x << 1)
#define tr(x) (x << 1 | 1)

int T;

int n;
int bx[1010];

int main()
{
    freopen("pro.in","r",stdin);
    freopen("pro.out","w",stdout);
    
    int cas = 1;

    scanf("%d", &T);

    while(T--) {
        int mx = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &bx[i]);
            mx = max(mx, bx[i]);
        }
        int ans = mx;
        for(int i = 1; i <= mx; i++) {
            int rs = 0;
            for(int j = 1; j <= n; j++) {
                if(bx[j] > i) rs += (bx[j] - 1) / i;
            }
            ans = min(ans, rs + i);
        }
        printf("Case #%d: %d\n", cas++, ans);
    }

    
    return 0;
}