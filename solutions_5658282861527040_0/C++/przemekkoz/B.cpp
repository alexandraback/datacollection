//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t;
int a,b,k;

int main()
{
    scanf("%d", &t);
    for(int ti = 1;ti <= t;ti++)
    {
        scanf("%d%d%d", &a, &b, &k);
        k--;a--;b--;

        int wyn = 0;
        for(int i = 0;i <= a;i++)
            for(int j = 0;j <= b;j++)
                if((i&j) <= k)
                    wyn++;
        printf("Case #%d: %d\n", ti, wyn);
    }
    return 0;
}
