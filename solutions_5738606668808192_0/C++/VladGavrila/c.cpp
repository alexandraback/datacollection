#include <cstdio>

using namespace std;

int n, m, conf;

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("data.out", "w", stdout);

    scanf("%d", &n);
    scanf("%d%d", &n, &m);

    printf("Case #1:\n");

    for(int i=0; i<m; ++i)
    {
        printf("1");
        for(int j=n/2-3; j>=0; --j)
            printf("%d", ((i>>j)&1));
        printf("1");
        printf("1");
        for(int j=n/2-3; j>=0; --j)
            printf("%d", ((i>>j)&1));
        printf("1");

        for(int baza=2; baza<=10; ++baza)
        {
            long long ans=1, pt = baza;
            for(int j=0; j<n/2-2; ++j)
            {
                ans += pt * ((i>>j)&1);
                pt *= baza;
            }
            ans += pt;
            printf(" %lld", ans);
        }

        printf("\n");
    }

    return 0;
}


