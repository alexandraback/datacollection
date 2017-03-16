//Google Code Jam Round 1C 2014 - Problem A.
//https://code.google.com/codejam

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

bool check(long long int n)
{
    while(n%2 == 0)
        n /= 2;
    if(n != 1)
        return true;
    return false;
}

long long int GCD(long long int a, long long int b)
{
    if(a < b)
        return GCD(b, a);
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

int main()
{
    freopen ("a_output.txt","w",stdout);

    int T, ans;
    char c;
    long long int P, Q;

    scanf("%d", &T);

    for(int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%lld%c%lld", &P, &c, &Q);
        //printf("%d %d\n", P, Q);

        int ans = 0;

        printf("Case #%d: ", testCase);

        long long gcd = GCD(P, Q);
        P = P/gcd;
        Q = Q/gcd;

        if(check(Q))
        {
            printf("impossible\n");
            continue;
        }

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
