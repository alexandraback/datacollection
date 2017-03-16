#include <stdio.h>
#include <string.h>

unsigned int power(unsigned int base, int pow) {
    unsigned int ans = 1;
    for (int i=0;i<pow;i++) {
        ans *= base;
    }
    return ans;
}
void output(unsigned int ans) {
    if (ans==0)
        return ;
    int r = ans % 2;
    output(ans/2);
    printf("%d", r);
}
int main()
{
    int T;
    
    scanf("%d", &T);
    int N,J;
    for (int Ti=1;Ti<=T;Ti++) {
        printf("Case #%d:\n", Ti);
        scanf("%d %d", &N, &J);
        unsigned int num = power(2,N-1)+1;
        unsigned int ans = num-6;
        for (int i=0;i<J;i++) {
            ans += 6;
//            printf("ans [%u] ",ans);
            output(ans);
            printf(" 3 4 5 6 7 8 9 10 11\n");
        }
    }
    return 0;
}


