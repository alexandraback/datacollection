#include <cstdio>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int ct = 1; ct <= T; ct++)
    {
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);

        printf("Case #%d:", ct);
        for(int i = 1; i <= K; i++)
            printf(" %d", i);
        printf("\n");
    }

    return 0;
}
