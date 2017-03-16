#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int a[3000];
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int t, Case = 0;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < 2 * n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                scanf("%d", &x);
                a[x]++;
            }
        }
        printf("Case #%d:", ++Case);
        for (int i = 0; i < 2600; i++)
            if (a[i] % 2)
                printf(" %d", i);
        printf("\n");
    }
}