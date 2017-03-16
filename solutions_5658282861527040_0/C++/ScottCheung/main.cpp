#include <cstdio>
using namespace std;

int T, A, B, K;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int x = 1; x <= T; x++)
    {
        scanf("%d%d%d", &A, &B, &K);
        int ans = 0;
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                if ((i & j) < K)
                    ans++;
        printf("Case #%d: %d\n", x, ans);
    }
    return 0;
}
