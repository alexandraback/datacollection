#include <stdio.h>
#include <string.h>

char *map = "ynficwlbkuomxsevzpdrjgthaq";

int pos(char c);

int main()
{
    char G[150];
    int T, i;
    char *p;

    scanf("%d", &T);
    gets(G);
    for(i = 0; i < T; i++) {
        gets(G);
        p = G;
        while(*p) {
            if (*p == ' ') {
                p++;
                continue;
            }

            *p = 'a' + pos(*p);
            p++;
        }
        printf("Case #%d: %s\n", i + 1, G);
    }

    return 0;
}

int pos(char c)
{
    char *p;

    p = map;
    while(*p != c && *p)
        p++;

    return p - map;
}
