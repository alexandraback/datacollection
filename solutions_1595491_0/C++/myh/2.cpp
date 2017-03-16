#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int min(int a, int b) {
    return a<b ? a:b;
}

int main() {
    freopen("myh2.in","r",stdin); 
    freopen("myh2.out","w",stdout);
    int tt, ans1, ans2, n, s, p, a;
    scanf("%d", &tt);
    for (int k = 1; k <= tt; ++k) {
        scanf("%d%d%d", &n, &s, &p);
        ans1 = 0;
        ans2 = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (a >= 3*p-2) ++ans1;
            if (a == 3*p-3 || a == 3*p-4) {
                if (a > 1) ++ans2;
            }
        }
        printf("Case #%d: %d\n", k, ans1+min(ans2,s));
            
    }
    
    return 0;
}
