#include <stdio.h>
int main()
{
    int i, j;
    int T;
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        char buf[128];
        int n = 0, invite = 0;
        int Smax;
        scanf("%d %s", &Smax, buf);
        for (j = 0; j <= Smax; j++) {
            int Si;
            Si = buf[j] - '0';
            if (n < j) {
                invite += j - n;
                n = j;
            }
            n += Si;
        }
        printf("Case #%d: %d\n", i + 1, invite);
    }
}
