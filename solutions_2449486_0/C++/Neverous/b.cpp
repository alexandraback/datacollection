/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    height,
    width,
    target[128][128];

bool check(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        for(int h = 0; h < 128; ++ h)
            for(int w = 0; w < 128; ++ w)
                target[h][w] = 0;

        scanf("%d %d", &height, &width);
        for(int h = 0; h < height; ++ h)
            for(int w = 0; w < width; ++ w)
                scanf("%d", &target[h][w]);

        printf("Case #%d: %s\n", t + 1, check() ? "YES" : "NO" );
    }

    return 0;
}

bool check(void)
{
    for(int c = 1; c <= 100; ++ c)
    {
        for(int h = 0; h < height; ++ h)
        {
            bool same = true;
            for(int w = 0; same && w < width; ++ w)
                same = target[h][w] == c || target[h][w] == 0;

            for(int w = 0; same && w < width; ++ w)
                target[h][w] = 0;
        }

        for(int w = 0; w < width; ++ w)
        {
            bool same = true;
            for(int h = 0; same && h < height; ++ h)
                same = target[h][w] == c || target[h][w] == 0;

            for(int h = 0; same && h < height; ++ h)
                target[h][w] = 0;
        }
    }

    for(int h = 0; h < height; ++ h)
        for(int w = 0; w < width; ++ w)
            if(target[h][w])
                return false;

    return true;
}
