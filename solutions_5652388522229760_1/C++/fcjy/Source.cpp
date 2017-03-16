#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

void fill(bool* v, long long num)
{
    while (num > 0)
        v[num % 10] = 1, num /= 10;
}

int main()
{
    //freopen("gcj\\A-large.in", "r", stdin);
    //freopen("gcj\\A-large.out", "w", stdout);

    int T, cases = 1;
    long long N;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d", &N);
        if (N == 0)
            printf("Case #%d: INSOMNIA\n", cases++);
        else
        {
            int K = 0;
            bool vis[10];
            memset(vis, 0, sizeof(vis));

            do
            {
                K++;
                fill(vis, N * K);
            } while (count(vis, vis + 10, true) < 10);

            printf("Case #%d: %I64d\n", cases++, N * K);
        }
    }

    return 0;
}