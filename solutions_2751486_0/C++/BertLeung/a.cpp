#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[1000500];
char str[1000500];

int isVowel(char a)
{
    if ( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' )
        return 1;
    return 0;
}

int main()
{
    int aa, nn, i, j, k, n, len, ans, c;
    gets(buffer);
    nn = atoi(buffer);
    for ( aa = 1; aa <= nn; ++aa ) {
        gets(buffer);
        sscanf(buffer, "%s %d", str, &n);
        len = strlen(str);
        ans = 0;
        for (i = 0; i < len; i++ ) {
            for (j = i + n; j <= len; j++ ) {
                c = isVowel(str[i])? 0 : 1;
                for ( k = i+1; k < j; k++ ) {
                    if (c == n) break;
                    if ( isVowel(str[k]) ) c = 0;
                    else c++;
                }
                if (c == n) ans++;
            }
        }
        printf("Case #%d: %d\n", aa, ans);
    }
    return 0;
}

