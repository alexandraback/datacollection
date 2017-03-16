#include <stdio.h>
#include <string.h>

#define MAXWORD 10
#define MAXLINE 4000

char dict[MAXWORD][250000][MAXWORD+1];
int cdict[MAXWORD];

void readdict(void)
{
    FILE *f = fopen("garbled_email_dictionary.txt", "r");
    char word[MAXWORD+1];
    int i;
    
    memset(cdict, 0, sizeof(cdict));
    
    while (fscanf(f, "%s", word) != EOF)
    {
        i = strlen(word);
        strcpy(dict[i-1][cdict[i-1]], word);
        cdict[i-1]++;
    }
}

int mismatches(const char *word, const char *p)
{
    int result = 0;
    while (*word)
        if (*word++ != *p++)
            result++;
    return result;
}

int bestmismatch(const char *p, int l)
{
    int result = l;
    int i, j;
    for (i = 0; i < cdict[l-1]; i++)
    {
        j = mismatches(dict[l-1][i], p);
        if (j < result)
            result = j;
    }
    return result;
}

int main()
{
    int t, c;
    char s[MAXLINE+1];
    int best[MAXLINE+1];
    int i, j, k;
    
    readdict();
    
    scanf("%d", &t);
    for (c = 1; c <= t; c++)
    {
        scanf("%s", s);
        best[0] = 0;
        for (i=1; s[i-1]; i++)
        {
            best[i] = i;
            for (j = 1; j <= i && j <= MAXWORD; j++)
            {
                k = bestmismatch(&s[i-j], j);
                if (best[i-j] + k < best[i])
                    best[i] = best[i-j] + k;
            }
        }
        
        printf("Case #%d: %d\n", c, best[i-1]);
    }
    
    return 0;
}
