#include<stdio.h>
#define N 1010

char a[N];

int main(){
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++){
        int n;
        scanf("%d%s", &n, a);
        int s = a[0] - 48, ans = 0;
        for(int i=1; i<=n; i++){
            if(s < i) ans++, s++;
            s += a[i] - 48;
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
