#include <cstdio>

char a[1111];

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t; ++ti){
        int n;
        scanf("%d%s", &n, a);
        int s = 0, ans = 0;
        for(int i = 0; i <= n; i++){
            if(s < i){
                ans += i - s;
                s = i;
            }
            s += a[i] - '0';
        }
        printf("Case #%d: %d\n", ti, ans);
    }
    return 0;
}
