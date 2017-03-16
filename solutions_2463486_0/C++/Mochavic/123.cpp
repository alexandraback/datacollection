#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long c[1000000];
char str[100];
bool pd(long long x){
    int i, l;
    sprintf(str, "%I64d", x);
    l = strlen(str);
    for (i = 0; i < l - 1 - i; i++) if (str[i] != str[l - 1 - i]) return false;
    return true;
}
int main(){
    int i, cn = 0;
    for (i = 1; i < 10000000; i++){
        if (pd(i) && pd(1ll * i * i)) c[cn++] = 1ll * i * i;
    }
    int T, ri = 1;
    long long l, r;
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%lld%lld", &l, &r);
        int t = 0;
        for (i = 0; i < cn; i++){
            if (l <= c[i] && c[i] <= r) t++;
        }
        printf("Case #%d: %d\n", ri++, t);
    }
    return 0;
}
