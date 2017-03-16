#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

typedef long long i64;

using namespace std;

i64 a, b, k;

i64 dp[40][2][2][2];

void init()
{
    for (int i = 0; i < 40; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                for (int x = 0; x < 2; ++x)
                    dp[i][j][k][x] = -1;
}

int f(i64 a, i64 b)
{
    if (a & b)
        return 0;
    return 1;
}

int g(i64 a, i64 b)
{
    if (a & b)
        return 1;
    return 0;
}

i64 getdp(int n, int al, int bl, int kl)
{
    if (n == -1)
        return 1;
    if (dp[n][al][bl][kl] == -1)
    {
        i64 q = 1L << n;
        i64 res = getdp(n - 1, al & f(q, a), bl & f(q, b), kl & f(q, k));
        if (!al || (al && (q & a)))
            res += getdp(n - 1, al & g(q, a), bl & f(q, b), kl & f(q, k));
        if (!bl || (bl && (q & b)))
            res += getdp(n - 1, al & f(q, a), bl & g(q, b), kl & f(q, k));
        if ((!al || (al && (q & a))) && (!bl || (bl && (q & b))) && (!kl || (kl && (q & k))))
            res += getdp(n - 1, al & g(q, a), bl & g(q, b), kl & g(q, k));
        dp[n][al][bl][kl] = res;
        return res;
    }
    return dp[n][al][bl][kl];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int qw;
    cin >> qw;
    for (int qwe = 0; qwe < qw; ++qwe)
    {
        cout << "Case #" << qwe + 1 << ": ";
        init();
        cin >> a >> b >> k;
        a--;
        b--;
        k--;
        cout << getdp(30, 1, 1, 1) << endl;
    }
    return 0;
}
