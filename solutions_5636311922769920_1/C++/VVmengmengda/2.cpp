#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    freopen("D-large.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t, k, c, s, cas = 1, i, tmp2, tmp;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &k, &c, &s);
        printf("Case #%d: ", cas++);
        if(c == 1) {
            if(s < k) printf("IMPOSSIBLE\n");
            else {
                for(i = 1;i <= k;i++) {
                    if(i == k) printf("%d\n", i);
                    else printf("%d ", i);
                }
            }
            continue;
        }
        if(s < (k + 1) / 2) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        tmp = 0;
        tmp2 = k;
        for(i = 1;i <= (k + 1) / 2;i++) {
            if(i == (k + 1) / 2) printf("%d\n", tmp + tmp2);
            else printf("%d ", tmp + tmp2);
            tmp += k;
            tmp2--;
        }
    }
    return 0;
}
