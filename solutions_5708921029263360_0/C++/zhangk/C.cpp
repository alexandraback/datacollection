#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

int T, n1, n2, n3, K, kase = 0;

int main()
{
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3 >> K;
        int i, j, k, p;
        int ans = n1 * n2 * min(K, n3);
        printf("Case #%d: %d\n", ++kase, ans);
        k = 0;

            for (i = 1; i <= n1; i++)
                for (j = 1; j <= n2; j++)
                {
                    k = 0;
                    for (p = 1; p <= min(K, n3); p++)
        {
                k++;
                if (k > n3) k -= n3;
                printf("%d %d %d\n", i, j, k);
        }
                }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
