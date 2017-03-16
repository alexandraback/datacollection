#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[1000500];
char str[1000500];
int match[1000500];

int isVowel(char a)
{
    if ( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' )
        return 1;
    return 0;
}

int main()
{
    long long ans;
    int aa, nn, i, j, k, n, len, c;
    gets(buffer);
    nn = atoi(buffer);
    for ( aa = 1; aa <= nn; ++aa ) {
        gets(buffer);
        sscanf(buffer, "%s %d", str, &n);
        len = strlen(str);
        ans = 0;
        memset(match, 0, sizeof(match));
        for ( i = len-1, j = -1; i >= 0; i-- ) {
            if (isVowel(str[i])) match[i] = 0;
            else match[i] = match[i+1] + 1;

            if (match[i] >= n) {
                j = i;
                ans += (len-i-n+1);
            } else if ( j >= 0 ) {
                ans += (len-j-n+1);
            }
        }
        printf("Case #%d: %lld\n", aa, ans);
    }
    return 0;
}

