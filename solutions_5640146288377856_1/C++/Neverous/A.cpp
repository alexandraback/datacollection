/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

inline
int main_case(void)
{
    int rows, cols, width;
    scanf("%d %d %d", &rows, &cols, &width);
    return (cols / width) * (rows - 1) + width + (cols - 1) / width;
}

int main(void)
{
    int tests;
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        printf("Case #%d: %d\n", t + 1, main_case());

    return 0;
}
