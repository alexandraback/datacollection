#include <cstdio>
#include <algorithm>

using namespace std;

long long a[100];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int k, c, s, j, l;
        
        scanf("%d %d %d", &k, &c, &s);
        
        printf("Case #%d:", i + 1);
        
        if (c * s < k) {
            puts(" IMPOSSIBLE");
        } else {
            a[0] = 1;
            
            for (j = 1; j < c; j++) a[j] = a[j - 1] * k;
            
            for (j = 0; ; j++) {
                long long ans = 1;
                
                for (l = 0; l < c; l++) {
                    int x = min(j * c + l, k - 1);
                    
                    ans += a[c - l - 1] * x;
                }
                
                printf(" %lld", ans);
                
                if ((j + 1) * c >= k) break;
            }
            
            puts("");
        }
    }
    
    return 0;
}
