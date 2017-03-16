#include <cstdio>

int main() {
    int t; scanf("%d", &t);
    for(int _i=1; _i<=t; _i++) {
        int n; scanf("%d", &n);
        int used = 0, i, x=n;
        for(i=0; i<100000; i++) {
            for(int j=x; j>0; j/=10) used |= (1<<(j%10));
            if(used==((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8)|(1<<9))) break;
            x+=n;
        }
        if(i==100000) printf("Case #%d: INSOMNIA\n", _i);
        else printf("Case #%d: %d\n", _i, x);
    }
}
