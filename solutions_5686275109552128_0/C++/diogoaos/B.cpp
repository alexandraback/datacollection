#include <cstdio>

int p[1010];

int main() {
    int t, d, mp, stops;
    
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        scanf("%d", &d);
        mp = 0;
        
        for (int j = 0; j < d; j++) {
            scanf("%d", &p[j]);
            if (p[j] > mp) {
                mp = p[j];
            }
        }
        
        for (int maxSize = 1; maxSize <= mp; maxSize++) {
            stops = 0;
            for (int j = 0; j < d; j++) {
                stops += ((p[j] + maxSize - 1) / maxSize) - 1;
            }
            
            if (maxSize + stops < mp) {
               mp = maxSize + stops;
            }
        }
        
        printf("%d\n", mp);
    }
    return 0;
}