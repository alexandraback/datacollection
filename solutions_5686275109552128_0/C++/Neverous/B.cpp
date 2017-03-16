/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>

inline
int main_case(void)
{
    int starting = 0;
    int pancakes = 0;
    int best = 1048576;
    std::vector<int> diners;

    scanf("%d", &starting);
    for(int s = 0; s < starting; ++ s)
    {
        scanf("%d", &pancakes);
        diners.push_back(pancakes);
    }

    for(int s = 1; s < best; ++ s)
    {
        int divs = 0;
        for(int d = 0; d < starting; ++ d)
            divs += (diners[d] - 1) / s;

        best = std::min(best, s + divs);
    }

    return best;
}

int main(void)
{
    int tests = 0;
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        printf("Case #%d: %d\n", t + 1, main_case());

    return 0;
}
