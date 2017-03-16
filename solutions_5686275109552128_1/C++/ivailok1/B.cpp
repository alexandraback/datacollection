#include <iostream>
#include <stdio.h>

using namespace std;

/**
    TASK: Problem B. Infinite House of Pancakes
    EVENT: Qualification Round 2015
    COMPETITION: Google Code Jam
**/

const int MAXD = 1000;
const int MAXP = 1000;

int T, D;
int P[MAXD];

int main()
{
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);

    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d", &D);
        for (int i = 0; i < D; i++)
        {
            scanf("%d", &P[i]);
        }

        int minSec = MAXP + 1;
        for (int i = 1; i <= MAXP; i++)
        {
            int moves = 0;
            for (int j = 0; j < D; j++)
            {
                moves += (P[j] - 1) / i;
            }

            minSec = min(minSec, moves + i);
        }

        printf("Case #%d: %d\n", t, minSec);
    }
}

