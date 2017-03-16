#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++)
    {
        int A, B, K, ans = 0;
        scanf("%d %d %d", &A, &B, &K);
        for (int i = 0; i < A; i++)
        {
            for (int j = 0; j < B; j++)
            {
                if ((i & j) < K)
                {
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", tc, ans);
    }

}
