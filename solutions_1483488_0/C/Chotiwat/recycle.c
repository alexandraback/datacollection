#include <stdio.h>
#define MAX 2000020

int visited[MAX];

int rotate(int x, int mod) {
    x *= 10;
    return (x % mod) + x / mod;
}

int main() {
    int t, T, a, b, total, count, i, j, mod;

    scanf("%d", &T);

    for(t = 1; t <= T; t++) {
        scanf("%d%d", &a, &b);

        for(i = a; i <= b; i++) {
            visited[i] = 0;
        }
        total = 0;
        for(mod = 1; mod <= b; mod *= 10)
            ;

        for(i = a; i <= b; i++) {
            if(!visited[i]) {
                visited[i] = 1;
                count = 1;
                j = i;
                while((j = rotate(j, mod)) != i) {
                    if(j >= a && j <= b && !visited[j]) {
                        //printf("%d ", j);
                        visited[j] = 1;
                        ++count;
                    }
                }
                //printf("%d : %d\n", i, count);
                total += count * (count - 1) / 2;
            }
        }

        printf("Case #%d: %d\n", t, total);
    }

    return 0;
}
