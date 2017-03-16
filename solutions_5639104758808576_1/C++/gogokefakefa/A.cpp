#include <cstdio>

using namespace std;

int solve()
{
    int N;
    char a[1 << 20];

    scanf("%d%s", &N, a);

    int sum = a[0] - '0', added = 0;
    
    for(int i = 1; i <= N; ++i)
    {
        if(i > sum)
        {
            added += (i - sum);
            sum = i;
        }

        sum += a[i] - '0';
    }

    return added;
}
int main()
{
    int tests;

    scanf("%d", &tests);

    for (int i = 1; i <= tests; ++i)
    {
        printf("Case #%d: %d\n", i, solve());
    }

    return 0;
}
