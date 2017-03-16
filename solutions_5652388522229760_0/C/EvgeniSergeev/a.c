#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define len(x)  (int((x).size()))
#define append push_back
#define pp make_pair
#define ff(a, b)    for (int a = 0; a < (int)b; ++a)
#define ii(n)    ff(i, n)
#define kk(n)    ff(k, n)
#define mm(n)    ff(m, n)
#define fff(a, b, c) for (int a = (int)b; a < (int)c; ++a)
#define iii(a, b) fff(i, a, b)
#define kkk(a, b) fff(k, a, b)
#define mmm(a, b) fff(m, a, b)

int main() {
    int T;
    scanf("%d", &T);
    
    ii (T) {
        printf("Case #%d: ", i+1);

        int N;
        scanf("%d", &N);
        if (0 == N) {
            printf("INSOMNIA\n");
            continue;
        }
        char buffer[100];
        int counts[256];
        memset(counts, 0, sizeof(counts));
        int step = N;
        for ( ; ; N += step) {
            sprintf(buffer, "%d", N);
            for (char *c = buffer; *c; c++)
                counts[*c]++;
            bool all_good = true;
            for (char d = '0'; d <= '9'; ++d) {
                if (!counts[d])
                    all_good = false;
                //printf("%c:%d ", d, counts[d]);
            }
            //printf("%d\n", N);
            if (all_good) {
                printf("%d\n", N);
                break;
            }
        }
    }

    return 0;
}
