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
    long long result;
    char s[1000001];
    int n;
    int i, j;
    int len;
    int cnt;
    int pre_add;
    
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

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

        pre_add = 0;
        cnt = 0;
        for (i = 0; i < len; i++)
        {
            if (is_consonant(s[i]))
            {
                cnt++;
                if (cnt >= n)
                {
                    pre_add = i - n + 2;
                }
            }
            else
            {
                cnt = 0;
            }
            result += pre_add;
        }

out:
        printf("Case #%d: %lld\n", case_idx, result);
    }

    return 0;
}





