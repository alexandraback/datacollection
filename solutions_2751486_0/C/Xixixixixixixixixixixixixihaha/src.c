#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_consonant(char c)
{
    if (('a' == c) || ('e' == c) || ('i' == c) || ('o' == c) || ('u' == c))
    {
        return 0;
    }
    return 1;
}

int main(void)
{
    int case_idx = 0;
    int t;
    int result;
    char s[100001];
    int n;
    int i, j;
    int len;
    int cnt;
    
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    scanf("%d", &t);
    while(t--)
    {
        case_idx++;
        result = 0;
        scanf("%s %d", s, &n);

        len = strlen(s);
        if (0 == n)
        {
            result = (1 + len) * len / 2;
            goto out;
        }
        
        for (i = 0; i < len; i++)
        {
            cnt = 0;
            for (j = i; j >= 0; j--)
            {
                if (is_consonant(s[j]))
                {
                    cnt++;
                    if (cnt >= n)
                    {
                        result += j + 1;
                        break;
                    }
                }
                else
                {
                    cnt = 0;
                }
            }
        }

out:
        printf("Case #%d: %d\n", case_idx, result);
    }

    return 0;
}





