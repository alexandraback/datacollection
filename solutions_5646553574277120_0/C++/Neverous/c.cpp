/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

inline
bool test_price(int max, int coins, int coin[], int price)
{
    bool possible[price + 1] = {};
    possible[0] = true;
    for(int c = 0; c < coins; ++ c)
        for(int m = 0; m < max; ++ m)
            for(int p = price; p >= coin[c]; -- p)
                possible[p] |= possible[p - coin[c]];

    for(int p = 0; p <= price; ++ p)
        if(!possible[p])
            return false;

    return true;
}

inline
bool test_add(int add, int max, int coins, int coin[], int price)
{
    if(!add)
        return test_price(max, coins, coin, price);

    bool result = false;
    for(int n = 1; n <= price && !result; ++ n)
        if(std::find(coin, coin + coins, n) == coin + coins)
        {
            coin[coins] = n;
            result = test_add(add - 1, max, coins + 1, coin, price);
        }

    return result;
}

inline
int main_case(void)
{
    int max, coins, price;
    int coin[128];
    scanf("%d %d %d", &max, &coins, &price);
    for(int c = 0;c < coins; ++ c)
        scanf("%d", &coin[c]);

    std::sort(coin, coin + coins);
    for(int add = 0; add <= price; ++ add)
        if(test_add(add, max, coins, coin, price))
            return add;

    return coins;
}

int main(void)
{
    int tests;
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        printf("Case #%d: %d\n", t + 1, main_case());

    return 0;
}
