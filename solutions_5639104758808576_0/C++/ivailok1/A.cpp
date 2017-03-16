#include <iostream>
#include <stdio.h>

using namespace std;

/**
    TASK: Problem A. Standing Ovation
    EVENT: Qualification Round 2015
    COMPETITION: Google Code Jam
**/

const int MAXN = 1000;

int T, N;
char S[MAXN + 2];

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small.out", "w", stdout);

    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d %s", &N, S);
        N++;

        int addPeople = 0, currPeople = S[0] - '0';
        for (int i = 1; i < N; i++)
        {
            if (currPeople < i)
            {
                addPeople += i - currPeople;
                currPeople += i - currPeople;
            }

            currPeople += S[i] - '0';
        }

        printf("Case #%d: %d\n", t, addPeople);
    }
}
