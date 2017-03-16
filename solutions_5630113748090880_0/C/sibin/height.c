#include <stdio.h>
#include <string.h>

int main()
{
    int T, N, H[2501];
    int i, j, height, max_height;

    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        memset(H, 0, 2501 * sizeof(int));
        max_height = 0;
        scanf("%d", &N);

        for (j = 0; j < ((N*N*2) - N); j++) {
            scanf("%d", &height);
            H[height]++;
            if (height > max_height) {
                max_height = height;
            }
        }

        printf("Case #%d: ", i + 1);
        for (j = 0; j <= max_height; j++) {
            if ((H[j] % 2) != 0) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}
