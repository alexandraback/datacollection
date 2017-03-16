/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int tests,
    me,
    motes,
    mote[128],
    res;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &me, &motes);
        for(int m = 0; m < motes; ++ m)
            scanf("%d", &mote[m]);

        std::sort(mote, mote + motes);
        res = motes;
        for(int m = 0, act = 0; m < motes && me > 1; ++ m)
        {
            while(mote[m] >= me)
            {
                me += me - 1;
                act += 1;
            }

            me += mote[m];
            if(res > act + motes - m - 1)
                res = act + motes - m - 1;
        }

        printf("Case #%d: %d\n", t + 1, res);
    }

    return 0;
}
