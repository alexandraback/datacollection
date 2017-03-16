/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>
#include <string>

inline
long double check_all(std::string out, int left, const std::string &wanted, int letters, const std::string &keyboard, int &worst)
{
    if(left == 0)
    {
        int count = 0;
        size_t pos = out.find(wanted);
        while(pos != std::string::npos)
        {
            ++ count;
            pos = out.find(wanted, pos + 1);
        }

        if(count > worst)
            worst = count;

        return count;
    }

    long double result = 0.0L;
    for(int l = 0; l < letters; ++ l)
        result += 1.0L / letters * check_all(out + keyboard[l], left - 1, wanted, letters, keyboard, worst);

    return result;
}

inline
long double main_case(void)
{
    int letters, typed, worst = 0;
    char keyboard[128], word[128];
    scanf("%d %*d %d %s %s", &letters, &typed, keyboard, word);
    std::sort(keyboard, keyboard + letters);
    long double result = check_all("", typed, word, letters, keyboard, worst);
    return worst - result;
}

int main(void)
{
    int tests;
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        printf("Case #%d: %.10Lf\n", t + 1, main_case());

    return 0;
}
