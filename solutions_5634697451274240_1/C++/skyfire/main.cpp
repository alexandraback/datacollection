#include <bits/stdc++.h>

using namespace std;

#define N 111

int main()
{
    //freopen("sample.in", "r", stdin);
    //freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n_tests;
    scanf("%d", &n_tests);

    for (int test_id = 1; test_id <= n_tests; ++test_id)
    {
        char n[N];
        scanf("%s", n);
                
        int p[N];
        int m[N];

        int l = strlen(n);

        p[0] = n[0] == '+' ? 0 : 1;
        m[0] = n[0] == '-' ? 0 : 1;
        for (int i = 1; i < l; ++i)
        {
            p[i] = n[i] == '+' ? p[i-1] : m[i-1]+1;
            m[i] = n[i] == '-' ? m[i-1] : p[i-1]+1;
        }

        printf("Case #%d: %d\n", test_id, p[l-1]);
    }

    return 0;
}
