#include <stdio.h>

int main()
{
    int T; scanf("%d", &T);
    for (int test = 0; test < T; test++) {
        int max_S; scanf("%d\n", &max_S);
        char number[max_S + 1];

        for (int i = 0; i <= max_S; i++) {
            scanf("%c", &number[i]); number[i] -= '0';
        }

        long standing = number[0], required = 0;
        for (int i = 1; i <= max_S; i++) {
            if (!number[i]) continue;

            if (i > standing) {
                required += (i - standing);
                standing = i;
            }

            standing += number[i];
        }

        printf("Case #%d: %ld\n", test + 1, required);
    }
}