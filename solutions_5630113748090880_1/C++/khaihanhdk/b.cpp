#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[10000];

int main()
{
    freopen("d:\\B-large.in", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
    int oo;
    scanf("%d", &oo);
    for(int o = 0; o < oo; o++)
    {
        int n;
        scanf("%d", &n);
        int m = 2 * n - 1;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x;
                scanf("%d", &x);
                a[x]++;
            }
        }
        printf("Case #%d:", o +1);
        int ccc = 0;
        for(int i = 0; i <= 9000; i++)
            if (a[i] % 2 != 0)
                printf(" %d", i);
        printf("\n");

    }
}
