#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 110
int f[MAXN][MAXN];
int a[MAXN];
int main(){
    int i, j, k, T, n, s, t, ans;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w", stdout);
    scanf("%d", &T);
    for (k = 1; k <= T; k++){
        scanf("%d%d", &s, &n);
        for (i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        ans = n;
        t = 0;
        for (i = 1; i <= n; i++){
            while(s <= a[i] && s > 1) s += s - 1, t++;
            if (s <= a[i]) break;
            s += a[i];
            if (t + n - i < ans) ans = t + n - i;
        }
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}
