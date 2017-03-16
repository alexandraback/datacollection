#include <cstdio>
#include <cstring>

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    scanf("%d", &t);
    
    for(int i = 0;i < t;i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        
        int num = 1, x = 0;
        
        while(a >= num) {
            num *= 10;
            ++ x;
        }
        
        num /= 10;
        
        int pre[10];
        
        int res = 0;
        for(int j = a;j <= b;j ++) {
            int tmp = j;
            int count = 0;
            for(int k = 1;k < x;k ++) {
                tmp = (tmp%num)*10 + tmp/num;
                if(tmp > j&&tmp <= b) {
                    int ii = 0;
                    for(ii = 0;ii < count;ii ++) if(tmp == pre[ii]) break;
                    if(ii >= count) {
                        ++ res;
                        pre[count ++] = tmp;
                        // printf("%d %d\n", j, tmp);
                    }
                }
            }
        }
        
        printf("Case #%d: %d\n", i+1, res);
    }
    return 0;
}
