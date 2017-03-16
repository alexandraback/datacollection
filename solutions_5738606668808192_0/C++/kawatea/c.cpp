#include <cstdio>

using namespace std;

char s[33];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, j, c = 0, k, l;
        
        scanf("%d %d", &n, &j);
        
        printf("Case #%d:\n", i + 1);
        
        s[0] = s[1] = s[n - 1] = s[n - 2] = '1';
        
        for (k = 0; ; k++) {
            for (l = 2; l < n - 2; l += 2) {
                if ((k >> ((l - 2) / 2)) & 1) {
                    s[l] = s[l + 1] = '1';
                } else {
                    s[l] = s[l + 1] = '0';
                }
            }
            
            printf("%s 3 2 5 2 7 2 3 2 11\n", s);
            
            c++;
            
            if (c == j) break;
        }
    }
    
    return 0;
}
