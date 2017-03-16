#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int T, t, cache[10];
    scanf("%d", &T);
    t = T;
    while (t--) {

        long long num;
        scanf("%lld", &num);
        
        if (num == 0) {
             printf("Case #%d: INSOMNIA\n", T - t);
             continue;
        }


        memset(cache, 0, sizeof(int) * 10);

        int j, c = 0;
        for (j = 1; c != 10; j++) {
            long long x = num * j;
            while (x != 0) {
                int dig = x % 10;
                if (cache[dig] == 0) {
                    cache[dig] = 1;
                    c++;
                }
                x /= 10;
            }
        }

        printf("Case #%d: %lld\n", T - t, num * (j - 1));
    }
}

        

