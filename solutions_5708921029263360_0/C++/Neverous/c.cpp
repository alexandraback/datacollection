/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int jackets;
int limit;
int pants;
int shirts;
int tests;

int find_best(void);
bool is_valid(int mask);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d %d %d", &jackets, &pants, &shirts, &limit);
        printf("Case #%d: ", t + 1);
        int best = find_best();
        printf("%d\n", __builtin_popcount(best));
        for(int b = 0; (1 << b) <= best; ++ b)
        {
            if(best & (1 << b))
                printf("%d %d %d\n", 1 + (b % jackets), 1 + ((b / jackets) % pants), 1 + ((b / jackets / pants) % shirts));
        }
    }

    return 0;
}

int find_best(void)
{
    int best = 0;
    for(int m = (1 << (jackets * pants * shirts)); m >= 0; -- m)
        if(__builtin_popcount(m) > __builtin_popcount(best) && is_valid(m))
            best = m;

    return best;
}

bool is_valid(int mask)
{
    int count1[32] = {};
    int count2[32] = {};
    int count3[32] = {};
    for(int b = 0; (1 << b) <= mask; ++ b)
        if(mask & (1 << b))
        {
            int jacket = b % jackets;
            int pant = (b / jackets) % pants;
            int shirt = (b / jackets / pants) % shirts;
            if(jacket >= jackets)
                return false;

            if(pant >= pants)
                return false;

            if(shirt >= shirts)
                return false;

            if(++ count1[jacket * jackets + pant] > limit)
                return false;

            if(++ count2[jacket * jackets + shirt] > limit)
                return false;

            if(++ count3[shirt * shirts + pant] > limit)
                return false;
        }

    return true;
}
