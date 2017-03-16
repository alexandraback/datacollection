#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int f[2505];

int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);
    int T, n;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        for (int i = 0; i <= 2500; i++) f[i] = 0;
        scanf("%d", &n);
        for (int i = 0; i < 2 * n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                scanf("%d", &x);
                f[x]++;
            }
        }
        printf("Case #%d: ", cas);
        for (int i = 0; i <= 2500; i++)
        {
            if (f[i] & 1) printf("%d ", i);
        }
        puts("");
    }
    return 0;
}
