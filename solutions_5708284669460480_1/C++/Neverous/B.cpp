/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

inline
long double main_case(void)
{
    std::unordered_map<char, int> ppb;
    int letters, typed, wanted = 0;
    char keyboard[128], word[128];
    scanf("%d %d %d %s %s", &letters, &wanted, &typed, keyboard, word);
    for(int l = 0; l < letters; ++ l)
        ++ ppb[keyboard[l]];

    if(typed < wanted)
        return 0.0L;

    for(int w = 0; word[w]; ++ w)
        if(!ppb[word[w]])
            return 0.0L;

    long double result = 0.0L;
    const long double EPS = 0.0000000001L;
    std::vector<std::pair<long double, int>> cur;
    for(int t = 0; t <= typed; ++ t)
    {
        std::vector<std::pair<long double, int>> next;
        for(auto test: cur)
        {
            test.first *= 1.0L * ppb[word[test.second]] / letters;
            if(test.first <= EPS)
                continue;

            test.second += 1;
            if(!word[test.second])
            {
                //printf("Found occurrence with %.10Lf\n", test.first);
                result += test.first;
                continue;
            }

            next.push_back(test);
        }

        next.push_back(std::make_pair(1.0, 0));
        cur = next;
    }

    int overlap = wanted;
    for(int o = 1; o < wanted; ++ o)
    {
        bool ok = true;
        for(int w = o; word[w] && ok; ++ w)
            ok = word[w] == word[w - o];

        if(ok)
        {
            overlap = o;
            break;
        }
    }

    //printf("overlap is: %d\n", overlap);
    //printf("worst is %d\n", 1 + (typed - wanted) / overlap);
    return 1 + (typed - wanted) / overlap - result;
}

int main(void)
{
    int tests;
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        printf("Case #%d: %.10Lf\n", t + 1, main_case());

    return 0;
}
