#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

const int OFFSET = 5;
const int MAXN = 1000000 + OFFSET;

int T, N;
long long tenN[15];

long long GetReverse(long long n)
{
    long long curr = n, reversed = 0;
    while (curr != 0)
    {
        reversed = 10 * reversed + curr % 10;
        curr /= 10;
    }
    return reversed;
}



int GetDigits(long long n)
{
    long long curr = n, d = 0;
    while (curr != 0)
    {
        curr /= 10;
        d++;
    }
    return d;
}

long long Solve(long long n)
{
    long long ans = 0;
    long long curr = n;
    int d = GetDigits(curr);
    while (curr > 9)
    {
        //cout << curr << endl;

        long long s1 = curr % tenN[d / 2];
        curr -= (s1 - 1);

        long long r = GetReverse(curr);
        int add = curr == r ? 0 : 1;
        curr = r;

        //cout << "REV: " << r << endl;

        long long s2 = curr - tenN[d - 1];
        curr -= (s2 + 1);

        ans += (s1 - 1) + add + (s2 + 1);
        d--;

        //cout << (s1 - 1) << " " << (s2 + 1) << endl;
    }

    return ans + curr;
}

int main()
{
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);

    tenN[0] = 1;
    for (int i = 1; i <= 14; i++)
    {
        tenN[i] = 10 * tenN[i - 1];
    }

    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d", &N);

        printf("Case #%d: %lld\n", t, Solve(N));
    }
    return 0;
}

