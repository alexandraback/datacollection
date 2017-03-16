#include<stdio.h>

int main(){
    int t, u;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        int r, c, w, a = 0;
        scanf("%d%d%d", &r, &c, &w);
        a = (c / w) * r + w;
        if (!(c % w))--a;
        printf("Case #%d: %d\n", u, a);
    }
    return 0;
}
