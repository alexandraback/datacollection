#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n_tests;
    scanf("%d", &n_tests);

    for (int test_id = 1; test_id <= n_tests; ++test_id)
    {
        int k, c, s;
        scanf("%d %d %d", &k, &c, &s);

        vector<long long> ms;

        int checked = 0;
        do
        {
            long long p = ++checked;
            for (int level = 1; level < c; ++level)
            {
                if (checked < k)
                    ++checked;
                p = (p-1)*k + checked; 
            }
            ms.push_back(p);
        }
        while (checked < k);

        printf("Case #%d:", test_id);

        if (ms.size() > s)
            printf(" IMPOSSIBLE");
        else
            for (long long x: ms)
                printf(" %lld", x);
        printf("\n");
    }

    return 0;
}
