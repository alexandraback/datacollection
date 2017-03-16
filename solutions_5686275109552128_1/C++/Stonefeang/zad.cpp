#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t;

int n;
int tab[1007];
int wyn;
int aktu;

int main()
{
    scanf("%d", &t);
    for (int h=1; h<=t; h++)
    {
        wyn=1000000000;
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
        {
            scanf("%d", &tab[i]);
        }
        for (int i=1; i<=1000; i++)
        {
            aktu=0;
            for (int j=1; j<=n; j++)
            {
                aktu+=((tab[j]+i-1)/i)-1;
            }
            wyn=min(wyn, i+aktu);
        }
        printf("Case #%d: %d\n", h, wyn);
    }
    return 0;
}
