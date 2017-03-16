#include <stdio.h>
#include <stdlib.h>

bool present[10];

int main(int argc, char **argv) {
    int T;
    scanf("%d", &T);
    for (int t=1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        if (N==0) {
            printf("Case #%d: INSOMNIA\n", t);
            continue;
        }
        for (int i=0; i<10; i++) {
            present[i]=false;
        }
        int missing=10;
        int K=N;
        while (true) {
            int digits = K;
            while (digits>0) {
                int d=digits%10;
                if (!present[d]) {
                    present[d] = true;
                    missing--;
                }
                digits/=10;
            }
            if (missing==0) {
                printf("Case #%d: %d\n", t, K);
                break;
            }
            K += N;
        }
    }
    return 0;
}
