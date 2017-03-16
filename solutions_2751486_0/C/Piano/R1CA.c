#include<stdio.h>

#define f(x, y) (((x) - (y) + 2) * ((x) - (y) + 1) / 2)

int iscon(char c){
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int b[500000], e[500000];

int main(){
    int t, u;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        int n, i, j, now = 0, c = 0;
        char s[1000001];
        long long l, sum = 0;
        scanf("%s%d", s, &n);
        for (i = j = 0 ; s[i] ; ++i){
            if (iscon(s[i])){
                if (!now) j = i, now = 1;
            }
            else if (now){
                now = 0;
                if (i - j >= n)
                    b[c] = j, e[c++] = i;
            }
        }
        if (now && i - j >= n)
            b[c] = j, e[c++] = i;
        l = i;
        if (!c)printf("Case #%d: 0\n", u);
        else {
            if (b[0] != 0)sum += f(b[0] + n - 1, n);
            for (i = 1 ; i < c ; ++i)
                sum += f(b[i] - e[i - 1] + n + n - 2, n);
            if (e[c - 1] != l)
                sum += f(l - e[c - 1] + n - 1, n);
            printf("Case #%d: %I64d\n", u, f(l, n) - sum);
        }
    }
    return 0;
}
