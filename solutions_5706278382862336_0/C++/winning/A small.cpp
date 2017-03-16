//Google Code Jam Round 1C 2014 - Problem A.
//https://code.google.com/codejam

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

bool check(int n)
{
    while(n%2 == 0)
        n /= 2;
    if(n != 1)
        return true;
    return false;
}

int main()
{
    freopen ("a_output.txt","w",stdout);

    int T, ans;
    char c;
    int P, Q;

    scanf("%d", &T);

    for(int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%d%c%d", &P, &c, &Q);
        //printf("%d %d\n", P, Q);

        int ans = 0;

        printf("Case #%d: ", testCase);

        if(check(Q))
        {
            printf("impossible\n");
            continue;
        }
        //double p = P, q = Q;

        while(1)
        {
            ans ++;
            P *= 2;

            if(P >= Q)
                break;
        }
        printf("%d\n", ans);

    }
    return 0;
}
