#include <cstdio>

using namespace std;

int TC, tc, N, M;

int main() {
    freopen("i.in", "r", stdin);
    freopen("o.out", "w", stdout);
    scanf("%d", &TC);
    while(tc != TC) {
        scanf("%d %d", &N, &M);
        printf("Case #%d:\n", ++tc);
        for(int i = 0; i < M; i++) {
            printf("11");
            for(int j = 0; j < N / 2 - 2; j++) {
                if(i & (1 << (j))) {
                    printf("11");
                } else {
                    printf("00");
                }
            }
            printf("11");
            for(int i = 2; i <= 10; i++) {
                printf(" %d", i + 1);
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
}
