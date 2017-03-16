#include <cstdio>
int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);
    for (int ct = 1; ct <= T; ct++) {
        int A, B, K;
        scanf("%d%d%d", &A, &B, &K);
        int count = 0;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if ((i & j) < K) {
                    count++;
                }
            }
        }
        printf("Case #%d: %d\n", ct, count);
    }
    return 0;
}
