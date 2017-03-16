#include <stdio.h>
#include <math.h>

int T, N, S, p, t[32];
int i, j, k;

inline int min(int a, int b)
{
    return (a < b) ? a : b;
}

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

int calculate()
{
    int c0 = 0, c1 = 0, c2 = 0;
    int val1, val2;
    for (j = 0; j < N; j++) {
        val1 = p + max(0, (p - 2)) * 2;
        val2 = p + max(0, (p - 1)) * 2;
        if (t[j] >= val2) {
            c2++;
        } else if (t[j] >= val1) {
            c1++;
        } else {
            c0++;
        }
    }
    return c2 + min(c1, S);
}

int main()
{
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%d %d %d", &N, &S, &p);
        for (j = 0; j < N; j++) {
            scanf("%d", &t[j]);
        }
        printf("Case #%d: %d\n", i+1, calculate());
    }
}
