#include<stdio.h>

int main(){
    int t, u;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        int a, n, i, j, top = 0, cnt = 0, min = 99999999;
        int s[100];
        scanf("%d%d", &a, &n);
        for (i = 0 ; i < n ; ++i){
            int x;
            scanf("%d", &x);
            for (j = i ; j > 0 ; --j){
                if (x >= s[j - 1])break;
                s[j] = s[j - 1];
            }
            s[j] = x;
        }
        if (a == 1){
            printf("Case #%d: %d\n", u, n);
            continue;
        }
        for (i = 0 ; i < n ; ++i){
            if (n - i + cnt < min)min = n - i + cnt;
            for (; a <= s[i] ; ++cnt)
                a += a - 1;
            a += s[i];
        }
        if (cnt < min)min = cnt;
        printf("Case #%d: %d\n", u, min);
    }
    return 0;
}
