#include <stdio.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d\n", &T);
    char wtab[300];
    memset(wtab, 0, sizeof(wtab));
    while (T--)
    {
        char gs[100];
        gets(gs);
        char ss[100];
        gets(ss);
        for (int i = 0; gs[i]; i++)
        {
            //if (wtab[gs[i]] == 0)
            //    printf("\n%c\n", gs[i]);
            wtab[gs[i]] = ss[i];
        }
    }
    for (char c = 'a'; c <= 'z'; c++)
        printf("%c", wtab[c]);
    while (1);
}
