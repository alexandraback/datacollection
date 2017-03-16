/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int main_case(void)
{
    int levels = 0;
    int result = 0;
    char description[1024]{};


    scanf("%d %s", &levels, description);
    int current = description[0] - '0';

    for(int l = 1; l <= levels; ++ l)
        if(description[l] > '0')
        {
            result += std::max(0, l - current);
            current = std::max(l, current) + description[l] - '0';
        }

    return result;
}

int main(void)
{
    int tests = 0;
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        printf("Case #%d: %d\n", t + 1, main_case());

    return 0;
}
