#include <bits/stdc++.h>

using namespace std;

bool meet[10];

void update(int x)
{
    while (x)
    {
        meet[x%10] = true;
        x /= 10;
    }
}

bool check()
{
    for (int i = 0; i < 10; ++i)
        if (!meet[i])
            return false;
    return true;
}

int calc(int x)
{
    memset(meet, false, sizeof meet);
    int r = 0;
    do {
        r += x;
        update(r);
    }
    while (!check());
    return r;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n_tests;
    scanf("%d", &n_tests);

    for (int test_id = 1; test_id <= n_tests; ++test_id)
    {
        int n;
        scanf("%d", &n);
                
        printf("Case #%d:", test_id);

        if (!n)
            printf(" INSOMNIA");
        else
            printf(" %d", calc(n));
        printf("\n");
    }

    return 0;
}
