/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

#define fprintf(...) {}

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
    int length = 0;
    int multiplier = 0;
    char word[16384]{};
    scanf("%d %d %s", &length, &multiplier, word);
    for(int m = 1, p = length; m < multiplier; ++ m)
        for(int l = 0; l < length; ++ l, ++ p)
        {
            word[p] = word[l];
            word[p + 1] = 0;
        }

    fprintf(stderr, "%s\n", word);
    word[0] = map(word[0]);
    fprintf(stderr, "%s ", rev(word[0]));
    for(int w = 1; word[w]; ++ w)
    {
        word[w] = multable[(int) std::abs(word[w - 1])][map(word[w])] * sign(word[w - 1]);
        fprintf(stderr, "%s ", rev(word[w]));
    }

    fprintf(stderr, "\n");
    if(word[length * multiplier - 1] != -1)
        return false;

    int w = 0;
    while(word[w] && word[w] != 2)
        ++ w;

    if(word[w ++] != 2)
        return false;

    while(word[w] && word[w] != 4)
        ++ w;

    if(word[w ++] != 4)
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
