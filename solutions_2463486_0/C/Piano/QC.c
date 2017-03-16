#include<stdio.h>

int main(){
    int t, u, i, cnt = 0;
    long long num[39];
    for (i = 1 ; i <= 2001002 ; ++i){
        char s[21] = {};
        long long sq = (long long)i * i, j = (long long)i * i;
        int c = 0;
        while (j){
            s[c++] = j % 10 + '0';
            j /= 10;
        }
        sscanf(s, "%I64d", &j);
        if (sq == j){
            char ss[21] = {};
            j = i, c = 0;
            while (j){
                ss[c++] = j % 10 + '0';
                j /= 10;
            }
            sscanf(ss, "%I64d", &j);
            if (i == j){
                num[cnt++] = sq;
            }
        }
    }
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        long long a, b;
        int l, r, m, x, y;
        scanf("%I64d%I64d", &a, &b);
        for (l = 0, r = 39 ; l < r ; ){
            m = (l + r) / 2;
            if (num[m] == a){
                l = m;
                break;
            }
            else if (num[m] < a)
                l = m + 1;
            else r = m;
        }
        x = l;
        for (l = 0, r = 39 ; l < r ; ){
            m = (l + r) / 2;
            if (num[m] <= b){
                l = m + 1;
            }
            else r = m;
        }
        y = l;
        printf("Case #%d: %d\n", u, y - x);
    }
    return 0;
}
