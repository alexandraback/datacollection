#include <cstdio>
#include <cstring>

using namespace std;

char s[101];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, ans = 0, j;
        
        scanf("%s", s);
        
        n = strlen(s);
        
        for (j = 0; j + 1 < n; j++) {
            if (s[j] != s[j + 1]) ans++;
        }
        
        if ((s[0] == '-' && ans % 2 == 0) || (s[0] == '+' && ans % 2 == 1)) ans++;
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}
