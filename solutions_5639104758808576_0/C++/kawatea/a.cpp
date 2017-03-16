#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char s[1002];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, ans = 0, j, k;
        vector <int> v;
        
        scanf("%d %s", &n, s);
        
        for (j = 0; j <= n; j++) {
            for (k = 0; k < s[j] - '0'; k++) v.push_back(j);
        }
        
        for (j = 0; j < v.size(); j++) ans = max(ans, v[j] - j);
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}
