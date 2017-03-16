/* 2013
 * Maciej Szeptuch
 * II UWr
 * ----------
 *  Brute
 */
#include <cstdio>

int tests,
    len;
char word[128];

int count(void);
bool check(const int &s, const int &e);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%s %d", word, &len);
        printf("Case #%d: %d\n", t + 1, count());
    }

    return 0;
}

int count(void)
{
    int res = 0;
    for(int a = 0; word[a]; ++ a)
        for(int b = a; word[b]; ++ b)
            res += check(a, b);

    return res;
}

bool check(const int &s, const int &e)
{
    int cnt = 0;
    for(int w = s; w <= e && cnt < len; ++ w)
    {
        if(word[w] != 'a' && word[w] != 'e' && word[w] != 'i' && word[w] != 'o' && word[w] != 'u')
            ++ cnt;

        else
            cnt = 0;
    }

    return cnt >= len;
}
