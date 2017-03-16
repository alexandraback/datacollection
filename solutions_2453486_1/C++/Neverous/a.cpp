/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests;
char _row[8][8];

int check(const char row[8][8]);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        for(int h = 0; h < 4; ++ h)
            scanf("%s", _row[h]);

        printf("Case #%d: ", t + 1);
        switch(check(_row))
        {
            case 1:
                puts("X won");
                break;

            case 2:
                puts("O won");
                break;

            case 4:
                puts("Game has not completed");
                break;

            default:
                puts("Draw");
                break;
        }
    }

    return 0;
}

int check(const char row[8][8])
{
    int res = 0;
    for(int h = 0; h < 4; ++ h)
    {
        bool x = true,
             o = true;

        for(int w = 0; x && w < 4; ++ w)
            x = row[h][w] == 'X' || row[h][w] == 'T';

        for(int w = 0; o && w < 4; ++ w)
            o = row[h][w] == 'O' || row[h][w] == 'T';

        if(x) res |= 1;
        if(o) res |= 2;
    }

    for(int w = 0; w < 4; ++ w)
    {
        bool x = true,
             o = true;

        for(int h = 0; x && h < 4; ++ h)
            x = row[h][w] == 'X' || row[h][w] == 'T';

        for(int h = 0; o && h < 4; ++ h)
            o = row[h][w] == 'O' || row[h][w] == 'T';

        if(x) res |= 1;
        if(o) res |= 2;
    }

    bool x = true,
         o = true;
    for(int d = 0; x && d < 4; ++ d)
        x = row[d][d] == 'X' || row[d][d] == 'T';

    for(int d = 0; o && d < 4; ++ d)
        o = row[d][d] == 'O' || row[d][d] == 'T';

    if(x) res |= 1;
    if(o) res |= 2;
    x = o = true;

    for(int d = 0; x && d < 4; ++ d)
        x = row[d][3 - d] == 'X' || row[d][3 - d] == 'T';

    for(int d = 0; o && d < 4; ++ d)
        o = row[d][3 - d] == 'O' || row[d][3 - d] == 'T';

    if(x) res |= 1;
    if(o) res |= 2;

    for(int h = 0; !res && h < 4; ++ h)
        for(int w = 0; !res && w < 4; ++ w)
            if(row[h][w] == '.')
                res = 4;

    return res;
}
