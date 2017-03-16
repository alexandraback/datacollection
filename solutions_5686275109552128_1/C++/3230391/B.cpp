#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void){
    int t, n, ys = 0, a[2000];
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        int maxx = 0, ans = 5000;
        scanf("%d", &n);
        for (int i = 0; i<n; i++){
            scanf("%d", a+i);
            maxx = max(maxx, a[i]);
        }
        for (int i = 1; i<=maxx; i++){
            int now = i;
            for (int j = 0; j<n; j++)
                now += (a[j] + i-1)/i - 1;
            ans = min(ans, now);
        }
        printf("Case #%d: %d\n", ++ys, ans);
    }
    return 0;
}
