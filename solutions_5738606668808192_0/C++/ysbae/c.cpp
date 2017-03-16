#include <cstdio>

using namespace std;

int main() {
    int tc, t, n, i, j;

    scanf("%d", &tc);
    for (t = 1; t <= tc; t++) {
        scanf("%d %d", &n, &j);
        
        int msel = (n - 2) / 2;
        int m = (1 << msel);

        printf("Case #%d:\n", t);
        for (int sel = 0; sel < m && sel < j; sel++) {
            printf("1");
            for (i = 0; i < msel; i++) {
                if ((sel >> i) & 1) {
                    printf("11");
                } else {
                    printf("00");
                }
            }
            printf("1 3 4 5 6 7 8 9 10 11\n");
        }
    }
    return 0;
}
