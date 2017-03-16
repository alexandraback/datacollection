/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    len;
char word[1048576];

long long int count(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%s %d", word, &len);
        printf("Case #%d: %lld\n", t + 1, count());
    }

    return 0;
}

long long int count(void)
{
    int cnt = 0,
        _len = 0;
    long long int res = 0;
    while(word[_len]) ++ _len;

    for(int a = 0, b = 0; a < _len; ++ a)
    {
        while(b < _len && cnt < len)
        {
            if(word[b] != 'a' && word[b] != 'e' && word[b] != 'i' && word[b] != 'o' && word[b] != 'u')
                ++ cnt;

            else
                cnt = 0;

            ++ b;
        }

        if(cnt < len)
            break;

        res += _len - b + 1;

        if(b - a == cnt && word[a] != 'a' && word[a] != 'e' && word[a] != 'i' && word[a] != 'o' && word[a] != 'u')
            -- cnt;
    }
        
    return res;
}
