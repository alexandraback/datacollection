#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, ans = 1e9, j, k;
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) scanf("%d", &a[j]);
        
        for (j = 1; j <= 1000; j++) {
            int sum = j;
            
            for (k = 0; k < n; k++) sum += (a[k] - 1) / j;
            
            ans = min(ans, sum);
        }
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}
