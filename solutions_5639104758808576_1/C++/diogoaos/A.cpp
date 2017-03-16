#include <cstdio>

char shy[1010];

int main() {
    int t, smax, acc, ans;
    
    scanf("%d", &t);
    
    for (int i = 1; i <= t; i++) {
        scanf("%d %s", &smax, shy);
        acc = ans = 0;
        
        for (int j = 0; j <= smax; j++) {
            if ( (shy[j] - '0') > 0 && acc < j) {
                ans += j - acc;
                acc = j;
            }
            acc += shy[j] - '0';
        }
        
        printf("Case #%d: %d\n", i, ans);
    }
    
    return 0;
}