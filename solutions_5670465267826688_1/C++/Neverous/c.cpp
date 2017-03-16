/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cassert>
#include <cstdio>
#include <algorithm>

//#define fprintf(...) {}

int multable[5][5] = {
    { 0,  0,  0,  0,  0},
    { 0,  1,  2,  3,  4},
    { 0,  2, -1,  4, -3},
    { 0,  3, -4, -1,  2},
    { 0,  4,  3, -2, -1},
};

inline
int sign(int a)
{
    return a < 0 ? -1 : a > 0 ? 1 : 0;
}

inline
int map(char l)
{
    return l - 'i' + 2;
}

inline
const char *rev(int d)
{
    switch(d)
    {
        case 0:     return "INVALID";
        case 1:     return "1";
        case -1:    return "-1";
        case 2:     return "i";
        case -2:     return "-i";
        case 3:     return "j";
        case -3:     return "-j";
        case 4:     return "k";
        case -4:     return "-k";
    }

    return nullptr;
}

inline
bool main_case(void)
{
    long long int length = 0;
    long long int multiplier = 0;
    char word[16384]{};
    char vals[1048576]{};
    vals[0] = 1;
    scanf("%lld %lld %s", &length, &multiplier, word);
    int brk = 0;
    int p = 0;
    int temp = 0;
    for(long long int m = 0; m < multiplier && brk < 2; ++ m)
    {
        for(long long int l = 0; l < length && brk < 2; ++ l, ++ p)
        {
            if(p)
                vals[p] = multable[(int) std::abs(vals[p - 1])][map(word[l])] * sign(vals[p - 1]);

            else
                vals[p] = map(word[l]);

            vals[p + 1] = 0;
            if(p >= length && p % length == 0 && vals[p] == vals[0])
            {
                temp = p;
                ++ brk;
            }

            if(brk)
                assert(vals[p] == vals[p % temp]);
        }

        assert(m < 64);
    }


    if(!temp)
        temp = p;

    fprintf(stderr, "Done: %lld vs %lld\n", multiplier, p / length);
    if(vals[(length * multiplier - 1) % temp] != -1)
        return false;

    int w = 0;
    while(vals[w] && vals[w] != 2)
        ++ w;

    if(vals[w ++] != 2)
        return false;

    while(vals[w] && vals[w] != 4)
        ++ w;

    if(vals[w ++] != 4)
        return false;

    return true;
}

int main(void)
{
    int tests = 0;
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        printf("Case #%d: %s\n", t + 1, main_case() ? "YES" : "NO");

    return 0;
}
