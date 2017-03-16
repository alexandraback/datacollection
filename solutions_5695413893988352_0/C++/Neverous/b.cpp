/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

int tests;
char coders[32];
char jammers[32];
int best;
int bestc;
int bestj;

void solve(int cod, int jam, int p);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        best = 9999999;
        scanf("%s %s", coders, jammers);
        int len = strlen(coders);
        printf("Case #%d: ", t + 1);
        solve(0, 0, 0);
        for(int p = len - 1; p >= 0; -- p)
        {
            coders[p] = (bestc % 10) + '0';
            bestc /= 10;
        }

        for(int p = len - 1; p >= 0; -- p)
        {
            jammers[p] = (bestj % 10) + '0';
            bestj /= 10;
        }

        printf("%s %s\n", coders, jammers);
    }

    return 0;
}

void solve(int cod, int jam, int p)
{
    if(!coders[p])
    {
        int diff = std::abs(cod - jam);
        if(diff < best || (best == diff && cod < bestc) || (best == diff && cod == bestc && jam < bestj))
        {
            best = diff;
            bestc = cod;
            bestj = jam;
        }

        return;
    }

    for(int d1 = 0; d1 < 10; ++ d1)
        for(int d2 = 0; d2 < 10; ++ d2)
        {
            if(coders[p] == '?' && jammers[p] == '?')
                solve(cod * 10 + d1, jam * 10 + d2, p + 1);

            else if(coders[p] == '?' && jammers[p] - '0' == d2)
                solve(cod * 10 + d1, jam * 10 + d2, p + 1);

            else if(jammers[p] == '?' && coders[p] - '0' == d1)
                solve(cod * 10 + d1, jam * 10 + d2, p + 1);

            else if(coders[p] - '0' == d1 && jammers[p] - '0' == d2)
                solve(cod * 10 + d1, jam * 10 + d2, p + 1);
        }
}
