#include <cstdio>
#include <cstring>

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    scanf("%d", &t);
    
    for(int i = 0;i < t;i ++) {
        int n, s, p;
        scanf("%d%d%d", &n, &s, &p);
        
        int res = 0, num;
        for(int j = 0;j < n;j ++) {
            scanf("%d", &num);
            int val = num/3;
            if(num%3) ++ val;
            if(val >= p) {
                ++ res;
                continue;
            }
            
            if(val < p-1||s == 0) continue;
            
            if(num%3 != 1&&val > 0) {
                ++ res;
                -- s;
            }
        }
        
        printf("Case #%d: %d\n", i+1, res);
    }
    return 0;
}
