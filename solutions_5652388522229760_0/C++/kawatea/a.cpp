#include <cstdio>

using namespace std;

int a[10];

int check(long long x) {
    int i;
    
    while (x > 0) {
        a[x % 10] = 1;
        x /= 10;
    }
    
    for (i = 0; i < 10; i++) {
        if (a[i] == 0) return 0;
    }
    
    return 1;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, j;
        
        scanf("%d", &n);
        
        if (n == 0) {
            printf("Case #%d: INSOMNIA\n", i + 1);
            
            continue;
        }
        
        for (j = 0; j < 10; j++) a[j] = 0;
        
        for (j = 1; ; j++) {
            long long x = (long long)n * j;
            
            if (check(x) == 1) {
                printf("Case #%d: %lld\n", i + 1, x);
                
                break;
            }
        }
    }
    
    return 0;
}
