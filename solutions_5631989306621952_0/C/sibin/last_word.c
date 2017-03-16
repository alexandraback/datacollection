#include <stdio.h>
#include <string.h>
int main()
{
    char S[1000], word[4000];
    int T, i, j, start, trail;

    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        scanf("%s", S);

        start = 2000;
        trail = 2000;
        word[start] = S[0];
        for (j = 1; j < strlen(S); j++) {
            if (S[j] >= word[start]) {
                start--;
                word[start] = S[j];
            } else {
                trail++;
                word[trail] = S[j];
            }
        }
        trail++;
        word[trail] = '\0';

        printf("Case #%d: ", i + 1, start);
        for (j = start; j < trail; j++) {
            printf("%c", word[j]);
        }
        printf("\n");
    }
    return 0;
}
