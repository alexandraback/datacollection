#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[101], n, m;
void init(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
}

void solve(){
    int ans = n, add = 0;
    for (int i = 1; i <= n; i++) {
        while (m <= a[i]) {
            add++;
            m += m - 1;
            if (add > a[n]) {
                printf("%d\n", n);
                return;
            }
        }
        m += a[i];
        ans = min(ans, add + n - i);
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        init();
        solve();
    }
}
