#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

int T;
int R, C, W;


int main()
{
    scanf("%d", &T);
    REP(tc, T)
    {
        scanf("%d %d %d", &R, &C, &W);

        int minPerRow = 999999;

        REP(mask, 1<<C)
        {
            int cur = __builtin_popcount(mask);

            int spaces = 0;

            REP(i, C-W+1)
            {
                bool any = false;
                REP(k, W)
                    if (mask & (1<<(i+k)))
                    {
                        any = true;
                        break;
                    }

                if (!any)
                    spaces++;
            }

            if (spaces == 1)
                minPerRow = min(minPerRow, cur);
        }

        printf("Case #%d: %d\n", tc+1, (minPerRow + 1) * R + W - 1);
    }
}
